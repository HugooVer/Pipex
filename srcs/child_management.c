/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:51:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/11 16:38:45 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_management(t_proc *proc, t_path *path, t_arg *arg)
{
	char	*cmd_path;

	while (proc->child < (proc->cmd_nb))
	{
		proc->pids[proc->child] = fork();
		if (proc->pids[proc->child] == -1)
			return (4);
		if (proc->pids[proc->child] == 0)
		{
			path->pars = ft_split(*(arg->argv + 2 + proc->child), ' ');
			cmd_path = access_check(path->path, *path->pars, R_OK);
			child_position_check(proc);
			close_all_pipes(proc);
			execve(cmd_path, path->pars, arg->envp);
			if (ft_strchr(cmd_path, '/') != NULL)
				dprintf(2, "pipex: %s: No such file or directory\n",
					*path->pars);
			else
				dprintf(2, "%s: command not found\n", *path->pars);
			free_all_data(proc);
			exit (EXIT_FAILURE);
		}
	++proc->child;
	}
	return (0);
}

int	child_position_check(t_proc *proc)
{
	if (proc->child == 0)
		dup2close(STDIN_FILENO, open(proc->infile, O_RDONLY, 0774),
			STDOUT_FILENO, proc->pipes[proc->child][WRITE_END]);
	else if (proc->child == (proc->cmd_nb - 1))
		dup2close(STDOUT_FILENO, open(proc->outfile,
				O_WRONLY | O_CREAT | O_TRUNC, 0774), STDIN_FILENO,
			proc->pipes[proc->child - 1][READ_END]);
	else
		dup2close(STDOUT_FILENO, proc->pipes[proc->child][WRITE_END],
			STDIN_FILENO, proc->pipes[proc->child - 1][READ_END]);
	return (0);
}

int	wait_for_childs(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < (proc->cmd_nb))
	{
		wait(NULL);
		++i;
	}
	free_all_data(proc);
	return (0);
}
