/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/21 20:49:03 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// t_proc	proc;
	// t_path	path;
	// t_arg	arg;
	(void)argv;
	(void)argc;
	(void)envp;
	yolo();
	// arg_to_t_arg(argc, argv, envp, &arg);
	// data_preset(&proc, &path, &arg);
	// child_management(&proc, &path, &arg);
	// close_all_pipes(&proc);
	// wait_for_childs(&proc);
	return (0);
}
