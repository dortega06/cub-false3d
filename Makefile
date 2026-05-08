# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 16:46:01 by mcuenca-          #+#    #+#              #
#    Updated: 2026/05/08 19:37:31 by mcuenca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -g
INCS= -Iincludes -Isrcs -I$(LIBFT_DIR) -I$(MLX_DIR) #-fsanitize=address 

LIBFT_DIR=libft
LIBFT= $(LIBFT_DIR)/libft.a
MLX_DIR= minilibx-linux
MLX= minilibx-linux/libmlx.a
LIBS= $(LIBFT) $(MLX) -lXext -lX11 -lm

HEAD= includes/cube3d.h

SRCS_DIR= srcs
SRCS= srcs/main.c \
	  srcs/parse.c \
	  srcs/check_mng.c \
	  srcs/split_gnl_cube.c \
	  srcs/check_cub.c \
	  srcs/check_xpm.c \
	  srcs/content_is_valid.c \
	  srcs/extract_lines.c \
	  srcs/textures_are_valid.c \
	  srcs/colors_are_valid.c \
	  srcs/map_is_valid.c \
	  srcs/rsp.c \
	  srcs/floodfill.c \
	  srcs/execute.c \
	  srcs/moves.c \
	  srcs/texture_utils.c \
	  srcs/events.c \
	  srcs/render.c \
	  srcs/calculate_texture.c \
	  srcs/clean_data_cube.c

OBJS_DIR= objs
OBJS= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

NAME= cube3d

all: libs $(NAME)

libs: $(LIBFT) $(MLX)

$(LIBFT): $(LIBFT_DIR)/Makefile $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/libftprintf.h $(LIBFT_DIR)/gnl.h
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEAD) Makefile
	@mkdir -p $(OBJS_DIR)/
	$(CC) $(CFLAGS) $(INCS) -MMD -c $< -o $@

vpath %.c srcs

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_OBJS)

clean_libs: clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean_libs
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
