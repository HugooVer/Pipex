/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:03:14 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/10 17:44:49 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_memchri(char *s, int c)
{
	size_t			i;
	size_t			n;

	if (s == NULL)
		return (-1);
	n = ft_strlen(s);
	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) == c)
		{
			return (i);
		}
		++i;
	}
	return (-1);
}