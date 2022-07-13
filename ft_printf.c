/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:56:27 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/04 10:27:52 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	pr;
	t_arg		arg;
	char		next;

	ft_t_printf_init(&pr, format);
	va_start(pr.args, format);
	while (ft_t_printf_peek(&pr, &next))
	{
		if (next == '%')
		{
			arg = ft_parse_arg(&pr);
			pr.count += ft_print_arg(&pr, &arg);
		}
		else
		{
			write(1, &next, 1);
			pr.count++;
		}
		pr.i++;
	}
	va_end(pr.args);
	return (pr.count);
}

//	check if the next char of format is null and asing pr.next
int	ft_t_printf_peek(t_printf *pr, char *next)
{
	*next = pr->fmt[pr->i];
	if (*next)
		return (1);
	return (0);
}

int	main()
{
	ft_printf("%d", 'a');
	
	return(0);
}
