#include "../includes/libftprintf.h"

int ft_helper_add_precision(t_element *element, t_output_string *os)
{
  size_t  val_len;
  size_t  num_of_zeros;
  char    *zeros_str;

  if (ft_isinstr(element->conversion_type, "diuxX"))
  {
    val_len = ft_strlen(os->value);
    if (val_len < element->precision)
    {
      num_of_zeros = element->precision - val_len;
      zeros_str = malloc(sizeof (*zeros_str) * (num_of_zeros + 1));
      if (!zeros_str)
        return (1);
      ft_memset(zeros_str, '0', num_of_zeros);
      zeros_str[num_of_zeros] = '\0';
      os->leading_zeros = zeros_str;
    }
  }
  else if (element->conversion_type == 's')
  {
    if (ft_strlen(element->content_string) > element->precision)
    {
      element->content_string[element->precision] = '\0';
    }
  }
  return (0);
}