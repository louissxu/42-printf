#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	priv_num_len(size_t num, size_t radix_size)
{
	size_t	result;

	if (num == 0)
	{
		return (1);
	}
	result = 0;
	while (num)
	{
		result++;
		num = num / radix_size;
	}
	return result;
}

char	*ft_size_t_to_str_base(size_t num, char *radix)
{
	size_t	radix_size;
	size_t	num_of_chars;
	char	*result;
	size_t	i;

	radix_size = ft_strlen(radix);
	num_of_chars = priv_num_len(num, radix_size);
	result = malloc(sizeof (*result) * (num_of_chars + 1));
	if (!result)
	{
		return (NULL);
	}
	if (num == 0)
	{
		result[0] = radix[0];
	}
	i = num_of_chars;
	while (num)
	{
		result[i - 1] = radix[num % radix_size];
		num = num / radix_size;
		i--;
	}
	result[num_of_chars] = '\0';
	return (result);
}