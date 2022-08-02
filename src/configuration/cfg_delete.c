/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:03:21 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/02 20:40:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include "cfg.h"

void	delete_service(void *service)
{
	if (!service)
		return ;
	if (((t_service *)(service))->protocol == HTTP)
		delete_http_config((t_http *)(((t_service *)(service))->attr));
	else if (((t_service *)(service))->protocol == PING)
		delete_ping_config((t_ping *)(((t_service *)(service))->attr));
	else if (((t_service *)(service))->protocol == DNS)
		delete_dns_config((t_dns *)(((t_service *)(service))->attr));
	free(((t_service *)(service)));
}

void	delete_base_config(t_base_config *config)
{
	if (!config)
		return ;
	if (config->name)
		free(config->name);
	if (config->address)
		free(config->address);
	free(config);
}

void	delete_http_config(t_http *config)
{
	if (!config)
		return ;
	delete_base_config(&config->base_attributes);
	free(config);
}

void	delete_ping_config(t_ping *config)
{
	if (!config)
		return ;
	delete_base_config(&config->base_attributes);
	free(config);
}

void	delete_dns_config(t_dns *config)
{
	if (!config)
		return ;
	delete_base_config(&config->base_attributes);
	if (config->dns_server)
		free(config->dns_server);
	free(config);
}
