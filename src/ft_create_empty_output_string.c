#include "../includes/libftprintf.h"

t_output_string  *ft_create_empty_output_string()
{
    t_output_string *output_string;

    output_string = malloc(sizeof (*output_string) * 1);
    if (!output_string)
    {
        return (NULL);
    }
    output_string->left_padding = NULL;
    output_string->prefix = NULL;
    output_string->leading_zeros = NULL;
    output_string->value = NULL;
    output_string->right_padding = NULL;
    return (output_string);
}