/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:01:25 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 04:00:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "protocol.h"
# include "ft_lst.h"

// file_handler.c
FILE	*infile_opener(void);
FILE	*outfile_opener(void);
int		close_fstream(FILE *file);

// verifier.c
int	program_param_verifier(int argc, char **argv);
int	generic_error(int err_code, char *err_msg);

#endif
