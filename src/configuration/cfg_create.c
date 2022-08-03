/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:20:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 18:06:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfg.h"
#include "utilities.h"
#include <stdio.h>

static t_http_method	get_http_method(char *method);

t_http	*create_http(char **config)
{
	t_http	*attr;

	if (count_lines(config) != 6)
	{
		if (count_lines(config) > 6)
			fprintf(stderr, "col:	6");
		else if (count_lines(config) < 6)
			fprintf(stderr, "col:	%lu", count_lines(config));
		return (NULL);
	}
	attr = malloc(sizeof(t_http));
	attr->base_attributes.name = strdup(config[0]);
	attr->base_attributes.address = strdup(config[2]);
	attr->method = get_http_method(config[3]);
	attr->expected_status_code = atoi(config[4]);
	strtok(config[5], "\n");
	attr->base_attributes.interval = strtoul(config[5], NULL, 10);
	if (
		attr->expected_status_code < 100 || attr->expected_status_code >= 600
		|| !is_digit_str(config[4]) || !is_digit_str(config[5]))
	{
		delete_http_config(attr);
		attr = NULL;
	}
	return (attr);
}

t_ping	*create_ping(char **config)
{
	t_ping	*attr;

	if (count_lines(config) != 4)
	{
		if (count_lines(config) > 4)
			fprintf(stderr, "col:	4");
		else if (count_lines(config) < 4)
			fprintf(stderr, "col:	%lu", count_lines(config));
		return (NULL);
	}
	attr = malloc(sizeof(t_ping));
	attr->base_attributes.name = strdup(config[0]);
	attr->base_attributes.address = strdup(config[2]);
	strtok(config[3], "\n");
	attr->base_attributes.interval = strtoul(config[3], NULL, 10);
	if (!is_digit_str(config[3]))
	{
		delete_ping_config(attr);
		attr = NULL;
	}
	return (attr);
}

t_dns	*create_dns(char **config)
{
	t_dns	*attr;

	if (count_lines(config) != 5)
	{
		if (count_lines(config) > 5)
			fprintf(stderr, "col:	5");
		else if (count_lines(config) < 5)
			fprintf(stderr, "col:	%lu", count_lines(config));
		return (NULL);
	}
	attr = malloc(sizeof(t_dns));
	attr->base_attributes.name = strdup(config[0]);
	attr->base_attributes.address = strdup(config[2]);
	attr->base_attributes.interval = strtoul(config[3], NULL, 10);
	strtok(config[4], "\n");
	attr->dns_server = strdup(config[4]);
	if (!is_digit_str(config[3]))
	{
		delete_dns_config(attr);
		attr = NULL;
	}
	return (attr);
}

static t_http_method	get_http_method(char *method)
{
	t_http_method	mtd;

	if (!method || !*method)
		return (INVALID);
	mtd = GET;
	while (HTTP_METHODS[mtd] && mtd != INVALID)
	{
		if (strcmp(method, HTTP_METHODS[mtd]) == 0)
			break ;
		mtd++;
	}
	return (mtd);
}
