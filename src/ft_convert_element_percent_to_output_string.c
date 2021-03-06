/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_element_percent_to_output_string.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:59:45 by lxu               #+#    #+#             */
/*   Updated: 2022/02/06 17:59:46 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_output_string	*ft_convert_element_percent_to_output_string(t_element *element)
{
	t_output_string	*os;

	os = ft_output_string_create_empty();
	if (!os)
		return (NULL);
	os->value = ft_strdup(element->content_string);
	ft_helper_add_padding(element, os);
	return (os);
}
