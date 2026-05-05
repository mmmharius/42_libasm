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
#include <errno.h>

int     ft_strcmp(const char *s1, const char *s2);
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *restrict dst, const char *restrict src);
ssize_t ft_write(int fd, char *buf, int nbyte);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

int     main()
{
    char    *ex_str = "exemple";
    char    *ex_str1 = "exemple1";
    char    ex_buf[strlen(ex_str)];
    char    ex_buff[strlen(ex_str)];
    char    buf_ft[64];
    char    buf_std[64];
    char    *result_ft;
    char    *result_std;
    int     err;
    int     pipefd_ft[2];
    int     pipefd_std[2];
    ssize_t ret;

    printf("ft_strlen.s\n");
    printf("my strlen : %zu\n", ft_strlen(ex_str));
    printf("the strlen : %ld\n\n", strlen(ex_str));

    printf("ft_strcpy.s\n");
    printf("my strcpy return : %s\n", ft_strcpy(ex_buf, ex_str));
    printf("the strcpy return : %s\n", strcpy(ex_buff, ex_str));

    printf("ft_strcmp.s\n");
    printf("my strcmp : %d\n", ft_strcmp(ex_str, ex_str1));
    printf("the strcmp : %d\n\n", strcmp(ex_str, ex_str1));

    printf("ft_write.s\n");
    printf("my write: %ld\n", ft_write(1, ex_str, strlen(ex_str)));
    printf("the write: %ld\n", write(1, ex_str, strlen(ex_str)));
    printf("ft_write.s errno test :\n");
    errno = 0;
    ret = ft_write(-1, ex_str, 5);
    err = errno;
    printf("my write (fd=-1): ret=%ld, errno=%d\n", ret, err);
    errno = 0;
    ret = write(-1, ex_str, 5);
    err = errno;
    printf("the write (fd=-1): ret=%ld, errno=%d\n\n", ret, err);

    printf("ft_read.s\n");
    memset(buf_ft, 0, 64);
    memset(buf_std, 0, 64);
    pipe(pipefd_ft);
    write(pipefd_ft[1], "hello pipe\n", 11);
    close(pipefd_ft[1]);
    ret = ft_read(pipefd_ft[0], buf_ft, 11);
    close(pipefd_ft[0]);
    printf("my read: ret=%ld, content='%s'\n", ret, buf_ft);
    pipe(pipefd_std);
    write(pipefd_std[1], "hello pipe\n", 11);
    close(pipefd_std[1]);
    ret = read(pipefd_std[0], buf_std, 11);
    close(pipefd_std[0]);
    printf("the read: ret=%ld, content='%s'\n", ret, buf_std);
    printf("ft_read.s errno test :\n");
    errno = 0;
    ret = ft_read(-1, buf_ft, 5);
    err = errno;
    printf("my read (fd=-1): ret=%ld, errno=%d\n", ret, err);
    errno = 0;
    ret = read(-1, buf_std, 5);
    err = errno;
    printf("the read (fd=-1): ret=%ld, errno=%d\n\n", ret, err);

    printf("ft_strdup.s\n");
    result_ft = ft_strdup(ex_str);
    result_std = strdup(ex_str);
    printf("my strdup: '%s' (addr: %p)\n", result_ft, (void *)result_ft);
    printf("the strdup: '%s' (addr: %p)\n", result_std, (void *)result_std);
    free(result_ft);
    free(result_std);

    return (0);
}