/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:17:50 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 22:19:26 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*src;
	char	*dst;

	i = 0;
	len = ft_strlen(s1);
	dst = malloc(len + 1);
	src = (char *)s1;
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	// free((void *)s1);
	return (dst);
}
