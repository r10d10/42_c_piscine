/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:14:11 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/23 22:00:28 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

const unsigned int BUFFER_STEP = 64;

typedef struct status_s {
	int fd;
	char *buffer;
	unsigned int buffer_size;
}				status_t;

static status_t status;

static int		increase_buffer(void)
{
	char				*aux;
	unsigned int		i;

	aux = malloc(status.buffer_size + BUFFER_STEP);
	if (NULL == aux)
		return (1);
	i = 0;
	while (i < status.buffer_size)
	{
		aux[i] = status.buffer[i];
		i++;
	}
	free(status.buffer);
	status.buffer = aux;
	status.buffer_size += BUFFER_STEP;
	return (0);
}

int		open_file(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	status.fd = fd;
	status.buffer_size = BUFFER_STEP;
	status.buffer = malloc(status.buffer_size);
	if (NULL == status.buffer)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int		read_file_line(char **ptr)
{
	unsigned int cnt;

	cnt = 0;
	ssize_t r;
	r = read(status.fd, status.buffer, 1);	// Read the first byte.
	if (r < 0)
	{
		return (1);
	}
	else if (r == 0)
	{
		*ptr = NULL;
		return (0);
	}
	while (status.buffer[cnt++] != '\n')
	{
		r = read(status.fd, &status.buffer[cnt], 1);
		if (r <= 0)
			return (1);
		if (cnt >= BUFFER_STEP - 1)
		{ // We ran out of buffer.
			if (0 != increase_buffer())
				return (1);
		}
	}
	status.buffer[cnt - 1] = '\0';
	*ptr = status.buffer;
	return (0);
}

void	close_file(void)
{
	close(status.fd);
	free(status.buffer);
}
