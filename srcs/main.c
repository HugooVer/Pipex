/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/03/27 19:18:06 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**pars;
	
	char	*cmd;
	pid_t	*pids;
	int		**pipes;
	int		fd;
	int		cmd_nb;

	int		i;
	int		j;

	// printf("%i\n", argc);
	cmd_nb = argc-1;
	// printf("%i\n", cmd_nb);
	pids = malloc((cmd_nb + 1)* sizeof(pid_t));
	if (pids == NULL)
		return(5);
	pipes = malloc(cmd_nb * sizeof(int *));
	if (pipes == NULL)
		return(6);
	i = 0;
	while(i <= cmd_nb - 1)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (pipes[i] == NULL)
			return(7);
		++i;
	}
	if (argument_number(argc) == 1)
		return(1);

	path = envp_finder(envp, "PATH=");
	if (path == NULL)
		return (ft_printf("Env Error\n"), 2);

	i = 0;
	while (i < (cmd_nb) )
	{
		if (pipe(pipes[i]) == -1)
			return (3);
		// printf("Test %i\n", i);
		++i;
	}
	i = 0;
	while (i < (argc - 1))
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (4);
		// printf("\t%i\t%i\n", pids[i], getppid());
		if (pids[i] == 0)
		{
			j = 0;
			while (j < (argc - 2))
			{
				if (j != i)
					close(pipes[j][WRITE_END]);
				else if (j != i + 1)
					close(pipes[j][READ_END]);
				++j;
			}

			pars = ft_split(*(argv + 1 + i), ' ');
			cmd = access_check(path, *pars, R_OK);

			if (cmd == NULL)
				return (ft_printf("Path for command not found\n"), 5);
			if (i == 0)
			{
				// printf("---------i == 0--------\n");
				fd = open("infile", O_RDONLY, 774);
				dup2(fd, STDIN_FILENO);
				dup2(pipes[i][WRITE_END], STDOUT_FILENO);
			}
			else if(i == (argc - 2))
			{
				// printf("--------i == end--------\n");
				fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 774);
				dup2(fd, STDOUT_FILENO);
				dup2(pipes[i - 1][READ_END], STDIN_FILENO);
			}
			else
			{
				// printf("----------rest----------\n");
				dup2(pipes[i][WRITE_END], STDOUT_FILENO);
				dup2(pipes[i - 1][READ_END], STDIN_FILENO);
			}
			
			if (execve(cmd, pars, envp) == -1)
				perror("execve");
			close(pipes[i][READ_END]);
			close(pipes[i + 1][WRITE_END]);
			if (i == 0 || i == (argc - 2))
				close(fd);
			return (0);
		}
		++i;
	}
	i = 0;
	while (i < (argc - 2))
	{
		close(pipes[i][READ_END]);
		close(pipes[i][WRITE_END]);
		++i;
	}
	i = 0;
	while (i < (argc - 1))
	{
		wait(NULL);
		++i;
	}
	return (0);
}
