/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:07 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 18:52:10 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_convert_p(void *ptr)
{
	char	*result;
	char	*ptr_str;

	ptr_str = ft_size_t_to_str_hex((size_t)ptr);
	result = malloc(sizeof (*result) * (2 + ft_strlen(ptr_str) + 1));
	if (!result)
	{
		return (NULL);
	}
	ft_strlcpy(result + 2, ptr_str, ft_strlen(ptr_str) + 1);
	free(ptr_str);
	result[0] = '0';
	result[1] = 'x';
	return (result);
}
