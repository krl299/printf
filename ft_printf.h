/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:16:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/11 13:16:52 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
typedef struct s_printf
{
    const char  *fmt;
    int         i;
    int         count;
    va_list     args;
}   t_printf;
typedef struct s_arg
{
    long int    flags;
    int         width;
    int         has_precision;
    int         precision;
    char        length;
    char        specifier;
}   t_arg;
typedef struct s_formatted
{
    int     left_justify;
    int     spaces;
    int     zeroes;
    char    prefix;
    int     c_null;
    char    sign;
    char    *content;
}   t_formatted;
typedef enum e_flags
{
    LEFT_JUSTIFY = 1 << 0;
    SHOW_SIGN = 1 << 1;
    NO_SIGN = 1 << 2;
    SHOW_PREFIX = 1 << 3;
    PAD_ZERO = 1 << 4;
}   t_flags;

int     ft_printf(const char *format, ...);

#endif