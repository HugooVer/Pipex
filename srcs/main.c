/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/16 15:22:07 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	char cmd[] = "/usr/bin/";

	if (argc == 1)
		return (ft_printf("at least one argument ! \n"), 0);
	ft_printf("exvece call %s:\n", ft_strjoin(cmd, argv[1]));
	ft_printf("=============================================================\n");
	if (execve(ft_strjoin(cmd, argv[1]), argv + 1, envp) == -1)
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
