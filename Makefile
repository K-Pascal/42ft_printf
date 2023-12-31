FILES := ft_printf.c \
		 ft_printfparser.c \
		 ft_printfutils.c \
		 ft_printfints.c \
		 ft_printfchars.c \
		 ft_printfptr.c \
		 ft_printfint.c \
		 ft_printfuint.c \
		 ft_printfhex.c

SRCDIR := src
INCLUDEDIR := include
BUILDDIR := build
SRC := $(addprefix $(SRCDIR)/,$(FILES))
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))


CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
GDB ?= -g3
export GDB

NAME := libftprintf.a
LIBFT_DIR := libft
LIBFT := libft.a

.PHONY: all clean fclean re
all:  $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) bonus
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I . -I $(INCLUDEDIR) $< -o $@

myprintf: main.c $(NAME)
	$(CC) $(GDB) -I . -I $(INCLUDEDIR) main.c -L . -lftprintf -o $@

cleanprintf:
	rm -f myprintf

.PHONY: bonus norm
bonus: all

.PHONY:
norm:
	$(MAKE) -C $(LIBFT_DIR) norm
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCLUDEDIR)/
