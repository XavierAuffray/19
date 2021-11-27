/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 12:35:57 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_result;
	t_list	*el_result;

	lst_result = NULL;
	if (!lst || !f)
		return (lst_result);
	while (lst)
	{
		el_result = ft_lstnew((*f)(lst->content));
		if (!el_result)
		{
			ft_lstclear(&lst_result, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_result, el_result);
		lst = lst->next;
	}
	return (lst_result);
}
