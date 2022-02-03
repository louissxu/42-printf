#include "../includes/libftprintf.h"

// handle -0 +, minfield, precision

#include <stdio.h>

size_t ft_print_element_d(t_element *element)
{
    size_t  chars_printed;
    size_t  num_len;
    size_t  i;
    size_t  chars_to_print;

    num_len = ft_strlen(element->content_string);
    if (element->content_string[0] == '-')
        num_len--;
    if (ft_strncmp(element->content_string, "0", 2) == 0 && element->flags & precision_is_set)
        num_len = 0;

    if (num_len > element->precision)
        chars_to_print = num_len;
    else
        chars_to_print = element->precision;
    if (element->content_string[0] == '-' || element->flags & prepend_sign || element->flags & prepend_negative_or_space)
    {
        chars_to_print++;
    }

    i = 0;
    chars_printed = 0;
    while (chars_to_print + i < element->minimum_field_width && \
    !(element->flags & negative_field_width) && \
    !(element->flags & zero_padding && !(element->flags & precision_is_set)))
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
        i++;
    }
    if (element->content_string[0] == '-')
    {
        ft_putchar_fd('-', 1);
        chars_printed++;
    }
    else if (element->flags & prepend_sign)
    {
        ft_putchar_fd('+', 1);
        chars_printed++;
    }
    else if (element->flags & prepend_negative_or_space)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    i = 0;
    while (num_len + i < element->precision)
    {
        ft_putchar_fd('0', 1);
        i++;
        chars_printed++;
    }
    while (chars_printed + num_len< element->minimum_field_width && \
    !(element->flags & precision_is_set) && \
    element->flags & zero_padding && \
    !(element->flags & negative_field_width))
    {
        ft_putchar_fd('0', 1);
        chars_printed++;
    }
    if (element->content_string[0] == '-')
        ft_putstr_fd((element->content_string) + 1, 1);
    else if (ft_strncmp(element->content_string, "0", 2) == 0 && element->flags & precision_is_set)
        ft_putstr_fd("", 1);
    else
        ft_putstr_fd(element->content_string, 1);
    chars_printed += num_len;

    while (chars_printed < element->minimum_field_width && element->flags & negative_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return(chars_printed);
}