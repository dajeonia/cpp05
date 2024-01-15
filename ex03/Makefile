NAME = a.out
SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp Form.cpp
INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp Form.hpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
INCS = $(addprefix $(INC_DIR)/, $(INCLUDES))

SRC_DIR = .
OBJ_DIR = objs
INC_DIR = .

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(INC_DIR)

all : $(NAME)

fclean : 
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	rm -rf *_shrubbery

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR) : 
	mkdir $@
