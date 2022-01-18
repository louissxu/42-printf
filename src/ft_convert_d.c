/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:21:29 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 16:17:25 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_convert_d(int n)
{
	char	*result;

	result = ft_itoa(n);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
