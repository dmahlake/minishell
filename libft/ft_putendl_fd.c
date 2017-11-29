/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:16:53 by dmahlake          #+#    #+#             */
/*   Updated: 2017/07/09 15:16:56 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char c;

	if (!s)
		return ;
	c = '\n';
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &c, 1);
}
