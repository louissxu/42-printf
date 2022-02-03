#include "../includes/libftprintf.h"

// handle -0field width

size_t ft_print_element_c(t_element *element)
{
    size_t  chars_printed;

    chars_printed = 0;
    if (!(element->flags & negative_field_width) && element->minimum_field_width > 1)
    {
        if (element->flags & zero_padding)
        {
            while (chars_printed < (element->minimum_field_width - 1))
            {
                ft_putchar_fd('0', 1);
                chars_printed++;
            }
        }
        else
        {
            while (chars_printed < (element->minimum_field_width - 1))
            {
                ft_putchar_fd(' ', 1);
                chars_printed++;
            }
        }
    }
    ft_putchar_fd((element->content_string)[0], 1);
    chars_printed++;
    while (chars_printed < element->minimum_field_width)
    {
        ft_putchar_fd(' ', 1);
        chars_printed++;
    }
    return (chars_printed);
}