/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:09 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/29 20:45:06 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include "define.h"

int	main(int argc, char **argv)
{
	if (program_param_verifier(argc, argv) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
