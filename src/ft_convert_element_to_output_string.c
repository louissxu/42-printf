#include "../includes/libftprintf.h"

t_output_string *ft_convert_element_to_output_string(t_element *element)
{
    if (element->conversion_type == 'x')
        return (ft_convert_element_x_to_output_string(element));
    if (element->conversion_type == 'X')
        return (ft_convert_element_x_upper_to_output_string(element));
    return (NULL);
}