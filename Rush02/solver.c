#include "solver.h"
#include "dict.h"

#include <unistd.h>

int solve(const char *path, char *number __attribute__((unused)))
{
	if (0 != dict_create(path)) {
		write(1, "Dict Error\n", 11);
		return 1;
	}

	// Do the real thing here.

	dict_destroy();

	return 0;
}
