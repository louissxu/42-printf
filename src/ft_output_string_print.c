#include "../includes/libftprintf.h"

#include <stdio.h>

size_t ft_output_string_print(t_output_string *output_string)
{
    size_t  bytes_printed;
    size_t  i;

    // printf("\n\n----------DEBUGGING PRINT----------\n");
    // printf("left padding:  %s\n", output_string->left_padding);
    // printf("prefix:        %s\n", output_string->prefix);
    // printf("leading_zeros: %s\n", output_string->leading_zeros);
    // printf("value:         %s\n", output_string->value);
    // printf("right_padding: %s\n", output_string->right_padding);
    // printf("-----------OUTPUT STRING-----------\n");

    bytes_printed = 0;
    if (output_string->left_padding)
    {
        ft_putstr_fd(output_string->left_padding, 1);
        bytes_printed += ft_strlen(output_string->left_padding);
    }
    if (output_string->prefix)
    {
        ft_putstr_fd(output_string->prefix, 1);
        bytes_printed += ft_strlen(output_string->prefix);
    }
    if (output_string->leading_zeros)
    {
        ft_putstr_fd(output_string->leading_zeros, 1);
        bytes_printed += ft_strlen(output_string->leading_zeros);
    }
    if (output_string->value)
    {
        if (output_string->value_override_bytes_to_print)
        {
            i = 0;
            while (i < output_string->value_override_bytes_to_print)
            {
                ft_putchar_fd((output_string->value)[i], 1);
                bytes_printed++;
                i++;
            }
        }
        else
        {
            ft_putstr_fd(output_string->value, 1);
            bytes_printed += ft_strlen(output_string->value);
        }
    }
    if (output_string->right_padding)
    {
        ft_putstr_fd(output_string->right_padding, 1);
        bytes_printed += ft_strlen(output_string->right_padding);
    }
    return (bytes_printed);
}