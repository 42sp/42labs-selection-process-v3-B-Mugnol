/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:07:31 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 22:07:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	count_digits(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	char	*s;
	int		digit_count;

	digit_count = count_digits(n);
	s = malloc(sizeof(char) * (digit_count + 1));
	if (!s)
		return (NULL);
	*(s + digit_count) = '\0';
	while (digit_count > 0)
	{
		*(s + digit_count - 1) = n % 10 + '0';
		n /= 10;
		digit_count--;
	}
	return (s);
}

static int	count_digits(unsigned int n)
{
	int	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	while (n != 0)
	{
		n /= 10;
		digit_count++;
	}
	return (digit_count);
}
