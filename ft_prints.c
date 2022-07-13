/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:35:14 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/13 16:35:14 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_print_arg(t_printf *pr, t_arg *arg)
{
    int             count;
    t_formatted     f;

    ft_t_formatted_init(&f);
    ft_handle_specifier(&pr, &arg, &f);
}