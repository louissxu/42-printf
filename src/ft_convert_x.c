/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:24:27 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 16:18:19 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_convert_x(int num)
{
	unsigned int	u_num;

	u_num = (unsigned int)num;
	return (ft_size_t_to_str_hex(u_num));
}
