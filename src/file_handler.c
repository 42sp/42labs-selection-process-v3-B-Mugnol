/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:16:21 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 00:10:44 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include <stdio.h>
#include <stdlib.h>

FILE	*infile_opener(void)
{
	FILE	*f_stream;

	f_stream = fopen(I_FILE, "r");
	if (f_stream == NULL)
		perror("fopen");
	return (f_stream);
}

FILE	*outfile_opener(void)
{
	FILE	*f_stream;

	f_stream = fopen(O_FILE, "a+");
	if (f_stream == NULL)
		perror("fopen");
	return (f_stream);
}

int	close_fstream(FILE *file)
{
	if (file != NULL && fclose(file) != 0)
	{
		perror("fclose");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
