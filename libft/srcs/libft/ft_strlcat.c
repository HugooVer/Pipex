/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:55:24 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:20:10 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	y = ft_strlen(src);
	if (size <= 0)
		return (y);
	i = ft_strlen(dst);
	if (i > size)
		return (size + y);
	y = 0;
	while (src[y] != '\0' && (i + y < size - 1) != 0)
	{
		dst[i + y] = src[y];
		++y;
	}
	dst[i + y] = '\0';
	return (i + ft_strlen(src));
}
