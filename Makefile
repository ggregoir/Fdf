NAME	= fdf

SRC		= src/main.c          \
		  src/draw.c          \
		  src/func_point.c    \
		  src/get_next_line.c \
		  src/read.c 		  \

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@echo '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	@echo '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	@echo '\033[31m[ ✔ ] %s\n\033[0m' "Clean Lib"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	@echo '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Lib"

re: fclean all

test: re
	@echo '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all test