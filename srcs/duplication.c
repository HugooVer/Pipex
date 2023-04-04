/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:49:55 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/04 23:50:05 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	dup22(int fd1, int fdd1, int fd2, int fdd2)
{
	dup2 (fdd1, fd1);
	close(fdd1);
	dup2 (fdd2, fd2);
	close(fdd2);
	return(1);
}
