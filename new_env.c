/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:24:42 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    **new_env(char **envp)
{
    char    **env;
    int     i;
    while (envp[i])
        i++;
    env = malloc((i + 1) * sizeof(char *));
    if (!env)
    {
        perror("malloc env : ");
        exit(-1);
    }
    i = 0;
    while (envp[i])
    {
        env[i] = envp[i];
        i++;
    }
    return (env);
}