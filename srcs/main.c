/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/08 17:03:20 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_proc	proc;
	t_path	path;
	t_arg	arg;

	arg_to_t_arg(argc, argv, envp, &arg);
	if (here_doc_check(&arg) == 1)
	{
		if (argument_number(&arg, 5) == 1)
			return (1);
		printf("%s\n", random_file_generator());

	}
	else
	{
		data_preset(&proc, &path, &arg);
		child_management(&proc, &path, &arg);
		close_all_pipes(&proc);
		wait_for_childs(&proc);
	}
	return (0);
}
