/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:09 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/02 23:24:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include "define.h"
#include "cfg.h"

int	main(int argc, char **argv)
{
	FILE	*config_file;
	FILE	*log_file;
	t_list	*service_lst;

	if (program_param_verifier(argc, argv) == -1)
		return (EXIT_FAILURE);
	config_file = infile_opener();
	log_file = outfile_opener();
	if (config_file == NULL || log_file == NULL)
	{
		close_fstream(config_file);
		close_fstream(log_file);
		return (EXIT_FAILURE);
	}
	service_lst = get_service_list(config_file);
	close_fstream(config_file);
	close_fstream(log_file);
	ft_lstclear(&service_lst, delete_service);
	return (EXIT_SUCCESS);
}
