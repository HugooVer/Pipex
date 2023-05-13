/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:26:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 15:13:18 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_prints(char *s)
{
	int	len;

	if (s == NULL)
		return (ft_prints("(null)"));
	len = ft_strlen(s) * sizeof(char);
	write(2, s, len);
	return (len);
}
