/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:21:02 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/28 18:46:36 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_countdi(int p)
{
	long	pp;
	int		len;

	len = 0;
	pp = p;
	if (p == 0)
		return (len = 1, len);
	if (p < 0)
	{
		++len;
		pp = -(long) p;
	}
	while (pp > 0)
	{
		pp = pp / 10;
		++len;
	}
	return (len);
}

int	ft_printdi(int di)
{
	size_t	c;
	size_t	nbr;

	nbr = di;
	if (di < 0)
	{
		ft_printc('-');
		nbr = -(long) di;
	}
	if (nbr < 10)
	{
		c = nbr % 10 + 48;
		ft_printc(c);
	}
	else
	{
		ft_printdi(nbr / 10);
		ft_printdi(nbr % 10);
	}
	return (ft_digit_countdi(di));
}
