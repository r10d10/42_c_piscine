#include "dict.h"
#include "dict_values.h"
#include "file.h"

#include <stdlib.h>

int dict_create(const char *path)
{
	dict_values_init();

	int f = open_file(path);

	if (f != 0)
		return f;

	char *ptr;
	int r;

	while (0 == (r = read_file_line(&ptr)) && (ptr != NULL)) {
		if ((*ptr != '\0') && (0 != dict_values_parse_line(ptr))) {
			dict_values_destroy();
			close_file();
			return 1;
		}
	}

	close_file();

	if (r != 0) {
		dict_values_destroy();
		return 1;
	}

	dict_values_show();

	return 0;
}

void dict_destroy(void)
{
	dict_values_destroy();
}
