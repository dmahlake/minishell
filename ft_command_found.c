/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:41:08 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/26 12:38:55 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

char	*exec_find(char **args, char **paths)
{
	char	*res;
	char	*tmp;
	char	**t_path;

	t_path = paths;
	if (access(*args, F_OK) == 0)
		return (*args);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		res = ft_strjoin(tmp, *args);
		ft_strdel(&tmp);
		if (access(res, X_OK) == 0)
		{
			ft_2dfree(t_path);
			return (res);
		}
		ft_strdel(&res);
		paths++;
	}
	ft_2dfree(t_path);
	return (NULL);
}

char	**path(void)
{
	char		**path;
	char		**env;
	char		*str;

	env = g_env;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
		{
			str = ft_strchr(*env, '/');
			path = ft_strsplit(str, ':');
		}
		env++;
	}
	return (path);
}

int		command_found(char **name, char **args)
{
	*name = exec_find(args, path());
	if (*name == NULL)
	{
		ft_putstr(args[0]);
		ft_putstr(": command not found\n");
		return (0);
	}
	return (1);
}
