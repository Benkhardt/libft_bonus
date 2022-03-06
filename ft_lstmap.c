/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:43:06 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/06 13:39:41 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp1 = lst;
	new_elem = ft_lstnew(f(tmp1->content));
	if (new_elem == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = new_elem;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		new_elem = ft_lstnew((*f)(tmp1->content));
		ft_lstadd_front(&new_lst, new_elem);
		tmp1 = tmp2;
	}
	return (new_lst);
}
