# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 20:17:18 by momrane           #+#    #+#              #
#    Updated: 2024/05/06 09:44:24 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	megaphone

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRC		:=	megaphone.cpp
OBJ		:=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re