#include "../includes/libftprintf.h"

//handle -0field width

size_t  ft_print_element_s(t_element *element)
{
    size_t chars_printed;
    size_t str_len;
    size_t i;

    chars_printed = 0;
    str_len = ft_strlen(element->content_string);
    if (str_len > element->precision && element->flags & precision_is_set)
    {
        str_len = element->precision;
    }
    if (!(element->flags & negative_field_width) && str_len < element->minimum_field_width)
    {
        if (element->flags & zero_padding)
        {
            while (chars_printed < (element->minimum_field_width - str_len))
            {
                ft_putchar_fd('0', 1);
                chars_printed++;
            }
        }
        else
        {
            while (chars_printed < (element->minimum_field_width - str_len))
            {
                ft_putchar_fd(' ', 1);
                chars_printed++;
            }
        }
    }

    if (element->flags & precision_is_set)
    {
        i = 0;
        while (i < element->precision && (element->content_string)[i])
        {
            ft_putchar_fd((element->content_string)[i], 1);
            i++;
            chars_printed++;
        }
    }
    else
    {
        ft_putstr_fd(element->content_string, 1);
        chars_printed += str_len;
    }
    
    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}