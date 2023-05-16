# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugde-cl <hugde-cl@student.s42.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 19:06:35 by hugde-cl          #+#    #+#              #
#    Updated: 2023/05/16 19:07:49 by hugde-cl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= server
NAME_CLT	= client

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS_CLT	= client.c utils.c
SRCS_SRV	= server.c utils.c

# OBJS_CLT	= ft_client.o ft_atoi.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_strlen.o
# OBJS_SRV	= ft_server.o ft_atoi.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_strlen.o

all: $(NAME) $(NAME_CLT)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS_SRV) -o $(NAME)
$(NAME_CLT):
	$(CC) $(CFLAGS) $(SRCS_CLT) -o $(NAME_CLT)

clean:
	rm -rf $(OBJS_CLT) $(OBJS_SRV)

fclean: clean
	rm -f $(NAME) $(NAME_CLT)

re: fclean all

.PHONY: all clean fclean re
