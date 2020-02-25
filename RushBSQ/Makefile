CFLAGS := -Wall -Werror -Wextra -O3 -g
BIN := rushbsq
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

all: $(BIN)

fclean:
	rm -f *.o $(BIN)

clean: fclean

$(BIN): $(OBJS)

.PHONY = fclean clean



