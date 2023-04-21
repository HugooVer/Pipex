/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:39 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/21 22:49:50 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	to_hex(size_t x)
{
	char	*str;
	char	*t = NULL;

	str = "0123456789ABCDEF";
	if (x > 0)
	{
		to_hex(x / 16);
		ft_strjoin(t, &str[x % 16]);
	}
	printf("%s", t);
}


int	yolo(void)
{
	int				i;
	unsigned char	buffer[8];
	int				fd;

	fd = open("/dev/random", O_RDONLY);
	read(fd, buffer, 8);
	close(fd);
	i = 0;
	while (i < 8)
	{
		to_hex(buffer[i]);
		++i;
	}
	printf("\n");
	return (0);
}

