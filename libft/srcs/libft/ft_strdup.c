/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:52:07 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:18:10 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const size_t	len = ft_strlen(s);
	char			*ret;
	size_t			i;

	ret = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		++i;
	}
	return (ret);
}
