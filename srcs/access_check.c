/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:57 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/09 18:06:27 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*access_check(char *path, char *cmd, int amode)
{
	char	**one_path;

	one_path = ft_split(path, ':');
	if (ft_strchr(cmd, '/') != NULL)
		return (cmd);
	while (*one_path != (NULL))
	{
		if (access(ft_strjoin(ft_strjoin(*one_path, "/"), cmd), amode) == 0)
			return (ft_strjoin(ft_strjoin(*one_path, "/"), cmd));
		++one_path;
	}
	return (cmd);
}

// missing free()
int	existing_file(char *file_name, int amode)
{
	return (access(file_name, amode));
}
