#include "../includes/libftprintf.h"

t_output_string	*ft_convert_element_p_to_output_string(t_element *element)
{
	t_output_string	*os;

	os = ft_output_string_create_empty();
	if (!os)
		return (NULL);
	os->value = ft_strdup(element->content_string);
	os->prefix = ft_strdup("0x");
	ft_helper_add_precision(element, os);
	ft_helper_add_padding(element, os);
	return (os);
}