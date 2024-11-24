/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:03:09 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/11/24 18:50:05 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define TITLE_ANSI "\x1b[1;34m"  // Bold and dark blue
#define GREEN_ANSI  "\x1b[32m"
#define RED_ANSI    "\x1b[31m"
#define NC_ANSI     "\x1b[0m"

#define BUFFER_SIZE 1000


int			ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(unsigned int fd, const char *str, size_t len);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(const char *s);