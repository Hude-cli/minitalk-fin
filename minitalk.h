/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugde-cl <hugde-cl@student.s42.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:06:14 by hugde-cl          #+#    #+#             */
/*   Updated: 2023/05/16 19:08:06 by hugde-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putnbr(int nbr, int baselen, char *base);
void	ft_error(char *str);
int		ft_atoi(const char *str);

#endif
