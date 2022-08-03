/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:52:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/03 16:39:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Allowed flag
# define FLAG	"--simplify"

// FILES
// Configuration file
# define I_FILE	"monitoring.db"
// Output file
# define O_FILE	"monitoring.log"
// Separators in configuration file
# define COLUMN_SEPARATOR	"\t"
# define LINE_SEPARATOR		"\n"
/* If one of these is the first character in a line, the subsequent characters will be ignored until the line ends */
# define IGN_LINE_START		"#\n"

#endif
