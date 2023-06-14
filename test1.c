/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:49:35 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 23:49:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    prompt()
{
    char    *tmp;
    char    **cmd;

    while (tmp = get_next_line(0) != 0)
    {
        printf("cmd %s\n", tmp);
        write(1, "~$ ", 3);
        if (cmd = EOF)
        {
            write(1, "exit\n", 5);
            exit(1);
        }
        cmd = ft_split(tmp, " ");
        if (builtin(cmd[0]) == 1)
            do_builtin(cmd);
    }
    
}

void    builtins_cd(const char *path)
{
    int i;

    i = chdir(path);
    if (i == -1)
        perror("path");
}

void    builtins_pwd()
{
    char    *pwd;

    pwd = (char *)malloc(PATH_MAX * sizeof(char));
    pwd = getcwd(pwd, PATH_MAX);
    if (pwd == NULL)
        perror("path");
    else
        printf("%s\n", pwd);
}

// echo cd pwd export unset env exit
int builtin(char *cmd)
{
    char    *all_cmd;
    char    **tab_cmd;
    int     i;

    i = 0;
    all_cmd = malloc(ft_strlen("echo cd pwd export unset env exit") * sizeof(char));
    all_cmd = "echo cd pwd export unset env exit";
    tab_cmd = ft_split(all_cmd, " ");
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
    if (ft_strncmp(cmd[0], "cd", ft_strlen(cmd)) == 0)
        builtins_cd(cmd[1]);
    if (ft_strncmp(cmd[0], "pwd", ft_strlen(cmd)) == 0)
        builtins_pwd();
    
}