NAME = phonebook

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = Contact.cpp PhoneBook.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all