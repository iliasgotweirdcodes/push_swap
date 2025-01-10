/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:47:19 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 22:14:45 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_free(char **str, int i)
{
	if (str)
	{
		while (i >= 0)
		{
			free(str[i]);
			i--;
		}
		free(str);
	}
	return (NULL);
}

char	**ft_alloc(char **str, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < ft_countwords(s, c))
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		str[i] = ft_strdup(ft_substr(s, start, end - start));
		if (!str[i])
			return (NULL);
		j = 0;
		while (start < end)
			str[i][j++] = s[start++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

char **ft_split(char *s, char c)
{
	char **str;

	if (!s)
		return (NULL);
	str = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_alloc(str, s, c);
	return (str);
}
