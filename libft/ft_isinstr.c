/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:18:00 by lxu               #+#    #+#             */
/*   Updated: 2022/02/07 19:23:50 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isinstr(int c, char *str)
{
	while (*str)
	{
		if (c == *str)
		{
			return (1);
		}
		str++;
	}
	return (0);
}
