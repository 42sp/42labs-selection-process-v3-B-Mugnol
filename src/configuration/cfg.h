/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:49:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 18:06:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H

# include "protocol.h"

// cfg_get.c
t_service	*get_service(char *line, size_t line_number);

// cfg_create.c
t_http	*create_http(char **config);
t_ping	*create_ping(char **config);
t_dns	*create_dns(char **config);

// cfg_delete.c
void	delete_service(void *service);
void	delete_base_config(t_base_config *config);
void	delete_http_config(t_http *config);
void	delete_ping_config(t_ping *config);
void	delete_dns_config(t_dns *config);

#endif
