/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:58:39 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/28 12:08:39 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

char	*ft_getenv(const char *name)
{
	char	**env;
	int		len;

	env = g_env;
	len = ft_strlen(name);
	while (*env)
	{
		if (ft_strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}

int		ft_chdir(char *newdir)
{
	char b[2048];

	if (chdir(newdir) != -1)
	{
		ft_setenv("OLDPWD", ft_strchr(ft_getenv("PWD"), '/'));
		ft_setenv("PWD", getcwd(b, 2048));
		return (1);
	}
	return (0);
}

char	*get_newdir(char **args)
{
	char *newdir;

	if (args[1][0] == '~')
	{
		args[1]++;
		newdir = ft_strjoin(ft_strchr(ft_getenv("HOME"), '/'), args[1]);
	}
	else
	{
		if (args[1][0] == '/')
			newdir = args[1];
		else
		{
			newdir = ft_strjoin(ft_strchr(ft_getenv("PWD"), '/'), "/");
			newdir = ft_strjoin(newdir, args[1]);
		}
	}
	return (newdir);
}

void	ft_cd(char **args)
{
	char	*newdir;
	int		ch;

	ch = 0;
	if (args[1] == NULL || (args[1][0] == '~' && ft_strlen(args[1]) == 1))
		ch = ft_chdir(ft_strchr(ft_getenv("HOME"), '/'));
	else if (args[1][0] == '-')
		ch = ft_chdir(ft_strchr(ft_getenv("OLDPWD"), '/'));
	else
	{
		newdir = get_newdir(args);
		ch = ft_chdir(newdir);
	}
	if (ch == -1)
	{
		ft_putendl("ERROR: no such file or directory");
		return ;
	}
}
