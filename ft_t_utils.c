/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:59:27 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/13 12:59:27 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_t_printf_init(t_printf *pr, const char *fmt)
{
    pr->fmt = fmt;
    pr->i = 0;
    pr->count = 0;
}

void    ft_t_arg_init(t_arg *arg)
{
    arg->flags = 0;
    arg->width = 0;
    arg->has_precision = 0;
    arg->precision = 0;
    arg->length = '\0';
    arg->specifier =  '\0';
}

void    ft_t_formatted_init(t_formatted *f)
{
    f->left_justify = 0;
    f->spaces = 0;
    f->zeroes = 0;
    f->prefix = '\0';
    f->c_null = 0;
    f->sign = '\0';
    f->content = 0;
}

void    ft_t_formatted_free (t_formatted *f)
{
    free(f->content);
}