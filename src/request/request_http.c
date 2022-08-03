/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_http.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:09:59 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 17:25:06 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "request.h"

static char	*get_http_option(t_http_method method)
{
	if (method == HEAD)
		return (strdup("--head"));
	return (strdup(""));
}

void	request_http(t_http *attr, FILE *outfile)
{
	char	**param;
	int		pid;
	int		pid2;

	pid = fork();
	if (pid != 0)
		return ;
	param = malloc(6 * sizeof(char *));
	param[0] = strdup("/usr/bin/curl");
	param[1] = strdup("curl");
	param[2] = strdup("--silent");
	param[3] = get_http_option(attr->method);
	param[4] = strdup(attr->base_attributes.address);
	param[5] = NULL;
	while (pid++ < MAX_DATA_FETCHS)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			fprintf(outfile, "---> %s\n", attr->base_attributes.name);
			fprintf(outfile, "-> expected status code: %i\n",
				attr->expected_status_code);
			dup2(fileno(outfile), STDOUT_FILENO);
			execve(param[0], param + 1, NULL);
			exit(EXIT_FAILURE);
		}
		sleep(attr->base_attributes.interval);
	}
	ft_free_char_matrix(&param);
}
