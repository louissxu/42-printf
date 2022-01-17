#include "libft.h"
#include "libftprintf.h"

char	*ft_convert_x_upper(int num)
{
	char	*result;
	size_t	i;

	result = ft_convert_x(num);
	i = 0;
	while (result[i])
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	return (result);
}
