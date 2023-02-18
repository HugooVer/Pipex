/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:02:37 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/18 15:50:49 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*envp_finder(char **envp, char *flag)
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, flag, ft_strlen(flag)) == 0)
			return (ft_substr(*envp, ft_strlen(flag), ft_strlen(*envp)));
		++envp;
	}
	return (NULL);
}
