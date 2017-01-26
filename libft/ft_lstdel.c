/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:07:56 by ggregoir          #+#    #+#             */
/*   Updated: 2016/11/19 11:07:57 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*list;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list != NULL)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	*alst = NULL;
}
