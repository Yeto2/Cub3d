/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:14:21 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/16 05:31:59 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int  count_words(char const *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return (count);
}

static char *ft_strndup(const char *s, size_t n)
{
    char *str;
    size_t i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (n + 1));
    if (!str)
        return (NULL);
    while (s[i] && i < n)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!tab)
        return (NULL);
    while (s[i])
    {
        if (s[i] != c)
        {
            k = 0;
            while (s[i + k] && s[i + k] != c)
                k++;
            tab[j] = ft_strndup(s + i, k);
            if (!tab[j])
                return (NULL);
            j++;
            i += k;
        }
        else
            i++;
    }
    tab[j] = NULL;
    return (tab);
}
