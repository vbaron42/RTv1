# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 01:11:08 by vbaron            #+#    #+#              #
#    Updated: 2017/01/25 06:10:42 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_bzero.c ft_isascii.c ft_memalloc.c ft_memcmp.c ft_memmove.c \
		   ft_putchar.c ft_putendl_fd.c ft_putstr.c ft_strchr.c ft_strcpy.c \
		   ft_strequ.c ft_strjoin.c ft_strmap.c ft_strncmp.c ft_strnew.c \
		   ft_strsplit.c ft_strtrim.c ft_isalnum.c ft_isdigit.c ft_memccpy.c \
		   ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_putnbr.c ft_putstr_fd.c \
		   ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c ft_strmapi.c \
		   ft_strncpy.c ft_strnstr.c ft_strstr.c ft_tolower.c ft_atoi.c \
		   ft_isalpha.c ft_itoa.c ft_memchr.c ft_abs.c ft_memdel.c ft_pow.c \
		   ft_putendl.c ft_putnbr_fd.c ft_strcat.c ft_strcmp.c ft_strdup.c \
		   ft_striteri.c ft_strlen.c ft_strncat.c ft_strnequ.c ft_strrchr.c \
		   ft_strsub.c ft_toupper.c ft_isprint.c ft_isnegative.c \
		   ft_ispositive.c ft_isnull.c ft_answer.c ft_hello_world.c \
		   ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		   ft_lstnew.c ft_atoi_16.c get_next_line.c ft_strsplit_mo.c \
		   ft_error.c ft_putnbr_d.c ft_putnbr_d_fd.c ft_atoi_d.c ft_error_l.c

CFLAGS = -Werror -Wall -Wextra

OBJ = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(CFLAGS) $(SRC_NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(SRC_NAME)
	@norminette libft.h
