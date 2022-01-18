/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:46 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 15:23:47 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_percent(void)
{
	char	*result;

	result = malloc(sizeof (*result) * (1 + 1));
	if (!result)
	{
		return (NULL);
	}
	result[0] = '%';
	result[1] = '\0';
	return (result);
}
