#include "libftprintf.h"

char	*ft_convert_x(int num)
{
	unsigned int	u_num;
	char			*result;

	u_num = (unsigned int)num;
	result = ft_size_t_to_str_hex(u_num);
	return (result);
}
