CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC_FILES = ft_isascii.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_isalnum.c \
		ft_strlcpy.c \
		ft_isalpha.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c

SRC_DIR = ./

INCLUDE_DIR = ./

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

SRCS_OBJ = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) $< -o $@

clean:
	rm -rf ${SRCS_OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all

