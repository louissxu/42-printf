#include "../includes/libftprintf.h"

void ft_destroy_element(t_element *element)
{
	if (element->content_string != NULL)
    {
        free(element->content_string);
        element->content_string = NULL;
    }
    free(element);
}