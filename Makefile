FILES := ft_printf.c ft_printfparser.c ft_printfutils.c ft_printfints.c ft_printfchars.c ft_printfptr.c ft_printfint.c ft_printfuint.c \
		 ft_printfhex.c

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
GDB := 

NAME := libftprintf.a
MYLIB := libft.a

TESTNAME := myprintf

.PHONY: all clean fclean re cleantest
all:  $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

cleantest: fclean
	rm -f $(TESTNAME)

$(NAME): $(OBJ) $(LIBFTOBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)
	rm -f ./$(LIBFTPATH)/$(MYLIB)

$(LIBFTOBJ):
	$(MAKE) -C $(LIBFTPATH) bonus


$(TESTNAME): all $(OBJ) main.c
	$(CC) $(GDB) -I. -I$(INCLUDEDIR) main.c -L. -lftprintf -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I. -I$(INCLUDEDIR) $< -o $@

.PHONY: bonus
bonus: all

.PHONY: norm
norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(LIBFTPATH)/*.c
	norminette -R CheckDefine $(INCLUDEDIR)/ $(LIBFTPATH)/libft.h
