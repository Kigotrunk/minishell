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
        /*else
            pipex();*/
		write(1, "~$ ", 3);
    }
    
}