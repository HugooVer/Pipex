/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/12 15:01:26 by hvercell         ###   ########.fr       */
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

typedef struct s_here	t_here;

struct s_here
{
	int		here;
	int		fd;
	char	*file_name;
	char	*limiter;
};

char	*access_check(char *path, char *cmd, int amode);
char	*envp_finder(char **envp, char *flag, t_path *path);
int		argument_number(t_arg *arg, int nb);
int		dup2close(int fd1, int fdd1, int fd2, int fdd2);
int		pipe_creation(t_proc *proc);
int		pipe_initialisation(t_proc *proc);
int		data_preset(t_proc *proc, t_path *path, t_arg *arg, t_here *here);
int		child_management(t_proc *proc, t_path *path, t_arg *arg, t_here *here);
int		arg_to_t_arg(int argc, char **argv, char **envp, t_arg *arg);
int		child_position_check(t_proc *proc, t_here *here);
int		wait_for_childs(t_proc *proc, t_here *here, t_path *path);
int		close_all_pipes(t_proc *proc);
int		free_all_data(t_proc *proc, t_here *here, t_path *path);
int		permission_error(t_proc *proc, t_here *here);
int		errno_error(t_proc *proc, t_path *path, t_here *here);

char	*random_file_generator(void);
int		here_doc_check(t_arg *arg, t_here *here);
int		here_file_generation(t_here *here);
int		stdin_to_here_file(t_here *here);
int		existing_file(char *file_name, int amode);

#endif