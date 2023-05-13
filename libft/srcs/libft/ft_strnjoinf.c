/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:10:04 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 12:12:48 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinf(char *s1, char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = n;
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(ret, s1, len1 + 1);
	if (s2 != NULL)
		ft_strlcpy(ret + len1, s2, len2 + 1);
	return (free(s1), free(s2), ret);
}
