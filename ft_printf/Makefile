# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehovhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 20:19:21 by gehovhan          #+#    #+#              #
#    Updated: 2023/02/05 20:19:23 by gehovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
SRC_DIR			= src
OBJ_DIR			= obj
INCS			= -Iinclude
CFLAGS			= -Wall -Wextra -Werror
CC				= cc
MK				= mkdir -p
RM				= rm -rf
SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all:		$(LIB_DIR) $(OBJ_DIR) $(NAME)

$(NAME) :	$(OBJS)
			ar rcs $@ $?

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR): 	$(SRC_DIR)
				$(MK) $(OBJ_DIR)

clean:
			$(RM) $(OBJ_DIR) 
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
