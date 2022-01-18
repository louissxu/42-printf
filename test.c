#include <stdio.h>
#include "includes/libftprintf.h"

int main(void)
{
	printf("FULL TESTING ROUND\n");
	char c = 'a';
	printf("inbuilt   %c\n", c);
	ft_printf("my printf %c\n", c);

	char *s = "this is a string";
	printf("inbuilt   %s\n", s);
	ft_printf("my printf %s\n", s);

	printf("inbuilt   %p\n", s);
	ft_printf("my printf %p\n", s);

	int i = 123;
	printf("inbuilt   %d\n", i);
	ft_printf("my printf %d\n", i);

	int u = -567;
	printf("inbuilt   %u\n", u);
	ft_printf("my printf %u\n", u);

	printf("inbuilt   %x\n", u);
	ft_printf("my printf %x\n", u);

	printf("inbuilt   %X\n", u);
	ft_printf("my printf %X\n", u);

	printf("inbuilt   %%\n");
	ft_printf("my printf %%\n");	
}

