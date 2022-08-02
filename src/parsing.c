/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:08:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/02 23:19:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include "define.h"
#include "cfg.h"

static void	add_service_to_list(t_list **config_lst, char *line,
				size_t line_number, size_t allocated);

t_list	*get_service_list(FILE *infile)
{
	char	*line;
	size_t	line_number;
	size_t	allocated;
	ssize_t	chars_read;
	t_list	*config_lst;

	line_number = 0;
	config_lst = NULL;
	allocated = 1;
	while (allocated != 0)
	{
		line = NULL;
		line_number++;
		chars_read = getline(&line, &allocated, infile);
		if (chars_read == -1)
		{
			free(line);
			break ;
		}
		add_service_to_list(&config_lst, line, line_number, allocated);
		free(line);
	}
	return (config_lst);
}

static void	add_service_to_list(t_list **config_lst, char *line,
				size_t line_number, size_t allocated)
{
	t_service	*service;

	if (allocated == 0)
		return ;
	service = get_service(line, line_number);
	if (service == NULL)
		return ;
	ft_lstadd_back(config_lst, ft_lstnew(service));
}
