/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:17:55 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/28 20:25:48 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/includes/libft.h"
#include "signal.h"

void	ft_signal(int sig)
{
	if (sig == 2)
		ft_putchar('\n');
}

int		builtins(char **first)
{
	char	*name;

	name = NULL;
	signal(2, ft_signal);
	if (ft_strcmp(first[0], "env") == 0)
		display_env(g_env);
	else if (ft_strcmp(first[0], "setenv") == 0)
		ft_setenv(first[1], first[2]);
	else if (ft_strcmp(first[0], "unsetenv") == 0)
		ft_unsetenv(first, g_env);
	else if (ft_strcmp(first[0], "echo") == 0)
		ft_echo(&first[1]);
	else if (ft_strcmp(first[0], "cd") == 0)
		ft_cd(first);
	else if (command_found(&name, first))
		exec_com(name, first);
	return (1);
}

void	signal_handler(int sig)
{
	if (sig == 2)
		ft_putstr("\b \b\b \b \n\x1B[36mMini_dee$>\x1B[0m ");
}

int		main(int argc, char **argv, char **env)
{
	char	*input;
	char	*tmp;

	g_env = env;
	g_env = ft_cpy_env(env);
	while (argc)
	{
		signal(2, signal_handler);
		ft_putstr("\x1B[36mMini_dee$>\x1B[0m ");
		get_next_line(0, &input);
		tmp = input;
		input = ft_strtrim(input);
		argv = ft_strsplit(input, ' ');
		ft_strdel(&tmp);
		if (ft_strlen(input))
			if (!ft_strcmp(argv[0], "exit") || !builtins(argv))
			{
				ft_2dfree(argv);
				ft_strdel(&input);
				return (1);
			}
		ft_strdel(&input);
	}
	ft_2dfree(argv);
	return (0);
}
