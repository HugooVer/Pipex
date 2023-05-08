/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/08 16:58:28 by hvercell         ###   ########.fr       */
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
# include <errno.h>

typedef struct s_proc	t_proc;

struct s_proc
{
	pid_t	*pids;
	int		**pipes;
	int		cmd_nb;
	int		child;
	int		fdin;
	int		fdout;
	char	*cmd;
	char	*infile;
	char	*outfile;
};

typedef struct s_path	t_path;

struct s_path
{
	char	*path;
	char	**pars;
};

typedef struct s_arg	t_arg;

struct s_arg
{
	int		argc;
	char	**argv;
	char	**envp;
};

char	*access_check(char *path, char *cmd, int amode);
char	*envp_finder(char **envp, char *flag);
int		argument_number(t_arg *arg, int nb);
int		dup2close(int fd1, int fdd1, int fd2, int fdd2);
int		pipe_creation(t_proc *proc);
int		pipe_initialisation(t_proc *proc);
int		data_preset(t_proc *proc, t_path *path, t_arg *arg);
int		child_management(t_proc *proc, t_path *path, t_arg *arg);
int		arg_to_t_arg(int argc, char **argv, char **envp, t_arg *arg);
int		child_position_check(t_proc *proc);
int		wait_for_childs(t_proc *proc);
int		close_all_pipes(t_proc *proc);
int		free_all_data(t_proc *proc);
int		permission_error(t_proc *proc);
int		errno_error(t_proc *proc, t_path *path);

char	*random_file_generator(void);
int		here_doc_check(t_arg *arg);

#endif