#include "../includes/libftprintf.h"

void ft_element_destroy(t_element *element)
{
    if (element->content_string != NULL)
    {
        free(element->content_string);
        element->content_string = NULL;
    }
    free(element);
}