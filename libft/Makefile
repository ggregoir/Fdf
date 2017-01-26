# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 18:41:23 by jafaghpo          #+#    #+#              #
#    Updated: 2017/01/03 23:00:38 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

RM = 		rm -f


SRC =		ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_strcpy.c \
			ft_strcmp.c ft_memmove.c ft_memccpy.c ft_memset.c ft_strncpy.c \
			ft_tolower.c ft_toupper.c ft_putchar.c ft_putstr.c ft_itoa.c \
			ft_strdup.c ft_strlen.c ft_putnbr.c ft_memcmp.c ft_putendl.c \
			ft_strcat.c ft_strncat.c ft_atoi.c ft_isdigit.c ft_strncmp.c \
			ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strlcat.c ft_strnstr.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memalloc.c \
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_lstnew.c \
			ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_isupper.c ft_islower.c ft_isspace.c ft_strjoin_free.c
OBJ =		$(SRC:.c=.o)

%.o: %.c %.h
	@$(CC) $(CFLAGS) -c $<

$(NAME):	$(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@echo "\033[0;33m[✓] Built Libft C object"
	@echo "\033[0;36m--------------------------------"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32m[✓] Library created"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;35m[x] Removed Libft object files"

fclean:	clean
	@$(RM) $(NAME)
	@echo "\033[0;31m[x] Removed Libft executable"

re:		fclean all

.PHONY:	clean fclean
