#ifndef AM_H
#define AM_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

typedef struct {
	double *data;
	size_t *shape;
	size_t ndim;
	size_t total_elements;
} Array;

typedef struct {
	int in_use;
	double data[10];
} MemBlock;

typedef struct {
	long long int key;
	long long int value;
	int distance;
	int is_filled;
}ii;

size_t am_strlen(const char *str);
void am_print(const char *str);
Array am_read_npy(const char *filename);
int am_isdigit(unsigned char str);
int am_isspace(unsigned char str);
char *am_strstr(const char *haystack, const char *needle);
size_t am_strtol(const char *str, char **endptr);
void am_write_stderr(const char *msg);
ssize_t am_read(int fd, void *buf, size_t size);
MemBlock *am_malloc();
void am_free(MemBlock *block);
uint32_t hash32(int key);
uint64_t hash64(uint64_t key);
void insert_ii(ii *array, long long int key, long long int value, long long int box_size);
void insert_ii_unordered(ii *array, long long int key, long long int value, long long int box_size);
int search_ii(ii *array, int key, int box_size);
int delete_ii(ii *array, int key, int box_size);

#endif

uint32_t hash32(int key) {
	uint32_t h = (uint32_t)key;

	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return (h);
}

uint64_t hash64(uint64_t x) {
	x ^= x >> 30;
	x *= 0xbf58476d1ce4e5b9ULL;
	x ^= x >> 27;
	x *= 0x94d049bb133111ebULL;
	x ^= x >> 31;
	return x;
}


void insert_ii(ii *array, long long int key, long long int value, long long int box_size) {
	uint64_t hashed_index;
	int distance;
	uint64_t new_index;

	hashed_index = hash64(key) % box_size;
	if (!array[hashed_index].is_filled) {
		array[hashed_index].key = key;
		array[hashed_index].value = value;
		array[hashed_index].distance = 0;
		array[hashed_index].is_filled = 1;
	}
	else {
		distance = 1;
		new_index = (hashed_index + distance) % box_size;
		while (array[new_index].is_filled) {
			if (array[new_index].distance < distance) {
				int tmp_key = array[new_index].key;
				int tmp_value = array[new_index].value;
				int tmp_distance = array[new_index].distance;
				array[new_index].key = key;
				array[new_index].value = value;
				array[new_index].distance = distance;
				key = tmp_key;
				value = tmp_value;
				distance = tmp_distance;
			}
			new_index = (new_index + 1) % box_size;
			distance++;
		}
		array[new_index].key = key;
		array[new_index].value = value;
		array[new_index].distance = distance;
		array[new_index].is_filled = 1;
	}
}

//allow collision for unordered_set
//ABC193 C
void insert_ii_unordered(ii *array, long long int key, long long int value, long long int box_size) {
	uint64_t hashed_index;
	int distance;
	uint64_t new_index;

	hashed_index = hash64(key) % box_size;
	if (!array[hashed_index].is_filled) {
		array[hashed_index].key = key;
		array[hashed_index].value = value;
		array[hashed_index].distance = 0;
		array[hashed_index].is_filled = 1;
	}
	else {
		distance = 1;
		new_index = (hashed_index + distance) % box_size;
		while (array[new_index].is_filled) {
			if (array[new_index].key == key)
				return;
			else {
				if (array[new_index].distance < distance) {
					int tmp_key = array[new_index].key;
					int tmp_value = array[new_index].value;
					int tmp_distance = array[new_index].distance;
					array[new_index].key = key;
					array[new_index].value = value;
					array[new_index].distance = distance;
					key = tmp_key;
					value = tmp_value;
					distance = tmp_distance;
				}
				new_index = (new_index + 1) % box_size;
				distance++;
			}
		}
		array[new_index].key = key;
		array[new_index].value = value;
		array[new_index].distance = distance;
		array[new_index].is_filled = 1;
	}
}

int search_ii(ii *array, int key, int box_size) {
	uint32_t hashed_index;

	hashed_index = hash32(key) % box_size;
	while (array[hashed_index].is_filled) {
		if (array[hashed_index].key == key)
			return array[hashed_index].value;
		hashed_index++;
	}
	//not sufficient error handliing
	return (-1);
}

int delete_ii(ii *array, int key, int box_size) {
	uint32_t hashed_index;

	hashed_index = hash32(key) % box_size;
	while (array[hashed_index].is_filled) {
		if (array[hashed_index].key == key) {
			array[hashed_index].is_filled = 0;
			return (array[hashed_index].value);
		}
		hashed_index++;
	}
	return (-1);
}

int am_isdigit(unsigned char str) {
	if (47 < str && str < 58)
		return (1);
	return (0);
}

int am_isspace(unsigned char str) {
	if (str == ' ' || str == '	')
		return (1);
	return (0);
}

#define POOL_SIZE 100

MemBlock memory_pool[POOL_SIZE];

MemBlock *am_malloc() {
	for (int i = 0; i < POOL_SIZE; i++) {
		if (!memory_pool[i].in_use) {
			memory_pool[i].in_use = 1;
			return (&memory_pool[i]);
		}
	}
	return (NULL);
}

void am_free(MemBlock *block) {
	block->in_use = 0;
}
#include <unistd.h>

void am_print(const char *output) {
	size_t len = am_strlen(output);
	size_t total_written = 0;
	ssize_t written;

	while (total_written < len) {
		written = write(1, output + total_written, len - total_written);
		if (written == -1) {
			am_write_stderr("write failed");
			return;
		}
		total_written += written;
	}
}
#include <unistd.h>

