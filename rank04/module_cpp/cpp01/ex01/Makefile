# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 17:05:08 by momrane           #+#    #+#              #
#    Updated: 2024/05/16 17:22:04 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	horde

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98

INC_DIR	:=	.
SRC_DIR	:=	.
BIN_DIR	:=	./bin

SRC		:=	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Zombie.cpp \
			$(SRC_DIR)/zombieHorde.cpp \

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
