NAME		= phonebook
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX			= c++
SRC			= $(wildcard *.cpp)
RM			= rm -rf
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ Compiled!$(DEFAULT)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)🧨 Objects are destroyed$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🧨 Executable is destroyed$(DEFAULT)"


re : clean all

.PHONY : all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m