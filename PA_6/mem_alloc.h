/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>

#define PAGE_SIZE 4096
#define PAGE_BITS 12
#define WORD_SIZE 8
#define MAX_SIZE (PAGE_SIZE - sizeof(Header))
#define SUCCESS 0
#define FAILURE -1
#define TRUE 1
#define FALSE 0

typedef struct Header {
    size_t size;
    struct Header * next;
    struct Header * previous;
} Header;

void * mem_alloc(size_t requested_size);
void print_header(void * mem);
void print_list();
int mem_init();
void mem_free(void * ptr);
int is_allocated(Header * header);
int is_free(Header * header);
void set_allocated(Header * header);
void set_free(Header * header);
Header * get_header(void * mem);
int same_page(Header * h1, Header * h2);
int mem_extend(Header * last);
size_t get_size(Header * header);
