/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:29:31 by ggregoir          #+#    #+#             */
/*   Updated: 2016/11/12 18:29:32 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (i >= len)
		{
			return (NULL);
		}
		if (lit[j] == big[i])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (lit[j] == '\0')
			return ((char *)big + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
