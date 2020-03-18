/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:03:06 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/23 15:50:08 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int	get_number_length(const char *string)
{
	unsigned int cnt;

	cnt = 0;
	while (string[cnt] >= '0' && string[cnt] <= '9')
		cnt++;
	return (cnt);
}

unsigned int	get_spaces(const char *string)
{
	unsigned int cnt;

	cnt = 0;
	while (string[cnt] == ' ')
		cnt++;
	return (cnt);
}

unsigned int	get_words(char *string)
{
	unsigned int	cnt;
	unsigned int	last_non_space;

	cnt = 0;
	while (string[cnt] != '\0')
	{
		if (string[cnt] != ' ')
			last_non_space = cnt;
		cnt++;
	}
	string[last_non_space + 1] = '\0'; // Trim trailing spaces.
	return (last_non_space + 1);
}

int				is_power_of_ten(const char *line, unsigned int length)
{
	unsigned int cnt;

	cnt = 0;
	if (line[cnt++] != '1')
		return (0);
	while (cnt < length)
	{
		if (line[cnt] != '0')
			return (0);
		cnt++;
	}
	return (1);
}

int				parse_dict_number(const char *line, unsigned int length,
				unsigned int *order, unsigned int *idx)
{
	if (length == 1)
	{
		*order = 0;
		*idx = line[0] - '0';
		return (0);
	}
	else if (length == 2)
	{
		if (line[0] == '1')
		{
			*order = 1;
			*idx = line[1] - '0';
			return (0);
		}
		else if (line[1] == '0')
		{
			*order = 2;
			*idx = line[0] - '0';
			return (0);
		}
	}
	else if (is_power_of_ten(line, length))
	{
		if (length == 3)
		{
			*order = 2;
			*idx = 10;
			return (0);
		}
		else if ((length <= 37) && ((length % 3) == 1))
		{
			*order = 3;
			*idx = (length / 3) - 1;
			return (0);
		}
	}
	return (1);
}

char			*dupstr(const char *str)
{
	unsigned int	length;
	char			*ret_string;

	length = 0;
	while (str[length] != '\0')
		length++;
	length += 1; // Terminating character.
	ret_string = malloc(length);
	if (NULL == ret_string)
		return (NULL);
	length = 0;
	while (str[length] != '\0')
	{
		ret_string[length] = str[length];
		length++;
	}
	ret_string[length] = '\0';
	return (ret_string);
}
