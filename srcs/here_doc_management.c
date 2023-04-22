/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:39 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/22 22:18:13 by hvercell         ###   ########.fr       */
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

struct s_xorshift64_state {
	uint64_t	a;
};

uint64_t	xorshift64(struct s_xorshift64_state *state)
{
	uint64_t	x;

	x = state->a;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return (state->a = x);
}

char	*random_file_generator(void)
{
	int							i;
	unsigned char				buffer[8];
	int							fd;
	char						*ret;
	struct s_xorshift64_state	state;
	char						*tp = "ok";

	fd = -1;
	// fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		// fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
	{
			state.a = 1; //to get a seed use "date +%s%N | cut -b1-13" or just "date +%s%N" can be a good solution
		printf("%lu", xorshift64(&state));
		return (tp);
	}
	read(fd, buffer, 8);
	close(fd);
	i = 0;
	while (i < 8)
	{
		ret = ft_strjoin_char(ret, buffer[i]);
		++i;
	}
	printf("%s", ret);
	return (ret);
}
