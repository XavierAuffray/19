/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:07:20 by xauffray          #+#    #+#             */
/*   Updated: 2021/05/10 09:38:25 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len, int to_free);
char	*ft_strdup(char *str, char *yes, int to_free, int again);
char	*ft_strjoin(const char *s1, char const *s2, int *y);

#endif
