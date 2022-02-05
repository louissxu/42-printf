#include "../includes/libftprintf.h"

int ft_helper_add_prefix(t_element *element, t_output_string *os)
{
  if (ft_isinstr(element->conversion_type, "di"))
  {
    if (element->content_string[0] == '-')
    {
      os->prefix = ft_strdup("-");
    }
    else if (element->flags & prepend_sign)
    {
      os->prefix = ft_strdup("+");
    }
    else if (element->flags & prepend_negative_or_space)
    {
      os->prefix = ft_strdup(" ");
    }
  }
  if (element->conversion_type == 'x')
  {
    if (element->flags & alternate_form)
    {
      os->prefix = ft_strdup("0x");
    }
  }
  if (element->conversion_type == 'X')
  {
    if (element->flags & alternate_form)
    {
      os->prefix = ft_strdup("0X");
    }
  }
  return (0);
}