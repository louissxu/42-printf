#include "../includes/libftprintf.h"

#include <stdio.h>

size_t ft_print_element_u(t_element *element)
{
    size_t  i;
    size_t  chars_printed;
    size_t  chars_to_print;
    size_t  num_len;

    num_len = ft_strlen(element->content_string);
    if (ft_strncmp(element->content_string, "0", 2) == 0 && element->flags & precision_is_set)
        num_len = 0;

    if (num_len > element->precision)
        chars_to_print = num_len;
    else
        chars_to_print = element->precision;

    chars_printed = 0;
    while (chars_printed + chars_to_print < element->minimum_field_width && \
    !(element->flags & negative_field_width))
    {
        if (element->flags & zero_padding && !(element->flags & precision_is_set))
        {
            ft_putchar_fd('0', 1);
            chars_printed++;
        }
        else
        {
            ft_putchar_fd(' ', 1);
            chars_printed++;
        }
    }
    i = 0;
    while (i + num_len < element->precision)
    {
        ft_putchar_fd('0', 1);
        i++;
        chars_printed++;
    }
    if (!(ft_strncmp(element->content_string, "0", 2) == 0 && element->flags & precision_is_set))
    {
        ft_putstr_fd(element->content_string, 1);
        chars_printed += ft_strlen(element->content_string);
    }
    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}