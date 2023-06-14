/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:58:25 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/14 19:05:29 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
    char    *tmp;
    char    **cmd;
	int		x;

	
	write(1, "~$ ", 3);
    while ((tmp = get_next_line(0)))
    {
		x = 0;
        //printf("cmd %s\n", tmp);
		
        /*if (cmd == EOF)
        {
            write(1, "exit\n", 5);
            exit(1);
        }*/
        cmd = ft_split(tmp, ' ');
		while (cmd[x])
		{
			printf("%s\n", cmd[x]);
			x++;
		}
        if (builtin(cmd[0]) == 1)
            do_builtin(cmd);
		write(1, "~$ ", 3);
    }
    
}

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
}