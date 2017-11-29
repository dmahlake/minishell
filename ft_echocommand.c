/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echocommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:32:46 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/20 16:28:10 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

void	ft_echo_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\\' && str[i] != '\'')
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar(' ');
}

void	ft_echo(char **args)
{
	char	*enstr;

	while (*args)
	{
		if (*args[0] == '$')
		{
			(*args)++;
			enstr = ft_getenv(*args);
			if (enstr)
				ft_putstr(ft_strchr(enstr, '=') + 1);
		}
		else
			ft_echo_putstr(*args);
		args = args + 1;
	}
	ft_putchar('\n');
}
