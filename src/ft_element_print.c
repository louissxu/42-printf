#include "../includes/libftprintf.h"
#include "../libft/libft.h"

#include <stdio.h>

size_t ft_element_print(t_element *element)
{
	// printf("\n----printing conversion----\n");
	// printf("flags:               %d\n", element->flags);
	// printf("conversion type:     %c\n", element->conversion_type);
	// printf("precision:           %zu\n", element->precision);
	// printf("minimum_field_width: %zu\n", element->minimum_field_width);
	// printf("content_string:     <%s>\n", element->content_string);
	// printf("----end of this element----\n");

	t_output_string *output_string;
	size_t bytes_printed;

	if (element->conversion_type == 'c')
		return (ft_print_element_c(element));
	else if (element->conversion_type == 'd')
		return (ft_print_element_d(element));
	else if (element->conversion_type == 'i')
		return (ft_print_element_i(element));
	else if (element->conversion_type == 'p')
		return (ft_print_element_p(element));
	else if (element->conversion_type == '%')
		return (ft_print_element_percent(element));
	else if (element->conversion_type == 's')
		return (ft_print_element_s(element));
	else if (element->conversion_type == 'u')
		return (ft_print_element_u(element));
	else if (element->conversion_type == 'x')
	{
		output_string = ft_convert_element_to_output_string(element);
		bytes_printed = ft_output_string_print(output_string);
		ft_output_string_destroy(output_string);
		return (bytes_printed);
	}
	else if (element->conversion_type == 'X')
	{
		output_string = ft_convert_element_to_output_string(element);
		bytes_printed = ft_output_string_print(output_string);
		ft_output_string_destroy(output_string);
		return (bytes_printed);
	}
	else
	{
		ft_putstr_fd(element->content_string, 1);
		return (ft_strlen(element->content_string));
	}
}