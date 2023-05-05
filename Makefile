NAME		= pipex

OBJDIR	= obj/
MANDODIR	= src/

SRC		=	pipex_utils.c \
			pipex.c

SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))

CC		= cc
RM		= rm -f
RMDIR	= rmdir
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = includes/libft/libft.a
CAFLAGS = $(CAFILES) $(IFLAGS)

$(OBJDIR)%.o: $(MANDODIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libmake $(SRCOBJ)
	$(CC) $(SRCOBJ) $(CAFLAGS) -o $(NAME)

libmake:
	git submodule update --init --recursive --remote
	$(MAKE) -C includes/libft

clean: 
	$(RM) $(SRCOBJ)
	$(RM) $(BONUSOBJ)
	if [ -d "obj" ]; then rmdir obj; fi
	$(MAKE) clean -C includes/libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C includes/libft

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
