#include "../includes/libftprintf.h"

size_t ft_print_element_x_upper(t_element *element)
{
    size_t  i;
    size_t  chars_printed;
    size_t  chars_to_print;

    if (ft_strlen(element->content_string) < element->precision)
        chars_to_print = element->precision;
    else
        chars_to_print = ft_strlen(element->content_string);
    if (element->flags & alternate_form && \
    ft_strncmp(element->content_string, "0", 2))
        chars_to_print += 2;

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
    if (element->flags & alternate_form && \
    ft_strncmp(element->content_string, "0", 2))
    {
        ft_putstr_fd("0X", 1);
        chars_printed += 2;
    }
    i = 0;
    while (i + ft_strlen(element->content_string) < element->precision)
    {
        ft_putchar_fd('0', 1);
        i++;
        chars_printed++;
    }
    ft_putstr_fd(element->content_string, 1);
    chars_printed += ft_strlen(element->content_string);

    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}