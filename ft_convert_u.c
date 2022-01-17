#include "libft.h"
#include "libftprintf.h"

char	*ft_convert_u(int num)
{
	char			*result;
	unsigned int	u_num;

	u_num = (unsigned int)num;
	result = ft_size_t_to_str_base(u_num, "0123456789");
	
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
