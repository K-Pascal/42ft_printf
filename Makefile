FILES := ft_printf.c ft_printfparser.c ft_printf_utils.c ft_printf_chars.c ft_printf_ptr.c ft_printfintd.c

SRCDIR := src
INCLUDEDIR := include
BUILDDIR := build
SRC := $(addprefix $(SRCDIR)/,$(FILES))
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))

LIBFTPATH := libft
LIBFTFILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
		   ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		   ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		   ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		   ft_lstiter.c ft_lstmap.c


LIBFTSRC := $(addprefix $(LIBFTPATH)/,$(LIBFTFILES))

LIBFTOBJ := $(LIBFTSRC:.c=.o)


CC := cc
CFLAGS := -Wall -Wextra -Werror
GDB := -g

NAME := libftprintf.a

TESTNAME := myprintf

.PHONY: all clean fclean re cleantest
all:  $(NAME)

clean:
	rm -f $(OBJ) $(LIBFTOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

cleantest: fclean
	rm -f $(TESTNAME)

$(NAME): $(OBJ) $(LIBFTOBJ)

$(TESTNAME): $(NAME) $(OBJ) main.c
	$(CC) $(GDB) -I $(INCLUDEDIR) main.c -L. -lftprintf -o $(TESTNAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I . -I $(INCLUDEDIR) $< -o $@
	ar rcs $(NAME) $@

$(LIBFTPATH)/%.o: $(LIBFTPATH)/%.c
	$(CC) $(CFLAGS) $(GDB) -c -I $(LIBFTPATH) $< -o $@
	ar rcs $(NAME) $@

.PHONY: bonus
bonus: all

.PHONY: norm
norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(LIBFTSRC)
	norminette -R CheckDefine $(LIBFTPATH)/libft.h $(INCLUDEDIR)/*.h
