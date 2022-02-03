#include "../includes/libftprintf.h"

size_t ft_print_element_p(t_element *element)
{
    size_t  chars_to_print;
    size_t  chars_printed;
    size_t  i;

    if (element->precision > ft_strlen(element->content_string) - 2)
        chars_to_print = element->precision + 2;
    else
        chars_to_print = ft_strlen(element->content_string);

    chars_printed = 0;
    while (chars_printed + chars_to_print < element->minimum_field_width && \
    !(element->flags & negative_field_width) && \
    !(element->flags & zero_padding && element->precision == 0))
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    ft_putstr_fd("0x", 1);
    chars_printed += 2;
    chars_to_print -= 2;

    while (chars_printed + chars_to_print < element->minimum_field_width && \
    !(element->flags & negative_field_width) && \
    element->flags & zero_padding && \
    !(element->flags & precision_is_set))
    {
        ft_putchar_fd('0', 1);
        chars_printed++;
    }

    i = 0;
    while (i + ft_strlen(element->content_string) - 2 < element->precision)
    {
        ft_putchar_fd('0', 1);
        i++;
        chars_printed++;
    }

    ft_putstr_fd((element->content_string) + 2, 1);
    chars_printed += ft_strlen((element->content_string) + 2);

    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}