#include "../includes/libftprintf.h"

// handle -0

size_t ft_print_element_percent(t_element *element)
{
    size_t  chars_printed;

    chars_printed = 0;
    if (!(element->flags & negative_field_width) && \
    element->minimum_field_width > ft_strlen(element->content_string))
    {
        while (chars_printed + ft_strlen(element->content_string) < element->minimum_field_width)
        {
            if (element->flags & zero_padding)
                ft_putchar_fd('0', 1);
            else
                ft_putchar_fd(' ', 1);
            chars_printed++;
        }
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