/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/16 17:18:00 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	char	*path;

	if (argc == 1)
		return (ft_printf("At least one argument\n"), 0);
	path = envp_finder(envp, "PATH=");
	if (path == NULL)
		return (ft_printf("Env Error\n"), 0);
	cmd = access_check(envp[29], argv[1], R_OK);
	if (cmd == NULL)
		return (ft_printf("Path for command not found\n"), 0);
	ft_printf("execve() call %s:\n", cmd);
	ft_printf("=============================================================\n");
	if (execve(cmd, argv + 1, envp) == -1)
		perror("execve");
	return (0);
}


// PATH=/mnt/nfs/homes/hvercell/bin:
// 		/mnt/nfs/homes/hvercell/bin:
// 		/usr/local/sbin:
// 		/usr/local/bin:
// 		/usr/sbin:
// 		/usr/bin:
// 		/sbin:
// 		/bin:
// 		/usr/games:
// 		/usr/local/games:
// 		/snap/bin
