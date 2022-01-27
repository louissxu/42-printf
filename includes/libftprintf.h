/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:23 by lxu               #+#    #+#             */
/*   Updated: 2022/01/18 16:20:37 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include "../libft/libft.h"

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

typedef enum e_flags
{
	zero_padding = 1,
	negative_field_width = 2,
	alternate_form = 4,
	prepend_negative_or_space = 8,
	prepend_sign = 16,
} t_flags;

typedef	struct	s_element
{
	void		*input_arg;
	t_flags	flags;
	char		conversion_type;
	int			precision;
	int			minimum_field_width;
	char		*content_string;
}	t_element;

#endif
