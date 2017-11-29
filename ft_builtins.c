/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:00:23 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/28 12:03:33 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

void	exec_com(char *comm, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(comm, args, g_env);
		ft_putstr("Error: Fork failed\n");
	}
	else
	{
		wait(0);
		ft_strdel(&comm);
	}
}

void	display_env(char **ptr)
{
	int		i;

	i = -1;
	while (ptr[++i])
	{
		ft_putstr(ptr[i]);
		ft_putchar('\n');
	}
}

void	ft_2dfree(char **a)
{
	int		id;

	id = -1;
	while (a[++id])
	{
		free(a[id]);
		a[id] = NULL;
	}
	free(a);
}
