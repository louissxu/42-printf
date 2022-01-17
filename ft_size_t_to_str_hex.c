#include "libft.h"
#include "libftprintf.h"

char	*ft_size_t_to_str_hex(size_t num)
{
	return (ft_size_t_to_str_base(num, "0123456789abcdef"));
}
