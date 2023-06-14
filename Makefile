# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 12:03:07 by kortolan          #+#    #+#              #
#    Updated: 2023/06/14 18:18:47 by kortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         =     gcc

CFLAGS     =     -Wall -Wextra -Werror

LIBFT    =    libft/libft.a

SRCS     =  test1.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
											

OBJS    = $(SRCS:.c=.o)
            
NAME = minishell

all:    $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all