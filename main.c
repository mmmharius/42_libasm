/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:14:16 by mpapin            #+#    #+#             */
/*   Updated: 2025/07/10 20:17:30 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int     ft_strcmp(char *s1, char *s2);
int     ft_strlen(const char *s);
char    *ft_strcpy(char *dst, char *src);

int     main(int argc, char **argv)
{
    //ft_strlen.s
    // if (argc != 2)
    //     return(printf("./libasm \"s1\"\n"), 1);
    // else
    // {
    //     printf("mon strlen : %d\n", ft_strlen(argv[1]));
    //     printf("the strlen : %ld\n", strlen(argv[1]));
    // }
    
    //ft_strcpy.s
    if (argc != 3)
        return(printf("./libasm \"s1\" \"s2\"\n"), 1);
    else
    {
        char buffer_1[ft_strlen(argv[2])];
        char buffer_2[ft_strlen(argv[2])];

        printf("mon srcpy renvoie : %s\n", ft_strcpy(buffer_1, argv[2]));  
        printf("the srcpy renvoie : %s\n", strcpy(buffer_2, argv[2]));
    }
    //ft_strcmp.s
    // if (argc != 3)
    //     return(printf("./libasm \"s1\" \"s2\"\n"), 1);
    // else
    // {
    //     printf("mon strcmp : %d\n", ft_strcmp(argv[1], argv[2]));
    //     printf("the strcmp : %d\n", strcmp(argv[1], argv[2]));
    // }
        
        
    //ft_read.s
    return (0);
}