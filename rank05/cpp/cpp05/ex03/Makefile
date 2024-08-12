NAME	:=	cleanform

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g3

INC_DIR	:=	.
SRC_DIR	:=	.
BIN_DIR	:=	./bin

FILES	:=	main Bureaucrat AForm \
			ShrubberyCreationForm \
			RobotomyRequestForm \
			PresidentialPardonForm \
			Intern
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
