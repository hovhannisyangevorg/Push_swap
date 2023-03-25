# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 21:12:42 by gehovhan          #+#    #+#              #
#    Updated: 2023/03/13 23:32:09 by gehovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard *.c)
OBJS			= $(patsubst %.c, %.o, $(SRCS))
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

.DEFAULT_GOAL	=	all

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME) :		$(OBJS)
				ar rcs $(NAME) $?

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME)

re :			fclean $(NAME)



.PHONY:			all clean fclean re
