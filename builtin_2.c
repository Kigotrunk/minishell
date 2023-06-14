/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:35:58 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 01:35:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtins_cd(const char *path)
{
    int i;

    i = chdir(path);
    if (i == -1)
        perror("path");
}

void    builtins_pwd(char **cmd)
{
    char    *pwd;

	if (cmd[1])
	{
		write(1, "too many arguments\n", 19);
		return ;
	}
	else
	{
    	pwd = (char *)malloc(2048 * sizeof(char));
    	pwd = getcwd(pwd, 2048);
    	if (pwd == NULL)
       		perror("path");
    	else
        	printf("%s\n", pwd);
	}
}

void    builtins_env(char **envp)
{
    char    **env;
    int     i;

    env = new_env(envp);
}