NAME = materia

SRCS = main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f


CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re