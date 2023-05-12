/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:02:37 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/12 14:34:49 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_sub(char const *s, unsigned int start, size_t len, t_path *path)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	path->path = malloc(len * sizeof(char) + 1);
	if (path->path == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (i < len)
	{
		path->path[i] = s[i];
		++i;
	}
	path->path[i] = '\0';
	return (path->path);
}

char	*envp_finder(char **envp, char *flag, t_path *path)
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, flag, ft_strlen(flag)) == 0)
			return (ft_sub(*envp, ft_strlen(flag), ft_strlen(*envp), path));
		++envp;
	}
	return (NULL);
}
