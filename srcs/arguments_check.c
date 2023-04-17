/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:01:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:01 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	argument_number(int argc)
{
	if (argc <= 4)
		return (ft_printf("At least four argument\n"), 1);
	return (0);
}
