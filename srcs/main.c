/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/15 23:10:09 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char cmd[] = "/usr/bin/ls";
	char *argVec[] = {"ls", "-l", "-a", NULL};
	char *envVec[] = {NULL};

	ft_printf("exvece call %s:\n", cmd);
	ft_printf("==============================================================================\n");
	if (execve(cmd, argVec, envVec) == -1)
		perror("execve");
	
	return(0);
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
