#include "../includes/libftprintf.h"

t_output_string *ft_convert_element_x_upper_to_output_string(t_element *element)
{
    t_output_string *os;
    size_t          len;
    char            *padding_string;

    os = ft_create_empty_output_string();
    if (!os)
        return (NULL);

    if (ft_strncmp(element->content_string, "0", 2) == 0 && element->flags & precision_is_set)
        os->value = ft_strdup("");
    else
        os->value = ft_strdup(element->content_string);
    if (!(os->value))
    {  
        ft_destroy_output_string(os);
        return (NULL);
    }

    if (ft_strlen(os->value) < element->precision)
    {
        len = element->precision - ft_strlen(os->value);
        os->leading_zeros = malloc(sizeof (*(os->leading_zeros)) * (len + 1));
        if (!(os->leading_zeros))
        {
            ft_destroy_output_string(os);
            return (NULL);
        }
        ft_memset(os->leading_zeros, '0', len);
        os->leading_zeros[len] = '\0';
    }

    if (ft_strlen(os->value) > 0 && element->flags & alternate_form && ft_strncmp(element->content_string, "0", 2) != 0)
    {
        os->prefix = ft_strdup("0X");
        if (!(os->prefix))
        {
            ft_destroy_output_string(os);
            return (NULL);
        }
    }

    if (ft_output_string_len(os) < element->minimum_field_width)
    {
        len = element->minimum_field_width - ft_output_string_len(os);
        padding_string = malloc(sizeof (*padding_string) * (len + 1));
        if (!padding_string)
        {
            ft_destroy_output_string(os);
            return (NULL);
        }
        if (element->flags & negative_field_width)
        {
            ft_memset(padding_string, ' ', len);
            padding_string[len] = '\0';
            os->right_padding = padding_string;
        }
        else if (element->flags & zero_padding && !(element->flags & precision_is_set))
        {
            ft_memset(padding_string, '0', len);
            padding_string[len] = '\0';
            os->leading_zeros = padding_string;
        }
        else
        {
            ft_memset(padding_string, ' ', len);
            padding_string[len] = '\0';
            os->left_padding = padding_string;
        }
    }
    return (os);
}