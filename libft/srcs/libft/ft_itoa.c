/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:14:04 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 18:49:09 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(size_t n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + ft_digit_count(n / 10));
}

static size_t	ft_abs(int n)
{
	if (n < 0)
		return ((size_t) - (long)n);
	else
		return ((size_t)n);
}

char	*ft_itoa(int n)
{
	int				dc;
	unsigned short	digit;
	unsigned short	signe;
	char			*ret;
	size_t			absn;

	signe = (n < 0);
	absn = ft_abs(n);
	dc = ft_digit_count(absn);
	ret = malloc((dc + signe + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (signe == 1)
		ret[0] = '-';
	ret[dc + signe] = '\0';
	digit = 0;
	--dc;
	while (absn > 9)
	{
		digit = absn % 10;
		ret[dc + signe] = digit + 48;
		--dc;
		absn = absn / 10;
	}
	return (digit = absn % 10, ret[dc + signe] = digit + 48, ret);
}
