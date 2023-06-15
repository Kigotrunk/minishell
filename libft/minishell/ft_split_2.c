/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:47:25 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/15 18:14:04 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_word(const char *str, char charset);
int		word_len(const char *str, char charset);
int		arg_c(const char *str);
char	**ft_split_2(const char *s, char c);
char	*eoa_quote(char *str, char c);

char	*eoa_quote(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		exit (11);
	while (str[i] != ' ')
		i++;
	return (str[i]);
}

int	arg_c(const char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '\"' || *str == '\'')
		{
			n++;
			str = eoa_quote(*str, str);
		}
		else
		{
			n++;
			while (*str != ' ' && *str)
				str++;
		}
	}
	return (n);
}

int	word_len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (!is_charset(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*get_arg(const char *str, char charset)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = word_len(str, charset);
	line = (char *)malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**ft_split_2(char const *str, char c)
{
	char	**tab;
	int		ac;
	int		i;

	ac = arg_c(str);
	tab = (char **)malloc((ac + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '\'')
		{
			tab[i] = get_arg(str);
			str = eoa_quote(str, '\'');
			i++;
		}
		else if(*str == '\"')
		{
			tab[i] = get_arg_quote(str);
			str = eoa_quote(str, '\"');
			i++;
		}
		else
		{
			tab[i] = get_arg(str)
			while (*str != ' ' && *str)
				str++;
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
