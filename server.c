/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugde-cl <hugde-cl@student.s42.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:06:20 by hugde-cl          #+#    #+#             */
/*   Updated: 2023/05/16 19:09:46 by hugde-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	result;
	static int				bit_position;

	(void)ucontext;
	kill(info->si_pid, SIGUSR1);
	result += (sig == SIGUSR1) << bit_position;
	bit_position++;
	if (bit_position > CHAR_BIT - 1)
	{
		if (result)
			write(1, &result, 1);
		bit_position = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	ft_putnbr(getpid(), 10, "0123456789");
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (19)
		pause();
	return (0);
}
