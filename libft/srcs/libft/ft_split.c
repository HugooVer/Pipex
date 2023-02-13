/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:16:14 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/15 18:56:42 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_sep(const char *s, const char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		++len;
	return (len);
}

static char	*ft_sub(const char **s, char c)
{
	while (**s == c)
		++*s;
	return (ft_substr(*s, 0, ft_strlen_sep(*s, c)));
}

static size_t	ft_word_count(const char *s, const char c)
{
	size_t	i;
	size_t	w;
	size_t	len;

	i = 0;
	w = 0;
	len = ft_strlen(s) - 1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			return (w);
		while (s[i] != c && i <= len)
			++i;
		++w;
	}
	return (w);
}

static void	*ft_free(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i] != NULL)
	{
		free(ret[i]);
		++i;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	char	**ret;

	if (s == NULL)
		return (NULL);
	wc = ft_word_count(s, c);
	ret = malloc(sizeof(char *) * (wc + 1));
	if (ret == NULL)
		return (NULL);
	ret[wc] = NULL;
	i = 0;
	while (i < wc)
	{
		ret[i] = ft_sub(&s, c);
		if (ret[i] == NULL)
			return (ft_free(ret));
		s += (ft_strlen(ret[i]));
		++i;
	}
	return (ret);
}
