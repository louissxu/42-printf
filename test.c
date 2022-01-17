#include "ft_convert_x.c"
#include "ft_convert_x_upper.c"
#include "ft_convert_p.c"
#include "ft_convert_u.c"
#include "ft_size_t_to_str_base.c"
#include <stdio.h>
#include "libft.h"
#include "ft_printf.c"

int main(void)
{
	int a = 125123;
	printf("testing x %x\n", a);
	printf("testing my x %s\n", ft_convert_x(a));
	printf("testing X %X\n", a);
	printf("testing my X %s\n", ft_convert_x_upper(a));

	char *b = "123";
	printf("testing p %p\n", b);
	printf("testing my p %s\n", ft_convert_p(b));

	int c = 123;
	printf("testing d %d\n", c);
	printf("testing i %i\n", c); 

	int d = -567;
	printf("testing u %u\n", d);
	printf("testing my u %s\n", ft_convert_u(d));


	printf("testing ft_size_to_str_base %s\n", ft_size_t_to_str_base(100, "0123456789abcdef"));

	ft_printf("hello world");
}

