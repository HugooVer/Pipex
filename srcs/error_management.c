/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:44:44 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/11 14:57:58 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	permission_error(t_proc *proc)
{
	if (proc->fdin == -1)
	{
		dprintf(2, "pipex: %s: IPermission denied\n", proc->infile);
		exit (EXIT_FAILURE);
	}
	else if (proc->fdout == -1)
	{
		dprintf(2, "pipex: %s: OPermission denied\n", proc->outfile);
		exit (EXIT_FAILURE);
	}
	return (0);
}

int	errno_error(t_proc *proc, t_path *path)
{
	dprintf(2, "Ppipex: %s: %s\n", strerror(errno), *path->pars);
	free_all_data(proc);
	exit (EXIT_FAILURE);
}
