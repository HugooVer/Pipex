/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:39 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/11 17:26:39 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_char(char const *s1, char s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (s1 == NULL && s2 == '\0')
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != '\0')
		len2 = 1;
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(ret, s1, len1 + 1);
	if (s2 != '\0')
		ft_strlcpy(ret + len1, &s2, len2 + 1);
	return (ret);
}

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
	return (ft_strjoin("/tmp/heredoc_", ft_itoa(n)));
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
	while (strncmp(here->limiter, line, ft_strlen(here->limiter)) != 0)
	{
		write(here->fd, line, ft_strlen(line));
		line = get_next_line(STDIN_FILENO);
	}
	close(here->fd);
	return (0);
}
