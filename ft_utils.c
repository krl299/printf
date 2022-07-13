/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:41 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/13 13:38:41 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_checking(char c, char *s)
{
    int i;

    int = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void    ft_putchar(char c)
{
    if (!c)
        write(1, &c, 1);
}

void    ft_str(char *s)
{
    write(1, s, ft_strlen(s));
}

void    ft_putspace(int len, char c)
{
    if (len <= 0)
        return ;
    while (len > 0)
    {
        ft_putchar(c);
        len--;
    }
}