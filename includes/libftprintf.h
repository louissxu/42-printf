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
#define LIBFTPRINTF_H

#include <stddef.h>
#include <stdarg.h>
#include "../libft/libft.h"

int ft_printf(const char *format, ...);

char *ft_size_t_to_str_base(size_t num, char *radix);
char *ft_size_t_to_str_hex(size_t num);

char *ft_convert_c(char c);
char *ft_convert_d(int n);
char *ft_convert_i(int n);
char *ft_convert_p(void *ptr);
char *ft_convert_percent(void);
char *ft_convert_s(char *str);
char *ft_convert_u(int num);
char *ft_convert_x(int num);
char *ft_convert_x_upper(int num);

typedef enum e_flags
{
	zero_padding = 1,
	negative_field_width = 2,
	alternate_form = 4,
	prepend_negative_or_space = 8,
	prepend_sign = 16,
	precision_is_set = 32,
} t_flags;

typedef struct s_element
{
	t_flags flags;
	char conversion_type;
	size_t precision;
	size_t minimum_field_width;
	char *content_string;
} t_element;

typedef struct s_output_string
{
	char *left_padding;
	char *prefix;
	char *leading_zeros;
	char *value;
	char *right_padding;
} t_output_string;

t_element *ft_parser(const char *format, size_t *i, va_list arg_list);
size_t ft_print_element(t_element *element);
void ft_destroy_element(t_element *element);

size_t ft_print_element_c(t_element *element);
size_t ft_print_element_d(t_element *element);
size_t ft_print_element_i(t_element *element);
size_t ft_print_element_p(t_element *element);
size_t ft_print_element_percent(t_element *element);
size_t ft_print_element_s(t_element *element);
size_t ft_print_element_u(t_element *element);
size_t ft_print_element_x(t_element *element);
size_t ft_print_element_x_upper(t_element *element);

t_output_string *ft_output_string_create_empty();
void ft_output_string_destroy(t_output_string *os);
size_t ft_output_string_len(t_output_string *os);
size_t ft_output_string_print(t_output_string *os);
t_output_string *ft_convert_element_to_output_string(t_element *element);
t_output_string *ft_convert_element_x_to_output_string(t_element *element);
t_output_string *ft_convert_element_x_upper_to_output_string(t_element *element);

#endif
