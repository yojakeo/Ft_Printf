# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 18:00:01 by japarbs           #+#    #+#              #
#    Updated: 2019/11/02 13:14:56 by japarbs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -g -Wall -Werror -Wextra
OBJ = *.o
SRCF = srcs/*.c
LIBSRCF = srcs/libft/*/*.c
INCLUDES = fillit.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(LIBSRCF) $(SRCF)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
  
.PHONY: all clean fclean re
