/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugde-cl <hugde-cl@student.s42.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:06:23 by hugde-cl          #+#    #+#             */
/*   Updated: 2023/05/16 19:09:43 by hugde-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr, int baselen, char *base)
{
	if (nbr >= baselen)
		ft_putnbr(nbr / baselen, baselen, base);
	write(1, &base[nbr % baselen], 1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nbr = nbr * 10 + *str - 48;
		else
			return (nbr * sign);
		str++;
	}
	return (nbr * sign);
}

void	ft_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	exit(EXIT_FAILURE);
}
