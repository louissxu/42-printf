#include "libft.h"

void ft_print_convert_s(char *str)
{
	write(1, str, ft_strlen(str));
}
