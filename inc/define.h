/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:52:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 21:00:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PROTOCOLS	((char const*[]){"HTTP", "PING", "DNS", NULL})

# define HTTP_METHODS	((char const*[]){"GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "CONNECT", "OPTIONS", "TRACE", NULL})

// Allowed flag
# define FLAG	"--simplify"

// Configuration file
# define I_FILE	"monitoring.db"
// Output file
# define O_FILE	"monitoring.log"

// Configurations' separators in configuration file
# define COLUMN_SEPARATOR	"\t"
# define LINE_SEPARATOR		"\n"

/* If one of these is the first character in a line, the subsequent characters will be ignored until the line ends */
# define IGN_LINE_START		"#\n"

#endif
