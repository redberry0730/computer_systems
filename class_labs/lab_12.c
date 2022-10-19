/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PAGE_SIZE 4096

void * mmap_checked(void * addr, size_t length, int prot, int flags, int fd, off_t offset) {
    void * buffer = mmap(addr, length, prot, flags, fd, offset);
    if (buffer == MAP_FAILED) {
        fprintf(stderr, "Failure in mmap: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return buffer;
}

void munmap_checked(void * addr, size_t length) {
    int return_val = munmap_checked(addr, length);
    if (return_Val == -1) {
        fprintf(stderr, "Failure in munmap %s\n", strerror(errno));
    }
}

//for testing mmap!!
int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
    print("FD: %d\n", fd);
    lseek(fd, PAGE_SIZE - 1, SEEK_SET);
    write(fd, "", 1);
    char * buffer = (char *) mmap_checked(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("Buffer %p\n", buffer);
    sprintf(buffer, "This is a test.\n");
    printf(buffer);
    close(fd);
    return EXIT_SUCCESS;
}

//for testing munmap!!
int main() {
    char * buffer = (char *) mmap_checked(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    printf("Buffer %p\n", buffer);
    sprintf(buffer, "This is a test.\n");
    printf(buffer);
    munmap_checked(buffer, PAGE_SIZE);
    return EXIT_SUCCESS;
}


void mem_free(void * ptr);
int is_allocated(Header * header);
int is_free(Header * header);
void set_allocated(Header * header);
void set_free(Header * header);
Header * get_header(void * mem);
int same_page(Header * h1, Header * h2);
int mem_extend(Header * last);
void print_list();
