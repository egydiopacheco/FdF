/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:34:44 by epacheco          #+#    #+#             */
/*   Updated: 2021/09/11 13:34:46 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*new;
	void	*op;

	lst_f = NULL;
	while (lst)
	{
		op = f(lst->content);
		new = ft_lstnew(op);
		if (!new)
			ft_lstclear(&lst_f, del);
		ft_lstadd_back(&lst_f, new);
		lst = lst->next;
	}
	return (lst_f);
}
