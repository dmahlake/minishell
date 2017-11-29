/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 10:37:22 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/20 15:10:27 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "minishell.h"

char	**ft_cpy_env(char **environ)
{
	char	**d_env;
	int		i;

	i = 0;
	d_env = g_env;
	while (*d_env)
	{
		environ[i] = ft_strdup(*d_env);
		d_env = d_env + 1;
		i++;
	}
	return (environ);
}
