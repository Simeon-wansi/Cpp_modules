NAME = btc

CC = c++

CFLAGS =  -W -W -W -std=c++98

SRCS =  main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all , re , clean fclean