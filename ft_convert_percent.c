#include <stdlib.h>

char	*ft_convert_percent(void)
{
	char	*result;
	
	result = malloc(sizeof (*result) * (1 + 1));
	if (!result)
	{
		return (NULL);
	}
	result[0] = '%';
	result[1] = '\0';
	return (result);
}
