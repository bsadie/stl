SRCS = main.cpp 

INCL = ft_vector.hpp ft_stack.hpp

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJS=${SRCS:.cpp=.o}

NAME = cont

all: $(NAME) clean

.cpp.o: 
		$(CC) $(FLAGS) -o $@ -c $< 
 

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) 


clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)




