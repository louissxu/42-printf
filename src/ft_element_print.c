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

	output_string = ft_convert_element_to_output_string(element);
	if (!output_string)
	{
		return (0);
	}
	bytes_printed = ft_output_string_print(output_string);
	ft_output_string_destroy(output_string);
	return (bytes_printed);
}