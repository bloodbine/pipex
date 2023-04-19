NAME	= libft.a

VPATH 	= ft_printf:get_next_line
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC		= ft_isalpha.c			\
		ft_toupper.c			\
		ft_isdigit.c			\
		ft_tolower.c			\
		ft_isalnum.c			\
		ft_strchr.c				\
		ft_isascii.c			\
		ft_strrchr.c			\
		ft_isprint.c			\
		ft_strncmp.c			\
		ft_strlen.c				\
		ft_memset.c				\
		ft_bzero.c				\
		ft_memchr.c				\
		ft_memcpy.c				\
		ft_memcmp.c				\
		ft_memmove.c			\
		ft_strnstr.c			\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		type_characters.c		\
		type_decimal.c			\
		type_hexadecimal.c		\
		ft_printf.c				\
		get_next_line_utils.c 	\
		get_next_line.c

BONUS = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c

SRCOBJ		= $(SRC:.c=.o)
BONUSOBJ	= $(BONUS:.c=.o)

$(NAME): $(SRCOBJ)
	@ar -rcs $@ $^

bonus: $(BONUSOBJ)
	@ar -rcs $(NAME) $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean: 
	@$(RM) $(SRCOBJ) $(BONUSOBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
