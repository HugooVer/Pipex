/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:01:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/11 16:46:41 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	argument_number(t_arg *arg, int nb)
{
	if (arg->argc <= nb)
		return (ft_printf("At least %i arguments\n", nb), 1);
	return (0);
}

int	here_doc_check(t_arg *arg, t_here *here)
{
	if (ft_strncmp(arg->argv[1], "here_doc", ft_strlen(arg->argv[1])) == 0)
		return (here->here = 1, here->limiter = arg->argv[2], 1);
	return (here->here = 0, 0);
}
