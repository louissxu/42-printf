#include <stdlib.h>

char	*ft_convert_c(char c)
{
	char	*result;

	result = malloc(sizeof (*result) * 2);
	if (!result)
	{
		return (NULL);
	}
	result[0] = c;
	result[1] = '\0';
	return (result);
}