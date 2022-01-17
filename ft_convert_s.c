#include "libft.h"

char	*ft_convert_s(char *str)
{
	char	*result;

	result = ft_strdup(str);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
