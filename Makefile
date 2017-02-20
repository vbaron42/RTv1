# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 19:52:58 by vbaron            #+#    #+#              #
#    Updated: 2017/02/20 21:54:50 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rtv1
FLAGS	=	-lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c tools.c read.c img.c event.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@cd libft/ && $(MAKE)
	@$(CC) $(FLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	@cd libft/ && $(MAKE) fclean
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create rtv1"

%.o: %.c
	@$(cc) $(FLAGS) -c $^ -o $@

norminette:
	@norminette $(SRC)
	@norminette rtv1.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
