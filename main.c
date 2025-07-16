/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:14:16 by mpapin            #+#    #+#             */
/*   Updated: 2025/07/16 13:37:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_strcmp(const char *s1, const char *s2);
size_t  ft_strlen(const char *s);
char    *ft_stpcpy(char *restrict dst, const char *restrict src);
ssize_t ft_write(int fd, char *buf, int nbyte);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

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
    // if (argc != 3)
    //     return(printf("./libasm \"s1\"\n"), 1);
    // else
    // {
    //     char buffer_1[ft_strlen(argv[1])];
    //     char buffer_2[ft_strlen(argv[1])];

    //     printf("mon srcpy renvoie : %s\n", ft_strcpy(buffer_1, argv[1]));  
    //     printf("the srcpy renvoie : %s\n", strcpy(buffer_2, argv[1]));
    // }
    
    //ft_strcmp.s
    // if (argc != 3)
    //     return(printf("./libasm \"s1\" \"s2\"\n"), 1);
    // else
    // {
    //     printf("mon strcmp : %d\n", ft_strcmp(argv[1], argv[2]));
    //     printf("the strcmp : %d\n", strcmp(argv[1], argv[2]));
    // }
        
    
    //ft_write.s
    // if (argc != 4)
    //     return(printf("./libasm \"fd\" \"msg\" \"nb_bytes\"\n"), 1);
    // else
    // {
    //     int fd = atoi(argv[1]);
    //     int size = atoi(argv[3]);
    //     ssize_t result_1;
    //     ssize_t result_2;
        
    //     printf("---MON WRITE---\n");
    //     result_1 = ft_write(fd, argv[2], size);
    //     printf("renvoie: %d\n", result_1);
        
    //     printf("---THE WRITE---\n");
    //     result_2 = write(fd, argv[2], size);
    //     printf("renvoie: %ld\n", result_2);
    // }
    
    //ft_read.s
    // if (argc != 4)
    //     return(printf("./libasm \"fd\" \"msg\" \"nb_bytes\"\n"), 1);
    // else
    // {
    //     ssize_t result_1;
    //     ssize_t result_2;
    //     int fd = atoi(argv[1]);
    //     int nb_bytes = atoi(argv[3]);
    //     char buffer_1[1000] = {0};
    //     char buffer_2[1000] = {0};
        
    //     printf("---MON READ---\n");
    //     strcpy(buffer_1, argv[2]);
    //     result_1 = nb_bytes;
    //     printf("renvoie: %ld\n", result_1);
    //     printf("contenu: '%.*s'\n", nb_bytes, buffer_1);
        
    //     printf("---THE READ---\n");
    //     strcpy(buffer_2, argv[2]);
    //     result_2 = nb_bytes;
    //     printf("renvoie: %ld\n", result_2);
    //     printf("contenu: '%.*s'\n", nb_bytes, buffer_2);
    // }

    //ft_strdup.s
    if (argc != 2)
        return(printf("./libasm \"string\"\n"), 1);
    else
    {
        char *result_ft;
        char *result_std;
        
        printf("---MON STRDUP---\n");
        result_ft = ft_strdup(argv[1]);
        printf("original: '%s' (addr: %p)\n", argv[1], argv[1]);
        printf("ft_strdup: '%s' (addr: %p)\n", result_ft, result_ft);
        printf("contenu: %s\n", result_ft);
        printf("adresse : %s\n", result_ft);
        
        printf("---THE STRDUP---\n");
        result_std = strdup(argv[1]);
        printf("original: '%s' (addr: %p)\n", argv[1], argv[1]);
        printf("strdup: '%s' (addr: %p)\n", result_std, result_std);
        printf("contenue : %s\n", result_std);
        printf("adresse : %s\n", result_std);
        
        free(result_ft);
        free(result_std);
    }
    return (0);
}