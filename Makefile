NAME		= pipex
BONUSNAME	= pipex_bonus

SRC		= pipex.c
BONUS 	= pipex.c

SRCOBJ	= $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)

CC		= cc
RM		= rm -f
RMDIR	= rmdir
OBJDIR	= obj
SRCDIR	= src
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = includes/libft/libft.a
CAFLAGS = $(CAFILES) $(IFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	if [ ! -d "obj" ]; then mkdir obj; fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libmake $(OBJDIR)/$(SRCOBJ)
	$(CC) $(OBJDIR)/$(SRCOBJ) $(CAFLAGS) -o $(NAME)

bonus: libmake $(OBJDIR)/$(BONUSOBJ)
	$(CC) $(OBJDIR)/$(BONUSOBJ) $(CAFLAGS) -o $(BONUSNAME)

libmake:
	git submodule update --init --recursive --remote
	cd includes/libft && $(MAKE)

clean: 
	$(RM) $(OBJDIR)/$(SRCOBJ)
	$(RM) $(OBJDIR)/$(BONUSOBJ)
	if [ -d "obj" ]; then rmdir obj; fi
	cd includes/libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUSNAME)
	cd includes/libft && $(MAKE) fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
