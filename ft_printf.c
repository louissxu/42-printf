#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ap_i;
	int		i;

	va_start(ap, format);
	ap_i = 0;
	i = 0;
	while (format[i])
	{
		write(1, &format[i], 1);
		i++;
	}
	return (0);
}

