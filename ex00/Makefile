NAME = megaphone
SRC = megaphone.cpp
CCC = c++
CCCFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)

all = $(NAME)

$(NAME): $(OBJS)
	$(CCC) $(CCCFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp 
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	 rm -f $(NAME)
re: fclean all
