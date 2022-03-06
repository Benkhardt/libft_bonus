/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:08:45 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/06 14:42:45 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**tmp;

	if (new == NULL || lst[0] == NULL)
		return ;
	tmp = lst;
	while (lst[0]->next != NULL)
		lst[0] = lst[0]->next;
	lst[0]->next = new;
	lst = tmp;
}
