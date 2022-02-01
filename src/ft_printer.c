#include "../includes/libftprintf.h"
#include "../libft/libft.h"

void ft_print_element(void *element)
{
	ft_putstr_fd(((t_element*)element)->content_string, 1)
	ft_putstr_fd("\n", 1);
}

void ft_destroy_element(t_element *element)
{
	element->minimum_field_width++;
	//pass
}

int ft_printer(t_list *list)
{
	ft_lstiter(list, ft_print_element);
	return (0);
}