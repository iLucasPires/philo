NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -g -o3

DIR_SOURCE = ./src
DIR_HEADERS = ./inc
DIR_OBJ = ./obj

VPATH = $(shell find $(DIR_SOURCE) -type d)
SRCS = $(shell find $(DIR_SOURCE) -type f -name "*.c")
OBJ = $(patsubst $(DIR_SOURCE)/%.c, $(DIR_OBJ)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking..."
	@cc $(CFLAGS) -I $(DIR_HEADERS)  -o $@ $^

$(DIR_OBJ)/%.o: $(DIR_SOURCE)/%.c $(DIR_HEADERS)/philo.h
	$(shell mkdir -p $(dir $@))
	@cc $(CFLAGS) -I $(DIR_HEADERS) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re
