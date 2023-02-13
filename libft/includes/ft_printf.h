/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:00:53 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/09 16:54:20 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_printc(char c);
int		ft_prints(char *s);
int		ft_printp(size_t p);
int		ft_printdi(int n);
int		ft_printu(unsigned int u);
int		ft_printx(unsigned int x);
int		ft_printx_(unsigned int X);

// size_t	ft_strlen(char *s);
// void	*ft_memchr(const void *s, int c, size_t n);
#endif