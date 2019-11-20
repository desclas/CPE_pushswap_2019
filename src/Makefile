##
## EPITECH PROJECT, 2019
## CPool_finalstumper_2019
## File description:
## Makefile
##

DEBUG =
ifeq ($(DEBUG),yes)
CFLAGS	=	-Iinclude -W -Wall -Wextra -Werror -g3
else
CFLAGS	=	-Iinclude -W -Wall -Wextra -Werror
endif

NAME	=	push_swap

SRC	=	main.c					\
		my_add_at_end_list.c	\
		algo.c					\
		operation_a.c			\
		operation_b.c			\
		operation_c.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re rush3
