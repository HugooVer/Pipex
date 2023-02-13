/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:56:55 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:51:17 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	lit_len = ft_strlen(little);
	while (big[i] != '\0' && i < len - (lit_len - 1))
	{
		if (ft_strncmp(big + i, little, lit_len) == 0)
			return ((char *)big + i);
		++i;
	}
	return (NULL);
}
