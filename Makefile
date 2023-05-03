NAME		= pipex
BONUSNAME	= pipex

OBJDIR	= obj/
MANDODIR	= src/mandatory/
BONUSDIR	= src/bonus/

SRC		=	pipex_utils.c \
			pipex.c

BONUS 	=	pipex_utils_bonus.c \
			pipex_bonus.c

SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))
BONUSOBJ = $(patsubst %.c, $(OBJDIR)%.o, $(BONUS))

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

$(OBJDIR)%.o: $(BONUSDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libmake $(SRCOBJ)
	$(CC) $(SRCOBJ) $(CAFLAGS) -o $(NAME)

bonus: libmake $(BONUSOBJ)
	$(CC) $(BONUSOBJ) $(CAFLAGS) -o $(BONUSNAME)

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
	$(RM) $(BONUSNAME)
	$(MAKE) fclean -C includes/libft

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
