/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:16:25 by sebonie           #+#    #+#             */
/*   Updated: 2021/10/13 18:16:25 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	256
# endif

int		ft_strlen_bonus(const char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
int		free_buff(int read_res, char *buff);
char	*get_next_line(int fd);

#endif