/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:06:11 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/28 18:54:50 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_countx(size_t p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (len = 1, len);
	while (p > 0)
	{
		p = p / 16;
		++len;
	}
	return (len);
}

void	ft_put_hexx(size_t x)
{
	char	*str;

	str = "0123456789abcdef";
	if (x > 0)
	{
		ft_put_hexx(x / 16);
		write(1, &str[x % 16], 1);
	}
}

int	ft_printx(unsigned int x)
{
	if (x == 0)
		return (ft_printdi(0));
	ft_put_hexx(x);
	return (ft_digit_countx(x));
}
