/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:57:08 by pauljull          #+#    #+#             */
/*   Updated: 2018/12/04 21:46:00 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*new;
	t_list	*begin;
	t_list	*mapbuff;

	if (!f || !lst || !(new = ft_lstdup(lst)))
		return (NULL);
	begin = new;
	while (new)
	{
		mapbuff = f(new);
		new->content = mapbuff->content;
		new->content_size = mapbuff->content_size;
		new = new->next;
	}
	return (begin);
}
