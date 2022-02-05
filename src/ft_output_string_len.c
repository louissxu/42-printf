#include "../includes/libftprintf.h"

size_t  ft_output_string_len(t_output_string *os)
{
    size_t  len;

    len = 0;
    if (os->left_padding)
        len += ft_strlen(os->left_padding);
    if (os->prefix)
        len += ft_strlen(os->prefix);
    if (os->leading_zeros)
        len += ft_strlen(os->leading_zeros);
    if (os->value_override_bytes_to_print)
        len += os->value_override_bytes_to_print;
    else if (os->value)
        len += ft_strlen(os->value);
    if (os->right_padding)
        len += ft_strlen(os->right_padding);
    return (len);
}