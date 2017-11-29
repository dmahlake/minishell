/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 12:25:19 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/26 11:54:15 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

int		ft_inputword(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_unsetenv(char **temp, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(temp[1], env[i], ft_inputword(env[i], '=')) == 0)
		{
			free(env[i]);
			while (env[i])
			{
				if (env[i + 1])
					env[i] = ft_strdup(env[i + 1]);
				else
					env[i] = NULL;
				i++;
				return ;
			}
		}
		i++;
	}
}
