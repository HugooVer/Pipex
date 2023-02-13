/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:05:06 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:03:33 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*ret;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ret = ft_strdup(s);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = f(i, ret[i]);
		++i;
	}
	return (ret);
}
