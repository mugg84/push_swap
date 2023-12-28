# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 15:50:22 by mmughedd          #+#    #+#              #
#    Updated: 2023/12/26 13:00:28 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

UTILS = utils.c check_args.c stack_fn.c solve_small.c

SRC_PATH = src/

UTILS_PATH = utils/

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

OBJS = $(SRCS:.c=.o)

INCS = -I ./includes/

NAME = push_swap

LIBFT = './libft'

LIBFT_LIB = './libft/libft.a'

CC = cc

FLAGS = -Wextra -Werror -Wall -g

RM = rm -f

all: $(NAME)

makelibft:
	make -C $(LIBFT)

$(NAME): makelibft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFT) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFT) && make fclean

re: fclean all

.PHONY: all clean fclean re makelibft