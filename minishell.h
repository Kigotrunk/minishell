/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:58:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/14 19:05:24 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

void    builtins_cd(const char *path);
void    builtins_pwd(char **cmd);
int     builtin(char *cmd);
void    do_builtin(char **cmd);
char    **new_env(char **envp);
void    builtins_env(char **envp);

#endif