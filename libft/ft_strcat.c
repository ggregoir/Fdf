/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:14:14 by ggregoir          #+#    #+#             */
/*   Updated: 2016/11/11 15:14:16 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t destlen;
	size_t i;

	i = 0;
	destlen = ft_strlen(s1);
	while (s2[i])
	{
		s1[destlen + i] = s2[i];
		i++;
	}
	s1[destlen + i] = '\0';
	return (s1);
}
