/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:57:42 by dmahlake          #+#    #+#             */
/*   Updated: 2017/07/09 17:32:54 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*ft_cleanstr(const char *str)
{
	char *p_str;

	p_str = (char *)str;
	while ((*p_str >= 'a' && *p_str <= 'z') || (*p_str >= 'A' && *p_str <= 'Z'))
		return (p_str);
	while (*p_str != '-' && (*p_str < '0' || *p_str > '9') && *p_str != '\0')
	{
		if (*p_str == '\e')
			return (p_str);
		p_str++;
	}
	return (p_str);
}

int				ft_atoi(const char *str)
{
	int		sign;
	int		res;
	char	*p_str;

	sign = 1;
	res = 0;
	p_str = ft_cleanstr(str);
	if (*p_str == '-')
	{
		sign *= -1;
		p_str++;
	}
	while (*p_str)
	{
		if (*p_str < '0' || *p_str > '9')
			return (res * sign);
		res = (res * 10) + (*p_str - '0');
		p_str++;
	}
	return (res * sign);
}
