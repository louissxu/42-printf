#include <stdio.h>
#include "includes/libftprintf.h"

int main(void)
{
	//int a = 5;
	size_t inbuilt_return = printf("hello world |%10.3s| |%+010.0i| |%-05c| %i |%#X| |%020p| |%-05%|\n", "hello", 556, 'j', 56, 12345, &"stuff");
	size_t my_return =   ft_printf("hello world |%10.3s| |%+010.0i| |%-05c| %i |%#X| |%020p| |%-05%|\n", "hello", 556, 'j', 56, 12345, &"stuff");
	printf("inbuilt return: %zu    my return: %zu\n", inbuilt_return, my_return);

	inbuilt_return = printf("hello world |%#X|\n", 0);
	my_return =   ft_printf("hello world |%#X|\n", 0);
	printf("inbuilt return: %zu    my return: %zu\n", inbuilt_return, my_return);



	// printf("FULL TESTING ROUND\n");
	// char c = 'a';
	// printf("inbuilt   %c\n", c);
	// ft_printf("my printf %c\n", c);

	// char *s = "this is a string";
	// printf("inbuilt   %s\n", s);
	// ft_printf("my printf %s\n", s);

	// printf("inbuilt   %p\n", s);
	// ft_printf("my printf %p\n", s);

	// int i = 123;
	// printf("inbuilt   %d\n", i);
	// ft_printf("my printf %d\n", i);

	// int u = -567;
	// printf("inbuilt   %u\n", u);
	// ft_printf("my printf %u\n", u);

	// printf("inbuilt   %x\n", u);
	// ft_printf("my printf %x\n", u);

	// printf("inbuilt   %X\n", u);
	// ft_printf("my printf %X\n", u);

	// printf("inbuilt   %%\n");
	// ft_printf("my printf %%\n");	

	// printf("MATCHING TESTS\n");
	// int ret;
	// printf("testing inbuilt: <");
	// ret = printf(" %c %c %c ", '0', 0, '1');
	// printf(">\n");
	// printf("return value was %d\n", ret);
	// printf("testing ft     : <");
	// ret = ft_printf(" %c %c %c ", '0', 0, '1');
	// printf(">\n");
	// printf("return value was %d\n", ret);
}

