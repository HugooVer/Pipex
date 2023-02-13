/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:52:56 by hvercell          #+#    #+#             */
/*   Updated: 2022/12/08 19:20:56 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*lstu;

	if (lst != NULL && *lst != NULL && del != NULL)
	{
		lstu = *lst;
		*lst = NULL;
		while (lstu != NULL)
		{
			temp = lstu->next;
			ft_lstdelone(lstu, del);
			lstu = temp;
		}
	}
}
