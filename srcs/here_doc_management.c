/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:39 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/12 19:07:47 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static unsigned long	backup_random(void)
{
	static unsigned long	x = 42;

	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return (x);
}

char	*random_file_generator(void)
{
	unsigned char				buffer[8];
	int							fd;
	unsigned long				n;
	char						*nn;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		n = backup_random();
	else
	{
		read(fd, buffer, 8);
		close(fd);
		memcpy(&n, buffer, 8);
	}
	nn = ft_itoa(n);
	return (ft_strnjoinf2("/tmp/heredoc_", nn, ft_strlen(nn)));
}

int	here_file_generation(t_here *here)
{
	here->file_name = random_file_generator();
	while (existing_file(here->file_name, F_OK) == 0)
		here->file_name = random_file_generator();
	return (open(here->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0774));
}

int	stdin_to_here_file(t_here *here)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(here->limiter, line, ft_strlen(here->limiter)) != 0)
	{
		write(here->fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(here->fd);
	return (0);
}
