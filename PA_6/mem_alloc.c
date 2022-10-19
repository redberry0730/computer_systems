/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include "mem_alloc.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

Header * free_list;

int mem_init() {
    Header * header = (Header *)mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (header == MAP_FAILED) {
        fprintf(stderr, "Failure in mmap: %s\n", strerror(errno));
        return FAILURE;
    }
    free_list = header;
    free_list->size = MAX_SIZE;
    free_list->next = free_list->previous = NULL;
    return SUCCESS;
}

void * mem_alloc(size_t requested_size) {
    if (requested_size > MAX_SIZE) {
        return NULL;
    }
    size_t aligned_size = ((requested_size + (WORD_SIZE - 1)) / WORD_SIZE) * WORD_SIZE;
    if (! free_list) {
        int result = mem_init();
        if (result == FAILURE) {
            return NULL;
        }
    }
    Header * header = free_list;
    while (header->next && (is_allocated(header) || header->size < aligned_size)) {
        header = header->next;
    }
    if (is_allocated(header) || header->size < aligned_size) {
        int result = mem_extend(header);
        if (result == FAILURE) {
            return NULL;
        }
    	header = header->next;
    }
    char * payload_start = (char *) header + sizeof(Header);
    if (header->size > aligned_size + sizeof(Header)) {
        Header * new_header = (Header *) (payload_start + aligned_size);
        new_header->size = header->size - aligned_size - sizeof(Header);
        new_header->next = header->next;
        new_header->previous = header;
    	if (new_header->next) {
    	    new_header->next->previous = new_header;
    	}
        header->next = new_header;
        header->size = aligned_size;
    }
    set_allocated(header);
    return payload_start;
}

void mem_free(void * ptr) {
    Header * header = get_header(ptr);
    set_free(header);
    if (header->next && is_free(header->next) && same_page(header, header->next)) {
    	Header * next_header = header->next;
    	header->size = header->size + next_header->size + sizeof(Header);
    	header->next = next_header->next;
        if (header->next) {
            header->next->previous = header;
        }
    }
    if (header->previous && is_free(header->previous) && same_page(header, header->previous)) {
    	Header * previous_header = header->previous;
    	previous_header->size = previous_header->size + header->size + sizeof(Header);
    	previous_header->next = header->next;
        if (header->next) {
            header->next->previous = previous_header;
        }
    }
    if (! header->previous) {
        free_list = header->next;
    }
    if (header->size == MAX_SIZE) {
        if (header->previous) {
            header->previous->next = header->next;
        }
        if (header->next) {
            header->next->previous = header->previous;
        }
        int result = munmap(header, PAGE_SIZE);
        if (result == FAILURE) {
            fprintf(stderr, "Failure in munmap: %s\n", strerror(errno));
        }
    }
}

int is_allocated(Header * header) {
    return header->size & 1;
}

int is_free(Header * header) {
    return ! is_allocated(header);
}

void set_allocated(Header * header) {
    header->size |= 1;
}

void set_free(Header * header) {
    header->size &= (~((size_t)1));
}

Header * get_header(void * mem) {
    return (Header *) ((char *)mem - sizeof(Header));
}

int same_page(Header * h1, Header * h2) {
    return ((unsigned long)h1 >> PAGE_BITS) == ((unsigned long)h2 >> PAGE_BITS);
}

int mem_extend(Header * last) {
    last->next = (Header *)mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (last->next == MAP_FAILED) {
        fprintf(stderr, "Failure in mmap: %s\n", strerror(errno));
        return FAILURE;
    }
    last->next->size = MAX_SIZE;
    last->next->next = NULL;
    last->next->previous = last;
    return SUCCESS;
}

void print_list() {
    Header * header = free_list;
    while (header) {
        printf("%p -> ", header);
        header = header->next;
    }
    printf("NULL\n");
}

void print_header(void * mem) {
    Header * header = get_header(mem);
    printf("Address: %p\n", header);
    printf("Size: %lu\n", header->size);
    printf("Previous: %p\n", header->previous);
    printf("Next: %p\n", header->next);
}

size_t get_size(Header * header) {
    size_t header_size = (header->size >> 1) << 1;
    return header_size;
}
