/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:38:46 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/13 16:38:46 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
    if (ft_checking(arg->specifier, "diuxX"))
        ft_spec_number(&pr, &arg, &f);
    else if (arg->specifier == 's')
        ft_spec_string(&pr, &arg, &f);
    else if (arg->specifier == 'c')
        ft_spec_char(&pr, &f);
    else if (arg->specifier == 'p')
        ft_spec_pointer(&pr, &f);
    else if (arg->specifier == '%')
        ft_spec_percent(&arg, &f);
}