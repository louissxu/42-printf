#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	priv_num_len(size_t num, size_t radix)
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
		num = num / radix;
	}
	return result;
}

char	*ft_size_t_to_hex_str(size_t num)
{
	size_t	num_of_chars;
	char	*result;
	size_t	i;
	char	hex_chars[17];

	strlcpy(hex_chars, "0123456789abcdef", 17);

	num_of_chars = priv_num_len(num, 16);
	result = malloc(sizeof (*result) * (num_of_chars + 1));
	if (!result)
	{
		return (NULL);
	}
	if (num == 0)
	{
		result[0] = '0';
	}
	i = num_of_chars;
	while (num)
	{
		result[i - 1] = hex_chars[num % 16];
		num = num / 16;
		i--;
	}
	result[num_of_chars] = '\0';
	return (result);
}
