/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/04 23:50:16 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**pars;

	t_proc	proc;


	int		i;
	int		j;
	
	if (argument_number(argc) == 1)
		return(1);


	proc.cmd_nb = argc - 3;

	proc.pids = malloc((proc.cmd_nb + 1)* sizeof(pid_t));
	if (proc.pids == NULL)
		return(5);
	proc.pipes = malloc(proc.cmd_nb * sizeof(int *));
	if (proc.pipes == NULL)
		return(6);
	i = 0;
	while(i <= proc.cmd_nb - 1)
	{
		proc.pipes[i] = malloc(2 * sizeof(int));
		if (proc.pipes[i] == NULL)
			return(7);
		++i;
	}

	path = envp_finder(envp, "PATH=");
	if (path == NULL)
		return (ft_printf("Env Error\n"), 2);

	i = 0;
	while (i < (proc.cmd_nb) )
	{
		if (pipe(proc.pipes[i]) == -1)
			return (3);

		++i;
	}
	proc.outfile = (argv[argc - 1]);
	proc.infile = (argv[1]);
		
	i = 0;
	while (i < (proc.cmd_nb))
	{
		proc.pids[i] = fork();
		if (proc.pids[i] == -1)
			return (4);

		if (proc.pids[i] == 0)
		{
			j = 0;
			while (j <= (proc.cmd_nb - 1))
			{
				if (j != i)
					close(proc.pipes[j][WRITE_END]);
				else if (j != i + 1)
					close(proc.pipes[j][READ_END]);
				++j;
			}
				pars = ft_split(*(argv + 1 + 1 + i), ' ');
				proc.cmd = access_check(path, *pars, R_OK);

			if (proc.cmd == NULL)
				return (printf("Path for command not found == %i\n", i), 5);

			if (i == 0)
			{

				proc.fd = open(proc.infile, O_RDONLY, 0774);
				dup22(STDIN_FILENO, proc.fd, STDOUT_FILENO, proc.pipes[i][WRITE_END]);
			}
			else if (i == (proc.cmd_nb - 1))
			{
				proc.fd = open(proc.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0774);
				dup22(STDOUT_FILENO, proc.fd, STDIN_FILENO, proc.pipes[i - 1][READ_END]);
			}
			else
				dup22(STDOUT_FILENO, proc.pipes[i][WRITE_END], STDIN_FILENO, proc.pipes[i - 1][READ_END]);

			if (execve(proc.cmd, pars, envp) == -1)
				perror("execve");
		}
		++i;
	}
	i = 0;
	while (i < (proc.cmd_nb - 1))
	{
		close(proc.pipes[i][READ_END]);
		close(proc.pipes[i][WRITE_END]);
		++i;
	}
	i = 0;
	while (i < (proc.cmd_nb))
	{
		wait(NULL);
		++i;
	}
	return (0);
}

