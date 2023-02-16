/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:57 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/16 16:21:24 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*access_check(char *path, char *cmd, int amode)
{
	char	**one_path;

	one_path = ft_split(path, ':');
	while (one_path != NULL)
	{
		if (access(ft_strjoin(ft_strjoin(*one_path, "/"), cmd), amode) == 0)
			return (ft_strjoin(ft_strjoin(*one_path, "/"), cmd));
		++one_path;
	}
	return ("Error");
}
