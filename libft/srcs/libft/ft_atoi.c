/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:18:05 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:56:52 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	signe;
	int	i;

	ret = 0;
	signe = 1;
	i = 0;
	while (ft_isspace(nptr[i]) != false)
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= (-1);
		++i;
	}
	while (ft_isdigit(nptr[i]) != 0)
	{
		ret = ret * 10 + (nptr[i] - '0');
		++i;
	}
	return (ret * signe);
}
