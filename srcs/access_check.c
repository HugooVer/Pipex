/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:57 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 15:00:58 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*access_check(char *path, char *cmd, int amode)
{
	char	**one_path;
	char	**one_path_cpy;
	char	*ret;
	size_t	len;

	one_path = ft_split(path, ':');
	one_path_cpy = one_path;
	if (ft_strchr(cmd, '/') != NULL)
		return (ft_free(one_path_cpy), cmd);
	while (*one_path != (NULL))
	{
		len = ft_strlen(cmd);
		ret = ft_strnjoinf1(ft_strnjoin(*one_path, "/", 1), cmd, len);
		if (access(ret, amode) == 0)
			return (ft_free(one_path_cpy), ret);
		++one_path;
		free(ret);
	}
	return (ft_free(one_path_cpy), cmd);
}

// missing free()
int	existing_file(char *file_name, int amode)
{
	return (access(file_name, amode));
}
