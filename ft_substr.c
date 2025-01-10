/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:04:58 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/05 17:05:18 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (NULL);
	if (!len || (i >= ft_strlen(s)))
		return (ft_strdup(""));
	if (len > ft_strlen(start + s))
		sub = malloc(ft_strlen(start + s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[i] && j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
