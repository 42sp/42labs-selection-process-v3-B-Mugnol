/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:00:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 04:15:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOCOL_H
# define PROTOCOL_H

typedef enum e_protocol
{
	HTTP,
	PING,
	DNS,
	NONE
}	t_protocol;

typedef enum e_http_method
{
	GET,
	POST,
	PUT,
	DELETE,
	PATCH,
	HEAD,
	CONNECT,
	OPTIONS,
	TRACE,
	INVALID
}	t_http_method;

typedef struct s_service
{
	t_protocol	protocol;
	void		*attr;
}	t_service;

typedef struct s_base_config
{
	char		*name;
	char		*address;
	size_t		range;
}	t_base_config;

typedef struct s_http
{
	struct	s_base_config	base_attributes;
	t_http_method			method;
	int						expected_status_code;
}	t_http;

typedef struct s_ping
{
	struct	s_base_config	base_attributes;
}	t_ping;

typedef struct s_dns
{
	struct	s_base_config	base_attributes;
	char					*dns_server;
}	t_dns;

#endif
