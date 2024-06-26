/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:25:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 18:12:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfg.h"
#include "utilities.h"
#include "define.h"

static t_protocol	get_protocol(char *protocol);
static void			get_attributes(char **config, t_service *svc);

t_service	*get_service(char *line, size_t line_number)
{
	t_service	*service;
	char		**config_str;

	if (!line || !*line || strchr(IGN_LINE_START, *line))
		return (NULL);
	config_str = ft_split(line, '\t');
	if (config_str == NULL || config_str[0] == NULL || config_str[1] == NULL)
	{
		fprintf(stderr, "Wrong configuration format at line:	%lu\n",
			line_number);
		ft_free_char_matrix(&config_str);
		return (NULL);
	}
	service = malloc(sizeof(t_service));
	service->protocol = get_protocol(config_str[1]);
	get_attributes(config_str, service);
	if (service->protocol == NONE || service->attr == NULL)
	{
		fprintf(stderr, "line:	%lu:	Invalid value\n", line_number);
		free(service);
		service = NULL;
	}
	ft_free_char_matrix(&config_str);
	return (service);
}

static t_protocol	get_protocol(char *protocol)
{
	t_protocol	prtcl;

	prtcl = HTTP;
	while (PROTOCOLS[prtcl] && prtcl != NONE)
	{
		if (strcmp(protocol, PROTOCOLS[prtcl]) == 0)
			break ;
		prtcl++;
	}
	return (prtcl);
}

static void	get_attributes(char **config, t_service *svc)
{
	if (svc->protocol == NONE)
		svc->attr = NULL;
	else if (svc->protocol == HTTP)
		svc->attr = (void *)(create_http(config));
	else if (svc->protocol == PING)
		svc->attr = (void *)(create_ping(config));
	else if (svc->protocol == DNS)
		svc->attr = (void *)(create_dns(config));
}
