/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:16:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/14 16:29:21 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_printf
{
	const char	*fmt;
	int			i;
	int			count;
	va_list		args;
}	t_printf;
typedef struct s_arg
{
	long int	flags;
	int			width;
	int			has_precision;
	int			precision;
	char		length;
	char		specifier;
}	t_arg;
typedef struct s_formatted
{
	int		left_justify;
	int		spaces;
	int		zeroes;
	char	prefix;
	int		c_null;
	char	sign;
	char	*content;
}	t_formatted;
typedef enum e_flags
{
	LEFT_JUSTIFY = 1 << 0,
	SHOW_SIGN = 1 << 1,
	NO_SIGN = 1 << 2,
	SHOW_PREFIX = 1 << 3,
	PAD_ZERO = 1 << 4,
}	t_flags;
//  File ft_printf.c
int		ft_printf(const char *format, ...);
int		ft_t_printf_peek(t_printf *pr, char *next);

// File ft_t_utils.c
void	ft_t_printf_init(t_printf *pr, const char *fmt);
void	ft_t_arg_init(t_arg *arg);
void	ft_t_formatted_init(t_formatted *f);
void	ft_t_formatted_free(t_formatted *f);

//  File ft_parsers.c
t_arg	ft_parse_arg(t_printf *pr);
void	ft_parse_flags(t_printf *pr, t_arg *arg);
void	ft_parse_width(t_printf *pr, t_arg *arg);
void	ft_parse_precision(t_printf *pr, t_arg *arg);
void	ft_parse_specifier(t_printf *pr, t_arg *arg);

//  File ft_prints.c
int		ft_print_arg(t_printf *pr, t_arg *arg);
void	ft_do_print(t_formatted *f);
int		ft_count_printed(t_formatted *f);

//  File ft_handles.c
void	ft_handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f);
void	ft_handle_zeroes(t_arg *arg, t_formatted *f);
void	ft_handle_flags(t_arg *arg, t_formatted *f);
void	ft_handle_width(t_arg *arg, t_formatted *f);

//  File ft_specs.c
void	ft_spec_number(t_printf *pr, t_arg *arg, t_formatted *f);
void	ft_spec_string(t_printf *pr, t_arg *arg, t_formatted *f);
void	ft_spec_char(t_printf *pr, t_formatted *f);
void	ft_spec_percent(t_arg *arg, t_formatted *f);
void	ft_spec_pointer(t_printf *pr, t_formatted *f);

//  File ft_utils.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putspace(int i, char c);
int	ft_checking(char c, char *s);

//  File ft_utils_2.c
int		ft_len_ptr(long int nb);
int		ft_len_base(int nb, int i);
char	*ft_itoa_base_ptr(long int value, int base);
char	*ft_itoa_base(int value, int base, char spec);

//  Files needed of libft
size_t	ft_strlen(const char *s);
// try to use ft_strdup before that
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
#endif
