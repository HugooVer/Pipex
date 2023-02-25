/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/25 19:14:07 by hvercell         ###   ########.fr       */
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

char	*access_check(char *path, char *cmd, int amode);
char	*envp_finder(char **envp, char *flag);

#endif