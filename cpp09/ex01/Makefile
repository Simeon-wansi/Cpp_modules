NAME = RPN

SRCS = RPN.cpp main.cpp

CC =  c++

CFLAGS =  -Wall -Wextra -Werror -std=c++98

RM  = rm -f

OBJS =  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


re: fclean all

clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
