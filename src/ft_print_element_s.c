#include "../includes/libftprintf.h"

//handle -0field width

size_t  ft_print_element_s(t_element *element)
{
    size_t chars_printed;
    size_t str_len;

    chars_printed = 0;
    str_len = ft_strlen(element->content_string);
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
    ft_putstr_fd(element->content_string, 1);
    chars_printed += str_len;
    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}