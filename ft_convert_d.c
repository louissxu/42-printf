#include "libft.h"
#include "libftprintf.h"

char	*ft_convert_d(int n)
{
	char	*result;
	
	result = ft_itoa(n);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
