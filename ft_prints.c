/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:35:14 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/14 16:33:12 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(t_printf *pr, t_arg *arg)
{
	int				count;
	t_formatted		f;

	ft_t_formatted_init(&f);
	ft_handle_specifier(pr, arg, &f);
	ft_do_print(&f);
	count = ft_count_printed(&f);
	ft_t_formatted_free(&f);
	return (count);
}

void	ft_do_print(t_formatted *f)
{
	if (f->c_null == 1)
		write(1, "\0", 1);
	else
		ft_putstr(f->content);
}

int		ft_count_printed(t_formatted *f)
{
	int	count;

	if (f->c_null == 1)
		count = 1;
	else
		count = ft_strlen(f->content);
	return (count);
}
