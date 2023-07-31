/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:42:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:54:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strnjoin_gnl(char *s1, const char *s2, size_t n_from_s2_to_cpy);
char	*ft_strchr_gnl(const char *s);

#endif
