/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:24:11 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 15:26:23 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*ft_convert_u(int num)
{
	char			*result;
	unsigned int	u_num;

	u_num = (unsigned int)num;
	result = ft_size_t_to_str_base(u_num, "0123456789");
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
