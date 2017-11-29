/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:18:46 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/15 16:03:01 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strclr(char *s)
{
	char *p_s;

	if (!s)
		return ;
	p_s = s;
	while (*p_s)
		*p_s++ = '\0';
}