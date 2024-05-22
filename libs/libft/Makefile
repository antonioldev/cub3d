NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lst*.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ) 
	ar  rc $@ $^

$(OBJ) : 
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(OBJ) $(OBJ_BONUS)
	ar  rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(OBJ_BONUS) : 
	$(CC) $(CFLAGS) -c $(SRC_BONUS)


#rcs
#r option means that if the library already exists, replace the old files within the library with your new files.
#c option means create the library if it did not exist.
#s option sort the library, so that it will be indexed and faster to access the functions in the library.
