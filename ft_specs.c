/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:10 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/14 16:39:04 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_number(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	nbr;

	nbr = va_arg(pr->args, int);
	if (nbr == 0)
		return ;
	if (ft_checking(arg->specifier, "diu"))
		f->content = ft_itoa_base(nbr, 10, arg->specifier);
	if (ft_checking(arg->specifier, "x"))
		f->content = ft_itoa_base(nbr, 16, arg->specifier);
	if (ft_checking(arg->specifier, "X"))
		f->content = ft_itoa_base(nbr, 16, arg->specifier);
}

void	ft_spec_string(t_printf *pr, t_arg *arg, t_formatted *f)
{
	char	*str;

	arg->precision = 0;
	str = va_arg(pr->args, char *);
	if (!str)
	{
		f->content = ft_strdup("(null)");
		return ;
	}
	f->content = ft_strdup(str);
}

void	ft_spec_char(t_printf *pr, t_formatted *f)
{
	char	c;

	c = va_arg(pr->args, int);
	if (!c)
	{
		f->c_null = 1;
		return ;
	}
	f->content = ft_strdup(&c);
}

void	ft_spec_percent(t_arg *arg, t_formatted *f)
{
	f->content = ft_strdup("%");
	arg->precision = 0;
}

void	ft_spec_pointer(t_printf *pr, t_formatted *f)
{
	long int	ptr;

	ptr = va_arg(pr->args, long int);
	if (!ptr)
		f->content = ft_strdup("0x0");
	else
		f->content = ft_itoa_base_ptr(ptr, 16);
}
