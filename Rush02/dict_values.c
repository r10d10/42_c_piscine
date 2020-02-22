#include "dict_values.h"
#include "parse.h"

#include <stdlib.h>

// REMOVE THIS
#include <stdio.h>

#define DICT_ROWS 4
#define DICT_COLUMNS 12

static char *dict_values[DICT_ROWS][DICT_COLUMNS];

const char* dict_get(unsigned int order, unsigned int idx)
{
	if ((order >= DICT_ROWS) || (idx >= DICT_COLUMNS))
		return NULL;

	return dict_values[order][idx];
}

void dict_values_init(void)
{
	unsigned int rows, columns;
	rows = 0;

	while (rows < DICT_ROWS) {
		columns = 0;
		while (columns < DICT_COLUMNS) {
			dict_values[rows][columns] = NULL;
			columns++;
		}
		rows++;
	}
}

int dict_values_parse_line(char *line)
{
	unsigned int cursor, order, idx;

	if (0 == (cursor = get_number_length(line)))
		return 1;

	if (0 != parse_dict_number(line, cursor, &order, &idx))
		return 0; // Not a key we want.

	cursor += get_spaces(line + cursor);

	if (line[cursor++] != ':')
		return 1;

	cursor += get_spaces(line + cursor);

	get_words(line + cursor);

	if (NULL != dict_values[order][idx])
		free(dict_values[order][idx]);
	dict_values[order][idx] = dupstr(line + cursor);

	return 0;
}

void dict_values_destroy(void)
{
	unsigned int rows, columns;
	rows = 0;
	while (rows < DICT_ROWS) {
		columns = 0;
		while (columns < DICT_COLUMNS) {
			if (NULL != dict_values[rows][columns]) {
				free(dict_values[rows][columns]);
				dict_values[rows][columns] = NULL;
			}
			columns++;
		}
		rows++;
	}
}

// REMOVE THIS
void dict_values_show(void)
{
	unsigned int rows, columns;
	rows = 0;
	while (rows < DICT_ROWS) {
		columns = 0;
		while (columns < DICT_COLUMNS) {
			printf("%d:%d:%s\n", rows, columns,
			       dict_get(rows, columns));
			columns++;
		}
		rows++;
	}
}
