# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:33:12 by maelgini          #+#    #+#              #
#    Updated: 2025/01/27 18:15:28 by maelgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC     = ft_printf.c ft_printf_utils.c ft_print_hex.c ft_printf_func.c
OBJS    = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	 ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
