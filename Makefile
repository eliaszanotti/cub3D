# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elias <elias@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 14:43:07 by elias             #+#    #+#              #
#    Updated: 2023/06/29 16:41:25 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname -s)

D_MLX		= minilibx/
ifeq ($(OS), Linux)
	D_LMLX	= ${D_MLX}linux/
	MLX		= -L${D_LMLX} -lmlx -lXext -lX11 -lm
endif
ifeq ($(OS), Darwin)
	D_LMLX	= ${D_MLX}mac/
	MLX		= -L${D_LMLX} -lmlx -framework OpenGL -framework AppKit
endif

S_SRC		= main.c									\
			${D_MLX}ft_create_img.c						\
			${D_MLX}ft_get_color.c						\
			${D_MLX}ft_init_window.c					\
			${D_MLX}ft_mlx_pixel_put.c					\
			${D_MLX}ft_print_line.c						\
			${D_MLX}ft_put_square.c						\
			\
			${D_PARSE}${D_MAP}ft_check_walls.c			\
			${D_PARSE}${D_MAP}ft_convert_list.c			\
			${D_PARSE}${D_MAP}ft_fill_map.c				\
			${D_PARSE}${D_MAP}ft_is_valid_map.c			\
			${D_PARSE}${D_FD}ft_get_infos.c				\
			${D_PARSE}${D_FD}ft_get_map.c				\
			${D_PARSE}${D_FD}ft_parse_colors.c			\
			${D_PARSE}ft_parsing.c						\
			\
			${D_RAY}${D_INIT}ft_init_ray.c				\
			${D_RAY}${D_INIT}ft_init_textures.c			\
			${D_RAY}${D_LOOP}ft_calculate_positions.c	\
			${D_RAY}${D_LOOP}ft_calculate_side_dist.c	\
			${D_RAY}${D_LOOP}ft_draw_line.c				\
			${D_RAY}${D_LOOP}ft_init_values.c			\
			${D_RAY}${D_LOOP}ft_loop.c					\
			${D_RAY}${D_LOOP}ft_pause.c					\
			${D_RAY}${D_LOOP}ft_print_cross.c			\
			${D_RAY}${D_LOOP}ft_print_flashlight.c		\
			${D_RAY}${D_LOOP}ft_print_minimap.c			\
			${D_RAY}${D_LOOP}ft_throw_ray.c				\
			${D_RAY}${D_MOVE}ft_move.c					\
			${D_RAY}${D_MOVE}ft_turn.c					\
			${D_RAY}ft_raycasting.c						\
			\
			${D_UTILS}ft_check.c						\
			${D_UTILS}ft_open_xpm.c						\
			${D_UTILS}ft_error.c						\
			${D_UTILS}ft_exit.c							\
			${D_UTILS}ft_free.c							\
			${D_UTILS}ft_hooks.c						\
			${D_UTILS}ft_is_correct_extension.c			\
			${D_UTILS}ft_reduce_opacity.c				\
			${D_UTILS}ft_reset_struct.c					\

HDRS_LIST	= cub3D.h	\

S_TMP		= ${addprefix ${D_SRC}, ${S_SRC}}
O_SRC		= $(patsubst %.c, ${D_OBJS}%.o, $(S_TMP))
HDRS		= ${addprefix ${D_INCLUDES}, ${HDRS_LIST}}

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
D_INCLUDES	= includes/
D_LIB		= libft/includes/
D_SRC		= srcs/
D_PARSE		= parsing/
D_FD		= fd/
D_MAP		= map/
D_UTILS		= utils/
D_RAY		= raycasting/
D_INIT		= init/
D_LOOP		= loop/
D_MOVE		= move/

# COLORS
C_R			= \033[1;31m
C_G			= \033[1;32m
C_B			= \033[1;34m
C_Y			= \033[1;33m
C_C			= \033[1;36m
C_RST		= \033[0m
C_DEL		= \r\033[2K

all:		ascii	\
			lib		\
			mlx		\
			${NAME}

${D_OBJS}%.o: %.c		${D_LMLX}mlx.h ${HDRS} Makefile
			@mkdir		-p $(shell dirname $@)
			@${PRINT}	"${C_Y}${C_DEL}Creating ${NAME}'s objects : $@"
			@${CC}		${CFLAGS} -I${D_LMLX} -I${D_LIB} -I${D_INCLUDES} -O3 -c $< -o $@

${NAME}:	${O_SRC}
			@${PRINT}	"${C_G}${C_DEL}Creating ${NAME}'s objects : DONE\n"
			@${PRINT}	"${C_Y}Compiling ${NAME}...${C_RST}"
			@${CC}		-fsanitize=address ${O_SRC} -o ${NAME} ${LIBFT} ${MLX}
			@${PRINT}	"${C_G}${C_DEL}Compiling ${NAME} : DONE ${C_RST}\n"

lib:
			@${MAKE}	-C ./libft

mlx:
			@${MAKE}	-C ./${D_LMLX}
			@${PRINT}	"${C_G}${C_DEL}\nCompiling MLX : DONE\n${C_RST}"

ascii:
			@${PRINT}	"$$ASCII\n"

clean:
			@${MAKE}	clean -C ./${D_LMLX}
			@${PRINT}	"${C_R}${C_DEL}Cleaning MLX : DONE\n"
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	clean -C ./libft
			@${PRINT}	"${C_R}Deleting objects : DONE\n"
			@${RM}		${D_OBJS}

fclean:		clean
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	fclean -C ./libft
			@${PRINT}	"${C_R}Deleting executable : DONE${C_RST}\n"
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

.PHONY:		all re clean fclean lib mlx ascii
