/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:39:43 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:58:20 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	handle_sign(const char **str)
{
	int	sign;

	sign = 1;
	if ((**str == '-' || **str == '+') && *(*str + 1) != '\0')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	handle_overflow(long result, int sign, int *error)
{
	if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
	{
		*error = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	*error = 0;
	while (ft_isspace(*str))
		str++;
	sign = handle_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (handle_overflow(result, sign, error))
			return (0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(sign * result));
}
