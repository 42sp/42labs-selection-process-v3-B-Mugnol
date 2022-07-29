/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:28:56 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/29 20:33:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include "define.h"

int	program_param_verifier(int argc, char **argv)
{
	int	status;

	status = 0;
	if (argc > 2)
		status = generic_error(EINVAL, argv[0]);
	if (argc == 2 && strcmp(FLAG, argv[argc - 1]) != 0)
		status = generic_error(EINVAL, argv[0]);
	if (status != 0)
		fprintf(stderr, "Usage: %s [--simplify]\n", argv[0]);
	return (status);
}

int	generic_error(int err_code, char *err_msg)
{
	if (err_code == 0)
		perror(err_msg);
	else if (err_msg)
		fprintf(stderr, "%s: %s\n", err_msg, strerror(err_code));
	else
		fprintf(stderr, "%s\n", strerror(err_code));
	return (-1);
}
