/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:29:29 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/28 18:45:42 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_countu(unsigned int p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (len = 1, len);
	while (p > 0)
	{
		p = p / 10;
		++len;
	}
	return (len);
}

int	ft_printu(unsigned int u)
{
	size_t	c;
	int		uu;

	uu = u;
	if (u < 10)
	{
		c = u % 10 + 48;
		ft_printc(c);
	}
	else
	{
		ft_printu(u / 10);
		ft_printu(u % 10);
	}
	return (ft_digit_countu(uu));
}
