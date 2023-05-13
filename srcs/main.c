/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 20:10:53 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_proc	proc;
	t_path	path;
	t_arg	arg;
	t_here	here;

	// ft_memset(&proc, 0, sizeof(t_proc));
	// ft_memset(&path, 0, sizeof(t_path));
	// ft_memset(&arg, 0, sizeof(t_arg));
	// ft_memset(&here, 0, sizeof(t_here));
	arg_to_t_arg(argc, argv, envp, &arg);
	here_doc_check(&arg, &here);
	if (argument_number(&arg, 4 + here.here) == 1)
		exit(EXIT_FAILURE);
	if (here.here == 1)
	{
		here.fd = here_file_generation(&here);
		stdin_to_here_file(&here);
	}
	data_preset(&proc, &path, &arg, &here);
	child_management(&proc, &path, &arg, &here);
	close_all_pipes(&proc);
	wait_for_childs(&proc, &here, &path);
	return (0);
}
