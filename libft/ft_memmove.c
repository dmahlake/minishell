/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:15:38 by dmahlake          #+#    #+#             */
/*   Updated: 2017/07/09 15:15:43 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dst;
	size_t	i;

	p_src = (char *)src;
	p_dst = (char *)dst;
	i = 0;
	if (p_src == p_dst)
	{
		return (dst);
	}
	else if (p_src > p_dst)
	{
		while (n-- > 0)
			*p_dst++ = *p_src++;
	}
	else if (p_src < p_dst)
	{
		while (n-- > 0)
		{
			p_dst[n] = p_src[n];
		}
	}
	return (dst);
}
