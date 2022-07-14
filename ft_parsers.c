/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:27:12 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/14 17:08:36 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_parse_arg(t_printf *pr)
{
	t_arg	arg;

	ft_t_arg_init(&arg);
	ft_parse_specifier(pr, &arg);
	return (arg);
}

void	ft_parse_specifier(t_printf *pr, t_arg *arg)
{
	char	specifier;

	specifier = '\0';
	if (ft_checking(pr->fmt[pr->i], "diuxXpcs%"))
	{
		pr->i++;
		specifier = pr->fmt[pr->i];
	}
	arg->specifier = specifier;
}
