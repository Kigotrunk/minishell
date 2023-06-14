/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:23:17 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 01:23:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// echo cd pwd export unset env exit
int builtin(char *cmd)
{
    char    *all_cmd;
    char    **tab_cmd;
    int     i;

    i = 0;
    all_cmd = malloc(ft_strlen("echo cd pwd export unset env exit PWD") * sizeof(char));
    all_cmd = "echo cd pwd export unset env exit PWD";
    tab_cmd = ft_split(all_cmd, ' ');
    while (tab_cmd[i])
    {
        if (ft_strncmp(tab_cmd[i], cmd, ft_strlen(cmd)) == 0)
            return (1);
        i++;
    }
    return (0);
}

void    do_builtin(char **cmd)
{
    if (ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])) == 0)
        builtins_cd(cmd[1]);
    if (ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])) == 0 || ft_strncmp(cmd[0], "PWD", ft_strlen(cmd[0])) == 0)
        builtins_pwd(cmd);
    if (ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])) == 0)
        builtin_env();
}