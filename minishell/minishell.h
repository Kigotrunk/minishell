/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:58:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/15 21:43:22 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line_bonus.h"

void    free_tab(char **tab);
int     quote_check(char *str);
int	    arg_c(char *str);
char	*eoa_quote(char *str, char c);
char    *eoa_str(char *str);
int     arg_len(char *str);
char	*get_arg(char *str);
char	**split_args(char *str);

void    builtins_cd(const char *path);
void    builtins_pwd(char **cmd);
int     builtin(char *cmd);
void    do_builtin(char **cmd, char **env);
char    **new_env(char **envp);
void    builtins_env(char **envp);

#endif