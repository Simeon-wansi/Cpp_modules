NAME =  iter 

CXX =  c++

CXXFLAGS =  -Wall -Wextra -Werror #-std=++98

SRCS =  main.cpp

OBJS = $(SRCS:.cpp=.o)


RM = rm -f

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


%.o: %.cpp
	$(CXX)  $(CXXFLAGS) -c $< -o $@


all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
