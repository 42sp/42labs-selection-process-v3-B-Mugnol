/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:49:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 17:10:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "request.h"

void	request(t_list *config_lst, FILE *outfile)
{
	while (config_lst)
	{
		if (((t_service *)(config_lst->content))->protocol == HTTP)
			request_http(((t_service *)(config_lst->content))->attr, outfile);
		// else if (((t_service *)(config_lst->content))->protocol == PING)
		// 	request_ping(((t_service *)(config_lst->content))->attr, outfile);
		// else if (((t_service *)(config_lst->content))->protocol == DNS)
		// 	request_dns(((t_service *)(config_lst->content))->attr, outfile);
		config_lst = config_lst->next;
	}
}
