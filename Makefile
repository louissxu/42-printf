NAME	= libftprintf.a
CC		= gcc
CFLAGS  = -Wall -Wextra -Werror

#---------------#
#    SOURCES    #
#---------------#

SRC_CONVERT = ft_convert_c.c \
			  ft_convert_d.c \
			  ft_convert_i.c \
			  ft_convert_p.c \
			  ft_convert_percent.c \
			  ft_convert_s.c \
			  ft_convert_u.c \
			  ft_convert_x.c \
			  ft_convert_x_upper.c

SRC_HELPERS = ft_size_t_to_str_base.c \
			  ft_size_t_to_str_hex.c

SRC_PRINTF = ft_printf.c

SRCS = $(SRC_CONVERT) \
	   $(SRC_HELPERS) \
	   $(SRC_PRINTF)

OBJS = $(SRCS:.c=.o)

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
