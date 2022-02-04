#include "../includes/libftprintf.h"

t_element *ft_element_create_empty()
{
  t_element *element;

  element = malloc(sizeof(*element) * 1);
  if (!element)
  {
    return (NULL);
  }
  element->flags = 0;
  element->conversion_type = '\0';
  element->precision = 0;
  element->minimum_field_width = 0;
  element->content_string = NULL;
  return (element);
}