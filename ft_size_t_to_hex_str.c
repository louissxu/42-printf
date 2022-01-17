#include <stdio.h>

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
	printf("the returned value is: %zu\n", priv_num_len(num, 16));
	return ("test");
}
