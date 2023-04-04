/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/04 23:51:00 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define WRITE_END 1
# define READ_END 0

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include <sys/wait.h>


typedef struct s_proc	t_proc;

struct s_proc
{
	pid_t	*pids;
	int		**pipes;
	int		fd;
	int		cmd_nb;
	char	*cmd;
	char	*infile;
	char	*outfile;
};


char	*access_check(char *path, char *cmd, int amode);
char	*envp_finder(char **envp, char *flag);
int		argument_number(int argc);
int		dup22(int fd1, int fdd1, int fd2, int fdd2);


#endif