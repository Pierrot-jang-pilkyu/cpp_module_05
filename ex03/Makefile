NAME	=	ex03
CLANG	=	g++
#CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
CFLAGS	=	-Wall -Wextra -Werror

SRCS	= 	./main.cpp \
			./Bureaucrat.cpp \
			./Form.cpp \
			./PresidentialPardonForm.cpp \
			./RobotomyRequestForm.cpp \
			./ShrubberyCreationForm.cpp \
			./Intern.cpp

OBJS	= $(SRCS:.cpp=.o)
RM		= rm -f
TREE	= *_shrubbery

all : $(NAME)

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)
	$(RM) $(TREE)
	@echo "Object files removed."

fclean : clean
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re