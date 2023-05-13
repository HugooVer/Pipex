/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:44:44 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 16:55:16 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	permission_error(t_proc *proc, t_here *here, t_path *path)
{
	char	*out;

	if (proc->child == 0 && proc->fdin == -1)
	{
		out = ft_strnjoinf1(ft_strnjoinf1("pipex: ", proc->infile,
					ft_strlen(proc->infile)), ": Permission denied\n", 20);
		ft_printf("%s", out);
		free(out);
		free_all_data(proc, here, path);
		exit (EXIT_FAILURE);
	}
	else if (proc->child == (proc->cmd_nb - 1 - here->here)
		&& proc->fdout == -1)
	{
		out = ft_strnjoinf1(ft_strnjoinf1("pipex: ", proc->outfile,
					ft_strlen(proc->outfile)), ": Permission denied\n", 20);
		ft_printf("%s", out);
		free(out);
		free_all_data(proc, here, path);
		exit (EXIT_FAILURE);
	}
	return (0);
}

int	errno_error(t_proc *proc, t_path *path, t_here *here)
{
	char	*out;

	out = ft_strnjoinf1(ft_strnjoinf1(ft_strnjoinf1(ft_strnjoin("pipex: ",
						strerror(errno), ft_strlen(strerror(errno))), ": ", 2),
				*path->pars, ft_strlen(*path->pars)), "\n", 1);
	ft_printf("%s", out);
	free(out);
	free_all_data(proc, here, path);
	exit (EXIT_FAILURE);
}
