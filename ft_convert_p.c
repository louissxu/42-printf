#include "libft.h"

char	*ft_convert_p(void *ptr)
{
	char	*result;
	char	*ptr_str;

	ptr_str = ft_size_t_to_hex_str((size_t)ptr);
	result = malloc(sizeof (*result) * (2 + ft_strlen(ptr_str) + 1));
	if (!result)
	{
		return (NULL);
	}
	ft_strlcpy(result + 2, ptr_str, ft_strlen(ptr_str) + 1);
	result[0] = '0';
	result[1] = 'x';
	return (result);
}
