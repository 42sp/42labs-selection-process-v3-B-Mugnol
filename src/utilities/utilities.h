/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:37:48 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 22:13:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

#include <stdlib.h>
#include <string.h>

size_t	count_lines(char **matrix);
void	ft_free_char_matrix(char ***m);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_utoa(unsigned int n);

#endif
