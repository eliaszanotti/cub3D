# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:36:15 by ezanotti          #+#    #+#              #
#    Updated: 2023/03/10 18:00:11 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_SRC		= main.c							\
			${D_GNL}get_next_line.c				\
			${D_GNL}get_next_line_utils.c		\
			${D_PARSE}ft_parse_infos.c			\
			${D_PARSE}ft_parsing.c				\
			${D_PARSE}ft_reset_struct.c			\
			${D_UTILS}ft_error.c				\
			${D_UTILS}ft_is_extension_correct.c	\

S_TMP		= ${addprefix ${D_SRC}, ${S_SRC}}
O_SRC		= $(patsubst %.c, ${D_OBJS}%.o, $(S_TMP))

# VARIABLES
NAME		= cub3D
CC			= cc

# FLAGS
MAKEFLAGS	+= --no-print-directory -s
CFLAGS		= -Wall -Wextra -Werror -g3
LIBFT		= -L ./libft -lft

# COMMANDS
RM			= rm -rf
PRINT		= @printf

# DIRECTORIES
D_OBJS		= .objs/
D_INC		= includes/
D_LIB		= libft/
D_SRC		= srcs/
D_GNL		= gnl/
D_PARSE		= parsing/
D_UTILS		= utils/

# COLORS
C_R			= \033[1;31m
C_G			= \033[1;32m
C_B			= \033[1;34m
C_Y			= \033[1;33m
C_C			= \033[1;36m
C_RST		= \033[0m
C_DEL		= \r\033[2K

all:		${NAME}

${D_OBJS}%.o: %.c	${D_INC}${NAME}.h ${D_INC}get_next_line.h Makefile
			@mkdir		-p $(shell dirname $@)
			@${PRINT}	"${C_Y}${C_DEL}Creating ${NAME}'s objects : $@"
			@${CC}		${CFLAGS} -I ${D_LIB} -I ${D_INC} -c $< -o $@

${NAME}:	ascii lib ${O_SRC}
			@${PRINT}	"${C_G}${C_DEL}Creating ${NAME}'s objects : DONE\n"
			@${PRINT}	"${C_Y}Compiling ${NAME}...${C_RST}"
			@${CC}		${O_SRC} -o ${NAME} ${LIBFT}
			@${PRINT}	"${C_G}${C_DEL}Compiling ${NAME} : DONE ${C_RST}\n\n"

lib:
			@make		-C ./libft

ascii:
			@${PRINT}	"$$ASCII\n"

clean:		ascii
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	clean -C ./libft
			@${PRINT}	"${C_R}Deleting objects : DONE\n"
			@${RM}		${D_OBJS}

fclean:		clean
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	fclean -C ./libft
			@${PRINT}	"${C_R}Deleting executable : DONE${C_RST}\n\n"
			@${RM}		${NAME}

re:			fclean all

define		ASCII
${C_C} _____ _____ _____    ___ ____
|     |  |  | __  |  |_  |    \\
|   --|  |  | __ -|  |_  |  |  |
|_____|_____|_____|  |___|____/
${C_RST}
endef

export		ASCII

.PHONY:		all re clean fclean lib ascii
