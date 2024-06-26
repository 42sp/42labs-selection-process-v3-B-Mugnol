/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:36:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 04:45:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (strlen(src));
	i = 0;
	while (i < size - 1 && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
