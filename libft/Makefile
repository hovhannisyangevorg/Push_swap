# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 21:12:42 by gehovhan          #+#    #+#              #
#    Updated: 2023/04/13 19:16:45 by gehovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= src
OBJ_DIR			= obj
INC_DIR			= include
SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard $(INC_DIR)/*.h)
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
CC				= cc
RM				= rm -rf
INCS			= -I$(INC_DIR)
CFLAGS			= -Wall -Wextra -Werror 
AR				= ar rcs 
NAME			= libft.a
MK				= mkdir -p

.DEFAULT_GOAL	=	all

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $@

all:		$(OBJ_DIR)	$(NAME)

$(NAME):	$(OBJS)
				$(AR) $(NAME) $?

clean:
				$(RM) $(OBJ_DIR)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all



.PHONY:			all clean fclean re
