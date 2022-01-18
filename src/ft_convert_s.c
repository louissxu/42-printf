/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:51 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 16:18:25 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_convert_s(char *str)
{
	char	*result;

	result = ft_strdup(str);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
