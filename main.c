/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:14:16 by mpapin            #+#    #+#             */
/*   Updated: 2025/07/10 08:20:39 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int     ft_strcmp(char *s1, char *s2);

int     main(int argc, char **argv)
{
    //strcmp.s
    if (argc != 3)
        return(printf("./libasm \"s1\" \"s2\" \n"), 1);
    else
        printf("%d", ft_strcmp(argv[1], argv[2]));
    return (0);
}