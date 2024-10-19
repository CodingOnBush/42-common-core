NAME	:=	scalar

CPP		:=	c++
CFLAGS	:=	-std=c++98# -Wall -Wextra -Werror 

INC_DIR	:=	./inc
SRC_DIR	:=	./src
BIN_DIR	:=	./bin

FILES	:=	ScalarConverter
SRC		:=	$(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FILES)))
SRC		+=	main.cpp

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
