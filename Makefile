# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 18:45:31 by gehovhan          #+#    #+#              #
#    Updated: 2023/04/12 16:56:24 by gehovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

FT_LIB			= libft
PRINTF_LIB		= ft_printf
LIBS			= $(FT_LIB)/libft.a $(PRINTF_LIB)/libprintf.a
LINKERS			= -L$(FT_LIB) -lft -L$(PRINTF_LIB) -lftprintf
SRC_DIR			= src
OBJ_DIR			= obj
INCS			= -Iinclude -I$(FT_LIB) -I$(PRINTF_LIB)/include
CFLAGS			= -Wall -Wextra -Werror 
CC				= cc
MK				= mkdir -p
RM				= rm -rf
SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all:		$(LIBS) $(OBJ_DIR) $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS) $(LINKERS)


$(FT_LIB)/libft.a:
	$(MAKE) -C $(FT_LIB)

$(PRINTF_LIB)/libprintf.a:
	$(MAKE) -C $(PRINTF_LIB)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR): 	$(SRC_DIR)
				$(MK) $(OBJ_DIR)

clean:
			$(RM) $(OBJ_DIR)
			$(MAKE) -C $(FT_LIB) clean
			$(MAKE) -C $(PRINTF_LIB) clean
fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(FT_LIB) fclean
			$(MAKE) -C $(PRINTF_LIB) fclean

re:			fclean all

.PHONY: all clean fclean re

.SILENT:
