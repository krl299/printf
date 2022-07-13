/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:10:16 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/13 18:10:16 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_len_ptr(long int nb)
{
    int                 i;
    long unsigned int   unb;

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

int     ft_len_base(int nb, int i)
{
    int             j;
    unsigned int    unb;

    unb = nb;
    j = 0;
    if (!unb)
        return (0=);
    while (unb > 0)
    {
        unb = unb / i;
        j++;
    }
    return (j);
}

char    *ft_itoa_base_ptr(long int value, int base)
{
    int size;
    long unsigned int   nbr;
    char                *result;
    char                *ref_base;
}

char    *ft_itoa_base(int value, int base, char spec)
{

}