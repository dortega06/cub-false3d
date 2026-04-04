# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 16:46:01 by mcuenca-          #+#    #+#              #
#    Updated: 2026/04/04 20:39:38 by mcuenca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -Iincludes -Isrcs -Ilibft -Iminilibx-linux -g

LIBFT_DIR=libft
LIBFT= libft/libft.a
MLX_DIR= minilibx-linux
MLX= minilibx-linux/libmlx.a
LIBS= $(LIBFT) $(MLX) -lXext -lX11 -lm

HEAD= includes/cube3d.h

SRCS_DIR= srcs
SRCS= srcs/main.c \
	  srcs/parse.c \
	  srcs/extension.c \
	  srcs/check_cub_extension.c \
	  srcs/check_xpm_extension.c \
	  srcs/clean_data_cube.c \
	  srcs/content_is_valid.c \
	  srcs/textures_are_valid.c

OBJS_DIR= objs
OBJS= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

NAME= cube3d

all: $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libs: $(LIBFT) $(MLX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEAD) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

vpath %.c is mem print print/print_srcs put str num lst gnl

clean:
	$(MAKE) -C  $(LIBFT_DIR) clean
	$(MAKE) -C  $(MLX_DIR) clean
	rm -f $(OBJS)
	if [ -d $(OBJS_DIR) ]; then rm -drf $(OBJS_DIR); fi

fclean: clean
	$(MAKE) -C  $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
