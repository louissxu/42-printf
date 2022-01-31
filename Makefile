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

SRC_PARSER = ft_parser.c

SRC_PRINTER = ft_printer.c

SRC_PRINTF = ft_printf.c

SRC_DIR = src

SRCS_RAW = $(SRC_CONVERT) \
		   $(SRC_HELPERS) \
			 $(SRC_PARSER) \
			 $(SRC_PRINTER) \
		   $(SRC_PRINTF)

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_RAW))

OBJ_DIR = obj

OBJS_RAW = $(SRCS_RAW:.c=.o)

OBJS = $(patsubst %,$(OBJ_DIR)/%, $(OBJS_RAW))

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

# REF: Meaning of $@ $< $^
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
# REF: Making missing directory if needed
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) extra -C ./libft
	cp libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C ./libft
	-rm $(OBJS)
	-rmdir obj

fclean:
	$(MAKE) fclean -C ./libft
	-rm $(OBJS)
	-rmdir obj
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
