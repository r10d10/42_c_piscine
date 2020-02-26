# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollero- <aollero@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 18:14:40 by aollero-          #+#    #+#              #
#    Updated: 2020/02/26 18:27:38 by aollero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Werror -Wextra -O3
NAME := rushbsq
SRCS := rushbsq.c file.c file1.c map.c 
OBJS := $(patsubst %.c, %.o, $(SRCS))

$(NAME): $(OBJS)

all: $(NAME)

fclean:
	rm -f *.o $(NAME)

clean: fclean

re: fclean all

.PHONY = fclean clean