ssize_t am_read(int fd, void *buf, size_t size) {
	size_t total_read = 0;
	ssize_t bytes_read;

	while (total_read < size) {
		bytes_read = read(fd, (char *)buf + total_read, size - total_read);
		if (bytes_read < 0) {
			am_print("Error: read failed\n");
			return (-1);
		}
		if (bytes_read == 0) {
			am_print("Waring: unexpected EOF\n");
			break;
		}
		total_read += bytes_read;
	}
	return (total_read);
}
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int read_header(int fd) {
	char magic[6];

	am_read(fd, magic, 6);
	if (magic[0] != '\x93' || magic[1] != 'N' || magic[2] != 'U' || magic[3] != 'M' || magic[4] != 'P' || magic[5] != 'Y') {
		am_print("Not a valid .npy format\n");
		close(fd);
		exit(1);
		return (-1);
	}
	return (0);
}

int read_version(int fd) {
	unsigned char version[2];

	am_read(fd, version, 2);
	return (0);
}

void get_shape(char *header, size_t **shape, size_t *ndim) {
	const char *shape_start = am_strstr(header, "'shape': (");

	if (!shape_start) {
		am_print("Error: 'shape' not found\n");
		return;
	}
	shape_start += 10;
	*ndim = 1;
	for (const char *p = shape_start; *p && *p != ')'; p++) {
		if (*p == ',')
			(*ndim)++;
	}
	*shape = (size_t *)malloc(*ndim * sizeof(size_t));
	if (!*shape) {
		am_print("Memory allocation failed\n");
		exit(1);
	}
	for (size_t i = 0; i < *ndim; i++) {
		(*shape)[i] = am_strtol(shape_start, (char **)&shape_start);
		while (*shape_start && (*shape_start == ',' || *shape_start == ' '))
			shape_start++;
	}
}

char *read_shape(int fd, size_t **shape, size_t *ndim) {
	unsigned short header_len;

	am_read(fd, &header_len, 2);
	char *header = (char *)malloc(header_len + 1);
	if (!header) {
		am_print("Memory allocation failed\n");
		exit(1);
	}
	am_read(fd, header, header_len);
	header[header_len] = '\0';
	get_shape(header, shape, ndim);
	/*
	am_print("Shape: ");
	for (size_t i = 0; i < *ndim; i++) {
		printf("%zu", (*shape)[i]);
		if (i < *ndim - 1)
			printf(", ");
	}
	printf("\n");
	*/
	free(header);
	return (NULL);
}

Array am_read_npy(const char *filename) {
	int fd = open(filename, O_RDONLY);
	size_t *shape = NULL;
	size_t ndim = 0;
	size_t total_elements = 1;

	if (fd == -1) {
		am_print("Error opening file");
		exit(1);
	}
	read_header(fd);
	read_version(fd);
	read_shape(fd, &shape, &ndim);
	for (size_t i = 0; i < ndim; i++)
		total_elements *= shape[i];
	double *data = (double *)malloc(total_elements * sizeof(double));
	am_read(fd, data, total_elements * sizeof(double));
	close(fd);
	Array result = {
		.data = data,
		.shape = shape,
		.ndim = ndim,
		.total_elements = total_elements
	};
	return (result);
}
#include <stddef.h>
#include <stdint.h> 


size_t am_strlen(const char *str) {
        size_t len = 0;

        while (*str++)
                len++;
        return (len);
}

char *am_strstr(const char *haystack, const char *needle) {
	if (!*needle)
		return ((char *)haystack);
	while (*haystack) {
		const char *h = haystack;
		const char *n = needle;
		while (*h && *n && (*h == *n)) {
			h++;
			n++;
		}
		if (!*n)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

#include <stddef.h>

void convert_to_num(const char *p, size_t *result, char **endptr) {
	int digit = 0;

	while (am_isdigit((unsigned char)*p)) {
		digit = *p - '0';
		if (*result > (SIZE_MAX - digit) / 10) {
			*result = SIZE_MAX;
			if (endptr)
				*endptr = (char *)p;
			return;
		}
		*result = *result * 10 + digit;
		p++;
	}
	if (endptr)
		*endptr = (char *)p;
}

size_t am_strtol(const char *str, char **endptr) {
	const char *p = str;
	size_t result = 0;
	int sign = 1;

	while (am_isspace((unsigned char)*p))
		p++;
	if (*p == '-') {
		sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	convert_to_num(p, &result, endptr);
	return (sign * result);
}
#include <unistd.h>
#include <errno.h>

ssize_t am_write(int fd, const char *buffer, size_t size) {
	size_t total_written = 0;
	ssize_t written;

	while (total_written < size) {
		written = write(fd, buffer + total_written, size - total_written);
		if (written < 0)
			return (-1);
		total_written += written;
	}
	return (total_written);
}

void am_write_stderr(const char *msg) {
        ssize_t written = write(2, msg, am_strlen(msg));

        if (written == -1) {
                const char *err = "Error writinf to stderr\n";
                am_write(2, err, am_strlen(err));
        }
        else if ((size_t)written < am_strlen(msg)) {
                const char *warn = "Partial write to stderr\n";
                am_write(2, warn, am_strlen(warn));
        }
}
#include <stdio.h>

#define SIZE 100001

ii array[SIZE];

int main() {
	long long int n, ans = 0;
	scanf("%lld", &n);
	for (long long int i = 2; i <= SIZE; i++) {
		long long int x = i * i;
		while(x <= n) {
			insert_ii_unordered(array, x, 1, SIZE);
			x *= i;
			/*
			int count = 0;
			for (int i = 0; i < 100001; i++)
				if (array[i].is_filled == 1)
					count++;
			printf("%d\n", count);
			*/
		}
	}
	for (long long int i = 0; i < SIZE; i++) {
		if (array[i].value == 1)
			ans++;
	}
	printf("%lld\n", n - ans);
}
