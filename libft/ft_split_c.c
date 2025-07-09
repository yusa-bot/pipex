/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:49:40 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/09 14:55:57 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != c)
			i++;
	}
	return (count);
}

void	copy_words(char *tab, const char *str, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
		tab[j++] = str[start++];
	tab[j] = '\0';
}

int	find_next_word(const char *str, int *start, int *end, char c)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == c))
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
		&& str[i] != c)
		i++;
	*end = i;
	return (*start < *end);
}

//start, endをstr全体の変数として使っている。
int	ft_fill_words(char **tab, const char *str, char c)
{
	int	i;
	int	word;
	int	start;
	int	end;

	i = 0;
	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(str, &start, &end, c))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split_c(const char *str, char c)
{
	char	**out;
	int		size;

	size = count_words(str, c);
	out = malloc((sizeof(char *) * (size + 1)));
	if (!out)
		return (NULL);
	if (!ft_fill_words(out, str, c))
	{
		free(out);
		return (NULL);
	}
	return (out);
}

// #include <stdio.h>

// int main()
// {
// 	char	str[] = "111s222s333";
// 	char	c = 's';
// 	char **res = ft_split_c(str, c);

// 	int i = 0;
// 	while (res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		i++;
// 	}
// }
