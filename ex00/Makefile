NAME = a.out

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	-rm -rf $(OBJS)

fclean: clean
	-rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re