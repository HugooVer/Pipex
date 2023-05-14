/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:49:40 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/14 17:51:34 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arg_to_t_arg(int argc, char **argv, char **envp, t_arg *arg)
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	return (0);
}

int	data_preset(t_proc *proc, t_path *path, t_arg *arg, t_here *here)
{
	proc->cmd_nb = arg->argc - 3;
	proc->pids = malloc((proc->cmd_nb + 1) * sizeof(pid_t));
	if (proc->pids == NULL)
		return (5);
	proc->pipes = malloc(proc->cmd_nb * sizeof(int *));
	if (proc->pipes == NULL)
		return (6);
	pipe_creation(proc);
	envp_finder(arg->envp, "PATH=", path);
	if (path->path == NULL)
		return (write(2, "Env Error\n", 10), 2);
	pipe_initialisation(proc);
	proc->outfile = (arg->argv[arg->argc - 1]);
	if (here->here == 0)
		proc->infile = (arg->argv[1]);
	else
		proc->infile = ft_strdup(here->file_name);
	proc->child = 0;
	return (0);
}

static void	*ft_free(char **ret)
{
	size_t	i;

	i = 0;
	if (ret == NULL)
		return (NULL);
	while (ret[i] != NULL)
	{
		free(ret[i]);
		++i;
	}
	free(ret);
	return (NULL);
}

int	free_all_data(t_proc *proc, t_here *here, t_path *path)
{
	int	i;

	i = 0;
	free(proc->pids);
	while (i <= proc->cmd_nb - 1)
	{
		free(proc->pipes[i]);
		++i;
	}
	free(proc->pipes);
	free(path->path);
	if (path->pars != NULL)
		ft_free(path->pars);
	if (here->here == 1)
		free(proc->infile);
	if (here->here == 1)
	{
		unlink(here->file_name);
		free(here->file_name);
	}
	return (0);
}
