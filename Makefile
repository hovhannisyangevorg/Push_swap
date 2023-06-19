# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 18:45:31 by gehovhan          #+#    #+#              #
#    Updated: 2023/06/19 22:02:29 by gehovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER			= checker
INC_DIR			= include
SRC_DIR			= src
MAIN_DIR		= main
OBJ_DIRS		= obj obj/checker obj/main
OBJ_DIR			= obj
FT_LIB			= libft
LIBS			= $(FT_LIB)/libft.a
LINKERS			= -L$(FT_LIB) -lft
ALL_SRCS		= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard $(INC_DIR)/*.h)
CHECK_SRCS		= $(filter-out $(SRC_DIR)/main.c, $(ALL_SRCS))
MAIN_SRCS		= $(filter-out $(SRC_DIR)/ft_checker.c, $(ALL_SRCS))
INCS			= -I$(INC_DIR) -I$(FT_LIB)/include
CFLAGS			= -Wall -Wextra -Werror 
CC				= cc
MK				= mkdir -p
RM				= rm -rf
MAIN_OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/$(MAIN_DIR)/%.o, $(MAIN_SRCS))
CHECK_OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/$(CHECKER)/%.o, $(CHECK_SRCS))

all:		$(LIBS) $(OBJ_DIRS) $(NAME)

bonus:		$(LIBS) $(OBJ_DIRS) $(CHECKER)

$(NAME):	$(MAIN_OBJS)
			$(CC) $(CFLAGS) $(INCS) -o $@ $(MAIN_OBJS) $(LINKERS)

$(CHECKER):	$(CHECK_OBJS)
			$(CC) $(CFLAGS) $(INCS) -DISCHECKER -o $@ $(CHECK_OBJS) $(LINKERS)

$(FT_LIB)/libft.a:
	$(MAKE) -C $(FT_LIB)

$(OBJ_DIR)/$(CHECKER): $(SRC_DIR)
	$(MK) $@
	
$(OBJ_DIR)/$(MAIN_DIR): $(SRC_DIR)
	$(MK) $@

$(OBJ_DIR)/$(MAIN_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)/$(CHECKER)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -DISCHECKER -c $< -o $@

$(OBJ_DIR): 	$(SRC_DIR)
				$(MK) $(OBJ_DIR)

clean:
			$(RM) $(OBJ_DIR)
			$(MAKE) -C $(FT_LIB) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(CHECKER)
			$(MAKE) -C $(FT_LIB) fclean

re:			fclean all bonus

.PHONY: all clean fclean re bonus

.SILENT:
