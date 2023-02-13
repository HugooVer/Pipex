/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:20:57 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/09 19:53:08 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_is_set(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set [i] == s1)
			return (true);
		++i;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	while (ft_is_set(*s1, set) == true)
		++s1;
	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_is_set(s1[len - i - 1], set) == true)
		++i;
	ret = malloc ((len - i + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	return (ft_strlcpy(ret, s1, len - i + 1), ret);
}
