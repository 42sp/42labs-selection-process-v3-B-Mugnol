/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 19:52:26 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

// Matrix is expected to be NULL terminated.
void	ft_free_char_matrix(char ***m)
{
	size_t	i;

	i = 0;
	while (*(*m + i) != NULL)
	{
		free(*(*m + i));
		*(*m + i) = NULL;
		i++;
	}
	free(*m);
	*m = NULL;
}
