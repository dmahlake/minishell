/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:02:30 by dmahlake          #+#    #+#             */
/*   Updated: 2017/09/28 12:44:28 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/dir.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define ANSI_COLOR_RED	"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define BUFF_SIZE 1024

char	**g_env;

void	ft_cd(char **args);
void	display_env(char **ptr);
void	ft_2dfree(char **a);
int		command_found(char **name, char **args);
void	ft_echo(char **args);
char	**ft_cpy_env(char **environ);
void	ft_setenv(char *name, const char *value);
void	ft_unsetenv(char **temp, char **env);
int		get_next_line(const int fd, char **line);
char	*ft_getenv(const char *name);
void	exec_com(char *comm, char **args);
int		builtins(char **first);
int		main(int agc, char **argv, char **env);

#endif
