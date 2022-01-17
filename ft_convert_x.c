#include "ft_size_t_to_hex_str.c"

char	*ft_convert_x(int num)
{
	unsigned int	u_num;
	char			*result;

	u_num = (unsigned int)num;
	result = ft_size_t_to_hex_str(u_num);
	return (result);
}
