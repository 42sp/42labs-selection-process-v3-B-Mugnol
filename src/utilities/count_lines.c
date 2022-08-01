/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:49:14 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 21:49:22 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t	count_lines(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}
