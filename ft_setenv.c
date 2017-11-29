/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:13:06 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/28 20:25:52 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"

int		env_rep(char *envstr, int *envlen, int len)
{
	char **envcpy;

	envcpy = g_env;
	while (*envcpy)
	{
		if (strncmp(*envcpy, envstr, len) == 0)
		{
			*envcpy = envstr;
			return (1);
		}
		envcpy++;
		(*envlen)++;
	}
	return (0);
}

void	ft_putenv(char *envstr)
{
	char	*temp;
	char	**newenv;
	int		len;
	int		envlen;

	temp = ft_strchr(envstr, '=');
	len = ft_strlen(envstr) - ft_strlen(temp);
	envlen = 0;
	if (temp == NULL)
		return ;
	if (env_rep(envstr, &envlen, len))
		return ;
	newenv = (char **)malloc(sizeof(char *) * (envlen + 2));
	if (newenv == NULL)
		return ;
	ft_cpy_env(newenv);
	newenv[envlen] = envstr;
	newenv[envlen + 1] = NULL;
	g_env = newenv;
}

void	ft_setenv(char *name, const char *value)
{
	char *envstr;

	if (name == NULL || name[0] == '\0')
		ft_putstr("setenv: name is null\n");
	else if (value == NULL)
	{
		ft_putendl(name);
		ft_putstr("setenv: value is null\n");
	}
	else
	{
		envstr = (char *)malloc(sizeof(char) * (ft_strlen(name)
					+ ft_strlen(value) + 2));
		if (envstr == NULL)
			return ;
		ft_strcpy(envstr, name);
		ft_strcat(envstr, "=");
		ft_strcat(envstr, value);
		ft_putenv(envstr);
	}
}
