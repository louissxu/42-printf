#include "../includes/libftprintf.h"
#include "../libft/libft.h"

void ft_print_element(t_element *element)
{
	ft_putstr_fd(element->content_string, 1);
}

void ft_destroy_element(t_element *element)
{
	//pass
}

int ft_printer(t_list *list)
{
	ft_lstiter(list, ft_print_element);
}