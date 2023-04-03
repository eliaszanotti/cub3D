# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: thibaultgiraudon <thibaultgiraudon@stud	+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2023/03/10 12:36:15 by ezanotti		  #+#	#+#			  #
#	Updated: 2023/03/31 18:55:30 by thibaultgir	  ###   ########.fr		#
#																			  #
# **************************************************************************** #

OS			= $(shell uname -s)

ifeq ($(OS), Linux)
	D_LMLX	= mlx/
	MLX	=	-Lmlx -lmlx -lXext -lX11 -lm
endif
ifeq ($(OS), Darwin)
	D_LMLX	= mlx_mac/
	MLX	=	-Lmlx_mac -lmlx -framework OpenGL -framework AppKit
endif

S_SRC		= main.c							\
			${D_GNL}get_next_line.c				\
			${D_GNL}get_next_line_utils.c		\
												\
			${D_MLX}ft_create_img.c				\
			${D_MLX}ft_draw_line.c				\
			${D_MLX}ft_get_color.c				\
			${D_MLX}ft_init_window.c			\
			${D_MLX}ft_mlx_pixel_put.c			\
			${D_MLX}ft_print_colors.c			\
			${D_MLX}ft_print_cross.c			\
			${D_MLX}ft_print_minimap.c			\
			${D_MLX}ft_put_player.c				\
			${D_MLX}ft_put_square.c				\
												\
			${D_PARSE}ft_check_walls.c			\
			${D_PARSE}ft_convert_list.c			\
			${D_PARSE}ft_fill_map.c				\
			${D_PARSE}ft_is_valid_map.c			\
			${D_PARSE}ft_parse_infos.c			\
			${D_PARSE}ft_parse_map.c			\
			${D_PARSE}ft_parsing.c				\
			${D_PARSE}ft_reset_struct.c			\
												\
			${D_RAY}ft_calculate_positions.c	\
			${D_RAY}ft_calculate_side_dist.c	\
			${D_RAY}ft_init_ray.c				\
			${D_RAY}ft_init_textures.c			\
			${D_RAY}ft_init_values.c			\
			${D_RAY}ft_loop.c					\
			${D_RAY}ft_move.c					\
			${D_RAY}ft_raycasting.c				\
			${D_RAY}ft_throw_ray.c				\
												\
			${D_UTILS}ft_error.c				\
			${D_UTILS}ft_free.c					\
			${D_UTILS}ft_hooks.c				\
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
D_MLX		= mlx/
D_RAY		= raycasting/

# COLORS
C_R			= \033[1;31m
C_G			= \033[1;32m
C_B			= \033[1;34m
C_Y			= \033[1;33m
C_C			= \033[1;36m
C_RST		= \033[0m
C_DEL		= \r\033[2K

all:		${NAME}

${D_OBJS}%.o: %.c		${D_MLX}mlx.h ${D_INC}${NAME}.h ${D_INC}get_next_line.h Makefile
			@mkdir		-p $(shell dirname $@)
			@${PRINT}	"${C_Y}${C_DEL}Creating ${NAME}'s objects : $@"
			@${CC}		${CFLAGS} -I${D_LMLX} -I${D_LIB} -I${D_INC} -c $< -o $@

${NAME}:	ascii mlx lib ${O_SRC}
			@${PRINT}	"${C_G}${C_DEL}Creating ${NAME}'s objects : DONE\n"
			@${PRINT}	"${C_Y}Compiling ${NAME}...${C_RST}"
			@${CC}		-fsanitize=address ${O_SRC} -o ${NAME} ${LIBFT} ${MLX}
			@${PRINT}	"${C_G}${C_DEL}Compiling ${NAME} : DONE ${C_RST}\n\n"

lib:
			@${MAKE}	-C ./libft

mlx:
			@${MAKE}	-C ${D_LMLX}
			@${PRINT}	"${C_G}${C_DEL}\nCompiling MLX : DONE\n${C_RST}"

ascii:
			@${PRINT}	"$$ASCII\n"

clean:		ascii
			@${MAKE}	clean -C ./mlx
			@${PRINT}	"${C_R}${C_DEL}\nCleaning MLX : DONE\n"
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
${C_C} _____ _____ _____	___ ____
|	 |  |  | __  |  |_  |	\\
|   --|  |  | __ -|  |_  |  |  |
|_____|_____|_____|  |___|____/
${C_RST}
endef

export		ASCII

.PHONY:		all re clean fclean lib mlx ascii
