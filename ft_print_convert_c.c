#include <unistd.h>

void ft_print_convert_c(char c)
{
	write(1, &c, 1);
}
