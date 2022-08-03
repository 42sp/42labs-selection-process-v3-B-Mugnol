/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:01:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 17:17:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_H
# define REQUEST_H

#include "utilities.h"
#include "protocol.h"
#include "define.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// request.c
void	request(t_list *config_lst, FILE *outfile);

// request_http.c
void	request_http(t_http *attr, FILE *outfile);

#endif
