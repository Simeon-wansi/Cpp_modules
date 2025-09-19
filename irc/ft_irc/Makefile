NAME = ircserv

CXX =  c++

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp Server.cpp Client.cpp Channel.cpp CommandDispatcher.cpp Commands.cpp utils.cpp

OBJS =  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# # # Simple Makefile for testing

# # CXX = c++
# # CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# # # Just build the test directly
# # test: test_integration.cpp Server.cpp Client.cpp Channel.cpp
# # 	$(CXX) $(CXXFLAGS) -o test_integration test_integration.cpp Server.cpp Client.cpp Channel.cpp

# # # Run the test
# # run: test
# # 	./test_integration

# # # Clean up
# # clean:
# # 	rm -f test_integration

# # .PHONY: test run clean

# SRC_FILES = test_integration.cpp  Server.cpp Client.cpp\
# 			Commands.cpp \
# 			utils.cpp \
# 			Channel.cpp \
# 			nick.cpp	\
# 			join.cpp	\
# 			mode.cpp	\
# 			topic.cpp
# OBJ = $(SRC:.cpp=.o)
# CC = c++
# RM = rm -rf
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# SRC = $(SRC_FILES)

# NAME = ircserv

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean $(NAME)

# .PHONY: all clean fclean re