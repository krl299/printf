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

int	ft_printf(const char *src, ...)
{
	va_list lstarg;
	int		i;
	char	dst;
	int		conv;

	va_start(lstarg, src);
	i = 0;
	while(src[i])
	{
		if (src[i] == '%')
		{
			conv = va_arg(lstarg, int);
			dst = conv;
			write(1, &dst, ft_strlen(&dst));
			i+= 2;
		}
		else
		{
			write(1, &src[i], 1);
			i++;
		}
	}
	write(1, "\n" ,1);
	va_end(lstarg);
	return (0);
}

int	main()
{
	ft_printf("%d", 'a');
	
	return(0);
}
