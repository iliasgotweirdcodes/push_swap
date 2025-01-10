/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:18:40 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 22:15:57 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}

char	*join_args(char **av, char *str)
{
    char    *temp;
    int     i;

    str = ft_strdup("");
    if (!str)
        return (NULL);
    i = 1;
    while (av[i])
    {
        temp = str;
        str = ft_strjoin(str, " ");
        free(temp);
        if (!str)
            return (NULL);
		if (av[i + 1])
		{
			temp = str;
			str = ft_strjoin(temp, " ");
			free(temp);
		}
        if (!str)
            return (NULL);
        i++;
    }
    return (str);
}
