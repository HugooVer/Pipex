/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:51:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 16:50:21 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_management(t_proc *proc, t_path *path, t_arg *arg, t_here *here)
{
	char	*cmd_path;

	cmd_path = NULL;
	while (proc->child < (proc->cmd_nb) - here->here)
	{
		proc->pids[proc->child] = fork();
		if (proc->pids[proc->child] == -1)
			return (4);
		if (proc->pids[proc->child] == 0)
		{
			path->pars = ft_split(*(arg->argv + 2 + proc->child
						+ here->here), ' ');
			cmd_path = access_check(path->path, *path->pars, R_OK);
			child_position_check(proc, here);
			close_all_pipes(proc);
			permission_error(proc, here, path);
			execve(cmd_path, path->pars, arg->envp);
			errno_error(proc, path, here);
			exit (EXIT_FAILURE);
		}
	++proc->child;
	}
	return (0);
}

int	child_position_check(t_proc *proc, t_here *here)
{
	if (proc->child == 0)
	{
		proc->fdin = open(proc->infile, O_RDONLY, 0774);
		dup2close(STDIN_FILENO, proc->fdin,
			STDOUT_FILENO, proc->pipes[proc->child][WRITE_END]);
	}
	else if (proc->child == (proc->cmd_nb - 1 - here->here))
	{
		proc->fdout = open(proc->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0774);
		dup2close(STDOUT_FILENO, proc->fdout,
			STDIN_FILENO, proc->pipes[proc->child - 1][READ_END]);
	}
	else
		dup2close(STDOUT_FILENO, proc->pipes[proc->child][WRITE_END],
			STDIN_FILENO, proc->pipes[proc->child - 1][READ_END]);
	return (0);
}

int	wait_for_childs(t_proc *proc, t_here *here, t_path *path)
{
	int	i;

	i = 0;
	while (i < (proc->cmd_nb))
	{
		wait(NULL);
		++i;
	}
	free_all_data(proc, here, path);
	return (0);
}
