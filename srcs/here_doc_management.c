/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:39 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/09 19:30:56 by hvercell         ###   ########.fr       */
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

static unsigned int	backup_random(void)
{
	static unsigned int	x = 42;

	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (x);
}

char	*random_file_generator(void)
{
	int							i;
	unsigned char				buffer[8];
	int							fd;
	char						*ret;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (ft_itoa(backup_random()));
	read(fd, buffer, 8);
	close(fd);
	i = 0;
	while (i < 8)
	{
		ret = ft_strjoin_char(ret, buffer[i]);
		++i;
	}
	return (ret);
}

int	here_file_generation(void)
{
	char	*here_file = NULL;

	while (existing_file(here_file, F_OK) == -1)
		here_file = random_file_generator();
	return (open(here_file, O_WRONLY | O_CREAT, 0774));
}

int	stdin_to_here_file(t_here *here)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (strncmp(here->limiter, line, ft_strlen(here->limiter)))
	{
		write(here->fd, line, ft_strlen(line));
		line = get_next_line(STDIN_FILENO);
	}
	close(here->fd);
	return (0);
}
