/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/18 20:52:03 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	char	*path;
	char	**pars;
	int		pids[argc - 1];
	int		pipes[argc - 2][2];
	int		i;
	int		j;

	if (argc == 1)
		return (ft_printf("At least one argument\n"), 1);

	path = envp_finder(envp, "PATH=");

	if (path == NULL)
		return (ft_printf("Env Error\n"), 2);

	i = 0;
	while (i < (argc - 2))
	{
		if (pipe(pipes[i]) == -1)
			return (3);
		++i;
	}
	i = 0;
	while (i < (argc - 1))
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (4);
		if (pids[i] == 0)
		{
			j = 0;
			while (j < (argc - 2))
			{
				if (j != i)
					close(pipes[j][0]);
				else if (j != i + 1)
					close(pipes[j][1]);
				++j;
			}

			pars = ft_split(*(argv + 1 + i), ' ');
			cmd = access_check(path, *pars, R_OK);

			if (cmd == NULL)
				return (ft_printf("Path for command not found\n"), 5);

			if (execve(cmd, pars, envp) == -1)
				perror("execve");
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return (0);
		}
		++i;
	}
	j = 0;
	while (j < (argc - 2))
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		++j;
	}
	i = 0;
	while (i < (argc - 1))
	{
		wait(NULL);
		++i;
	}
	return (0);
}
