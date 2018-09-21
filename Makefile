# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 14:08:36 by lmahlang          #+#    #+#              #
#    Updated: 2018/06/01 14:47:23 by lmahlang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEADER = lem_in.h

SRC = ft_links.c get_next_line.c ft_process.c ft_moving_ant.c ft_check.c ft_maping.c main.c

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/

FLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) -L $(LIBFT) -lft

clean:
	@rm -f $(OBJ) *.o
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
