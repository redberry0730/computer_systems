/*
 * This program decodes a text file into a secret message.
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define ZERO 0

void usage() {
	printf("Please enter a command line argument.\n");
	exit(EXIT_FAILURE);
}

void file_error(char * file_name) {
	fprintf(stderr, "Could not open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

char decode(int count, int set_bits[]) {
	char bit_value;
	for (int i = ZERO; i < count; i++) {
		bit_value |= 1 << set_bits[i];
	}
	printf("%c", bit_value);
	bit_value = ZERO;
	return ZERO;
}

void read_and_decode_file(char * file_name) {
	FILE * read_size = fopen(file_name, "r");
	if (! read_size) {
		file_error(file_name);
	}
	int x, array_size = ZERO;
	while ((x = fgetc(read_size)) != EOF) {
		array_size++;
	}
	fclose(read_size);
	FILE * read_data = fopen(file_name, "r");
	int array_all_values[array_size];
	int z, i = ZERO;
	while ((z = fgetc(read_data)) != EOF) {
		array_all_values[i] = z - '0';
		i++;
	}
	fclose(read_data);
	int j = ZERO;
	int true_array_size = sizeof(array_all_values) / sizeof(array_all_values[ZERO]);
	while (j < true_array_size) {
		int count = array_all_values[j];
		int sub_array[count];
		int s = j + 1;
		for (int k = ZERO; k < count; k++) {
			sub_array[k] = array_all_values[s];
			s++;
		}
		decode(count, sub_array);
		j += count + 1;
		int true_sub_array_size = sizeof(sub_array) / sizeof(sub_array[ZERO]);
		for (int p = ZERO; p < true_sub_array_size; p++) {
			sub_array[p] = ZERO;
		}
	}
}

int main(int argc, char * argv[]) {
	if (argc < 2) {
		usage();
	}
	read_and_decode_file(argv[1]);
	return EXIT_SUCCESS;
}
