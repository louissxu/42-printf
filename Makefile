NAME	= libftprintf.a
CC		= gcc
CFLAGS  = -Wall -Wextra -Werror

#---------------#
#    SOURCES    #
#---------------#

SRC_PRINTF = ft_printf.c

SRC_PARSER = ft_parser.c \
			 ft_parse_flag.c \
			 ft_parse_minimum_field_width.c \
			 ft_parse_precision.c \
			 ft_parse_conversion_type.c

SRC_ELEMENT = ft_element_create_empty.c \
			  ft_element_print.c \
			  ft_element_destroy.c \
			  ft_element_print.c

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
			  ft_size_t_to_str_hex.c \
			  ft_helper_add_precision.c \
			  ft_helper_add_padding.c \
			  ft_helper_add_prefix.c

SRC_OUTPUT_STRING = ft_output_string_create_empty.c \
					ft_output_string_destroy.c \
					ft_output_string_len.c \
					ft_output_string_print.c

SRC_ELEMENT_TO_OUTPUT_STRING = ft_convert_element_to_output_string.c \
							   ft_convert_element_c_to_output_string.c \
							   ft_convert_element_d_to_output_string.c \
							   ft_convert_element_i_to_output_string.c \
							   ft_convert_element_p_to_output_string.c \
							   ft_convert_element_percent_to_output_string.c \
							   ft_convert_element_s_to_output_string.c \
							   ft_convert_element_u_to_output_string.c \
							   ft_convert_element_x_to_output_string.c \
							   ft_convert_element_x_upper_to_output_string.c



SRC_DIR = src

SRCS_RAW = $(SRC_PRINTF) \
		   $(SRC_PARSER) \
		   $(SRC_ELEMENT) \
		   $(SRC_CONVERT) \
		   $(SRC_HELPERS) \
		   $(SRC_OUTPUT_STRING) \
		   $(SRC_ELEMENT_TO_OUTPUT_STRING)
		   
SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_RAW))

OBJ_DIR = obj

OBJS_RAW = $(SRCS_RAW:.c=.o)

OBJS = $(patsubst %,$(OBJ_DIR)/%, $(OBJS_RAW))

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

bonus: all

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

.PHONY: all bonus clean fclean re
