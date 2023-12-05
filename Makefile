FILES := ft_printf.c ft_printfparser.c ft_printfutils.c ft_printfints.c ft_printfchars.c ft_printfptr.c ft_printfint.c ft_printfuint.c \
		 ft_printfhex.c

SRCDIR := src
INCLUDEDIR := include
BUILDDIR := build
SRC := $(addprefix $(SRCDIR)/,$(FILES))
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))

LIBFTPATH := libft

CC := cc
CFLAGS := -Wall -Wextra -Werror
GDB := -g

NAME := libftprintf.a
MYLIB := libft.a

TESTNAME := myprintf

.PHONY: all clean fclean re cleantest
all: $(LIBFTPATH)/$(MYLIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

cleantest: fclean
	rm -f $(TESTNAME)

$(LIBFTPATH)/$(MYLIB):
	$(MAKE) -C $(LIBFTPATH) bonus

$(NAME): $(OBJ)

$(TESTNAME): all $(OBJ) main.c
	$(CC) $(GDB) -I. -I$(INCLUDEDIR) main.c -L. -lftprintf -Llibft/ -lft -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I. -I$(INCLUDEDIR) $< -o $@

.PHONY: bonus
bonus: all

.PHONY: norm
norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(LIBFTPATH)/*.c
	norminette -R CheckDefine $(INCLUDEDIR)/ $(LIBFTPATH)/libft.h
