/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:51:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/08 16:57:05 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_management(t_proc *proc, t_path *path, t_arg *arg)
{
	while (proc->child < (proc->cmd_nb))
	{
		proc->pids[proc->child] = fork();
		if (proc->pids[proc->child] == -1)
			return (4);
		if (proc->pids[proc->child] == 0)
		{
			keeping_used_pipes(proc);
			path->pars = ft_split(*(arg->argv + 2 + proc->child), ' ');
			proc->cmd = access_check(path->path, *path->pars, R_OK);
			if (proc->cmd == NULL)
				return (printf("Path for command not found == %i\n",
						proc->child), 5);
			child_position_check(proc);
			if (execve(proc->cmd, path->pars, arg->envp) == -1)
				perror("execve");
		}
	++proc->child;
	}
	return (0);
}

int	child_position_check(t_proc *proc)
{
	if (proc->child == 0)
		dup2colose(STDIN_FILENO, open(proc->infile, O_RDONLY, 0774),
			STDOUT_FILENO, proc->pipes[proc->child][WRITE_END]);
	else if (proc->child == (proc->cmd_nb - 1))
		dup2colose(STDOUT_FILENO, open(proc->outfile,
				O_WRONLY | O_CREAT | O_TRUNC, 0774), STDIN_FILENO,
			proc->pipes[proc->child - 1][READ_END]);
	else
		dup2colose(STDOUT_FILENO, proc->pipes[proc->child][WRITE_END],
			STDIN_FILENO, proc->pipes[proc->child - 1][READ_END]);
	return (0);
}

int	wait_fo_childs(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < (proc->cmd_nb))
	{
		wait(NULL);
		++i;
	}
	return (0);
}
