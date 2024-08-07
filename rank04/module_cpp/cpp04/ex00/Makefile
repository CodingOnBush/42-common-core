# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 15:48:49 by momrane           #+#    #+#              #
#    Updated: 2024/06/12 18:34:47 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	exec

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g3

INC_DIR	:=	.
SRC_DIR	:=	.
BIN_DIR	:=	./bin

FILES	:=	main Animal Dog Cat WrongAnimal WrongCat
SRC		:=	$(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FILES)))

OBJ		:=	$(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -I $(INC_DIR) -o $(NAME)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re