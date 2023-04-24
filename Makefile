NAME		= pipex
# BONUSNAME	= pipex_bonus

OBJDIR	= obj/
SRCDIR	= src/

SRC		=	pipex_utils.c \
			pipex.c

# BONUS 	=	pipex.c

SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))
# BONUSOBJ = $(patsubst %.c, $(OBJDIR)%.o, $(BONUS))

CC		= cc
RM		= rm -f
RMDIR	= rmdir
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = includes/libft/libft.a
CAFLAGS = $(CAFILES) $(IFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libmake $(SRCOBJ)
	$(CC) $(SRCOBJ) $(CAFLAGS) -o $(NAME)

# bonus: libmake $(BONUSOBJ)
# 	$(CC) $(BONUSOBJ) $(CAFLAGS) -o $(BONUSNAME)

libmake:
	git submodule update --init --recursive --remote
	cd includes/libft && $(MAKE)

clean: 
	$(RM) $(SRCOBJ)
	# $(RM) $(BONUSOBJ)
	if [ -d "obj" ]; then rmdir obj; fi
	cd includes/libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	# $(RM) $(BONUSNAME)
	cd includes/libft && $(MAKE) fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
