/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:23 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 15:52:10 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>

int		ft_printf(const char *format, ...);

char	*ft_size_t_to_str_base(size_t num, char *radix);
char	*ft_size_t_to_str_hex(size_t num);

char	*ft_convert_c(char c);
char	*ft_convert_d(int n);
char	*ft_convert_i(int n);
char	*ft_convert_p(void *ptr);
char	*ft_convert_percent(void);
char	*ft_convert_s(char *str);
char	*ft_convert_u(int num);
char	*ft_convert_x(int num);
char	*ft_convert_x_upper(int num);

#endif
