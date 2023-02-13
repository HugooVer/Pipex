/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:42:02 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/28 18:57:07 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_countx_(size_t p)
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

void	ft_put_hexx_(size_t x)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (x > 0)
	{
		ft_put_hexx_(x / 16);
		write(1, &str[x % 16], 1);
	}
}

int	ft_printx_(unsigned int x_)
{
	if (x_ == 0)
		return (ft_printdi(0));
	ft_put_hexx_(x_);
	return (ft_digit_countx_(x_));
}
