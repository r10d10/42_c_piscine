CFLAGS := -Wall -Werror -Wextra

all: rush02

fclean:
	rm -f *.o rush02

clean: fclean

rush02: dict.o rush02.o file.o dict_values.o solver.o parse.o

.PHONY = fclean clean



