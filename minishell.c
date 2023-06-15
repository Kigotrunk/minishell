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

int	main(int argc, char **argv, char **envp)
{
    char    *tmp;
    char    **cmd;
    char    **env;

	(void)argc;
    (void)argv;
	write(1, "~$ ", 3);
    env = cpy_env(envp);
    while ((tmp = get_next_line(0)))
    {
        cmd = ft_split(tmp, ' ');
        if (builtin(cmd[0]) == 1)
            do_builtin(cmd, env);
		write(1, "~$ ", 3);
    }
    
}