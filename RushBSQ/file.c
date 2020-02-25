#include "file.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

const unsigned int BUFFER_INITIAL = 64;

typedef struct status_s {
	int fd;
	char *buffer;
	unsigned int buffer_size;
} status_t;

static status_t status;

static int increase_buffer(void)
{
	char *aux = malloc(2 * status.buffer_size);
	if (NULL == aux)
		return 1;

	unsigned int i = 0;
	while (i < status.buffer_size) {
		aux[i] = status.buffer[i];
		i++;
	}
	free(status.buffer);
	status.buffer = aux;
	status.buffer_size *= 2;

	return 0;
}

static int open_file(const char *path)
{
	int fd;
	if (NULL != path) {
		fd = open(path, O_RDONLY);

		if (fd < 0)
			return 1;
	} else {
		fd = 0;
	}

	status.fd = fd;
	status.buffer_size = BUFFER_INITIAL;
	status.buffer = malloc(status.buffer_size);
	if (NULL == status.buffer) {
		if (0 != fd)
			close(fd);
		return 1;
	}

	return 0;
}

static int read_file_line_known_length(char **ptr, unsigned int length)
{
	while (length > status.buffer_size - 1) { // We ran out of buffer.
		if (0 != increase_buffer())
			return 1;
	}

	ssize_t r = read(status.fd, status.buffer, length);
	if (r != length) {
		return 1;
	}

	if (status.buffer[length - 1] != '\n') {
		return 1;

	}
	status.buffer[length - 1] = '\0';
	*ptr = status.buffer;
	return 0;
}

static int read_file_line(char **ptr)
{
	unsigned int cnt = 0;
	ssize_t r = read(status.fd, status.buffer, 1);	// Read the first byte.
	if (r < 0) {
		return 1;
	} else if (r == 0) {
		*ptr = NULL;
		return 0;
	}

	while (status.buffer[cnt++] != '\n') {
		r = read(status.fd, &status.buffer[cnt], 1);
		if (r <= 0)
			return 1;

		if (cnt >= status.buffer_size - 1) { // We ran out of buffer.
			if (0 != increase_buffer())
				return 1;
		}
	}
	status.buffer[cnt - 1] = '\0';
	*ptr = status.buffer;
	return 0;
}

static int read_obstacles(t_map *map, unsigned int row, char *ptr)
{
	unsigned int column;

	column = 0; // Find any obstacles there.
	while (*(ptr + column) != '\0') {
		if (column >= map->width)
			return 1;
		if (*(ptr + column) == map->obstacle_symbol) {
			map_set_obstacle(map, row, column);
		} else if (*(ptr + column) != map->empty_symbol) {
			return 1;
		}

		column++;
	}

	return (column != map->width);
}

static int read_additional_line(t_map *map, unsigned int row)
{
	char *ptr;

	if (0 != read_file_line_known_length(&ptr, map->width + 1) ||
	    (NULL == ptr))
		return 1;

	return read_obstacles(map, row, ptr);
}

static int read_header_and_first_line(t_map *map)
{
	char *ptr;
	unsigned int length;

	// Read the header of the map.
	if (0 != read_file_line(&ptr) || (NULL == ptr))
		return 1;

	length = 0; // Get the length of the str.
	while (*(ptr + length) != '\0')
		length++;

	char obstacle = ptr[length - 2];
	char solution = ptr[length - 1];
	char empty = ptr[length - 3];

	ptr[length - 3] = '\0';
	unsigned int height = atoi(ptr);

	// Read the first line of the map.
	if (0 != read_file_line(&ptr) || (NULL == ptr))
		return 1;

	length = 0; // Get the length of the line.
	while (*(ptr + length) != '\0')
		length++;

	if (0 != map_init(map, height, length, empty, obstacle, solution))
		return 1;

	if (0 != read_obstacles(map, 0, ptr)) {
		map_free(map);
		return 1;
	}

	return 0;
}

static void close_file(void)
{
	if (status.fd != 0)
		close(status.fd);

	if (NULL != status.buffer)
		free(status.buffer);
	status.buffer = NULL;
}

int file_get_map(const char *path, t_map *map)
{
	// HANDLE STDIN HERE!
	if (0 != open_file(path))
		return 1;

	// Get the header of the map.
	if (0 != (read_header_and_first_line(map))) {
		close_file();
		return 1;
	}

	unsigned int row;
	row = 1;

	while(row < map->height) {
		// Get the remainder of the map.
		if (0 != read_additional_line(map, row)) {
			map_free(map);
			close_file();
			return 1;
		}
		row++;
	}

	char *ptr;
	if (0 != read_file_line(&ptr) || ptr != NULL) { // No more lines.
		map_free(map);
		close_file();
		return 1;
	}

	close_file();

	return 0;
}
