# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 12:46:32 by mcuenca-          #+#    #+#              #
#    Updated: 2026/04/02 19:14:57 by mcuenca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_isspace.c\
	   \
	   ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_free.c ft_realloc.c\
	   \
	   ft_atoi.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c \
	   ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	   \
	   ft_itoa.c ft_count.c ft_array_w_max-min.c\
       \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   \
	   ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	   ft_lstiter.c ft_lsthead.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	   ft_lstwrite.c\
	   \
	   ft_printf.c print_c.c print_s.c print_p.c print_d.c print_u.c print_x.c \
	   \
	   gnl.c gnl_utils.c read_gnl_content.c
DIR_OBJ = objs
OBJS = $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o))) #$(SRCS:.c=.o)
HEADER = libft.h libftprintf.h gnl.h 
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(DIR_OBJ)/ #if [ ! -d $(DIR_OBJ) ]; then mkdir -p $(DIR_OBJ)/; fi # '-p'  ya comprueva si el directorio existe y no hará nada si ya existe, si no, pues lo creara
	$(CC) $(CFLAGS) -c $< -o $@ 

vpath %.c is mem print print/print_srcs put str num lst gnl

clean:
	rm -f $(OBJS)
	if [ -d $(DIR_OBJ) ]; then rm -d $(DIR_OBJ); fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean all

