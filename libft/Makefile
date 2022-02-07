NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#---------------#
#    SOURCES    #
#---------------#

SRC_CHAR = ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_isspace.c \
		   ft_tolower.c \
		   ft_toupper.c

SRC_CONVERSION = ft_atoi.c \
				 ft_itoa.c

SRC_MEMORY = ft_bzero.c \
			 ft_calloc.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c

SRC_PRINT = ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c

SRC_STR = ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c

SRCS = $(SRC_CHAR) \
	   $(SRC_CONVERSION) \
	   $(SRC_MEMORY) \
	   $(SRC_PRINT) \
	   $(SRC_STR)

OBJS = $(SRCS:.c=.o)

#-------------#
#    BONUS    #
#-------------#

BONUS_SRC_LIST = ft_lstadd_back.c \
				 ft_lstadd_front.c \
				 ft_lstclear.c \
				 ft_lstdelone.c \
				 ft_lstiter.c \
				 ft_lstlast.c \
				 ft_lstmap.c \
				 ft_lstnew.c \
				 ft_lstsize.c

BONUS_SRCS = $(BONUS_SRC_LIST)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#-------------#
#    EXTRA    #
#-------------#

EXTRA_SRC_LIST = ft_isinstr.c

EXTRA_SRCS = $(EXTRA_SRC_LIST)

EXTRA_OBJS = $(EXTRA_SRCS:.c=.o)

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(EXTRA_OBJS): $(EXTRA_SRCS)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# $(NAME): $(OBJS)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

bonus:
	$(CC) $(CFLAGS) -I . -c $(SRCS) $(BONUS_SRCS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
# 	ranlib $(NAME)

extra: $(OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS) $(EXTRA_OBJS)
	ranlib $(NAME)


clean:
	-rm $(OBJS) $(BONUS_OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
