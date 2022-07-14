/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:10:16 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/14 16:39:51 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(long int nb)
{
	int					i;
	long unsigned int	unb;

	unb = nb;
	i = 0;
	if (!unb)
		return (0);
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i);
}

int	ft_len_base(int nb, int i)
{
	int				j;
	unsigned int	unb;

	unb = nb;
	j = 0;
	if (!unb)
		return (0);
	while (unb > 0)
	{
		unb = unb / i;
		j++;
	}
	return (j);
}

char	*ft_itoa_base_ptr(long int value, int base)
{
	int					size;
	long unsigned int	nbr;
	char				*result;
	char				*ref_base;

	nbr = value;
	ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	size = ft_len_ptr(nbr);
	size += 2;
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (nbr > 0)
	{
		result[size--] = ref_base[(nbr % base)];
		nbr = nbr / base;
	}
	return (result);
}

char	*ft_itoa_base(int value, int base, char spec)
{
	int				size;
	unsigned int	nbr;
	char			*result;
	char			*ref_base;

	if (value < 0 && (spec == 'd' || spec == 'i'))
		value *= -1;
	nbr = value;
	if (spec == 'X')
		ref_base = "0123456789ABCDEF";
	else
		ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	size = ft_len_base(nbr, base);
	result = (char *)malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (0);
	result[size--] = '\0';
	if (value < 0)
		result[0] = '-';
	else
		result[0] = '0';
	while (nbr > 0)
	{
		result[size--] = ref_base[(nbr % base)];
		nbr = nbr / base;
	}
	return (result);
}
