# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 15:00:17 by rcarmen           #+#    #+#              #
#    Updated: 2022/02/01 03:26:58 by rcarmen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -O3

SRC = main.c scan_map.c error.c free.c bresenham.c mlx.c render_frame.c hook.c rotation.c libfuncs3.c libfuncs2.c libfuncs1.c ft_split.c
OBJ = $(patsubst %.c, %.o, $(SRC))

SRC_DIR = src
OBJ_DIR = $(SRC_DIR)/
INC_DIR = include src/libft/inc mlx_linux

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBS = mlx_linux/libmlx.a -lX11 -lXext -Lincludes/MiniLib/ -lm 

BIN = bin/

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@$(MAKE) -C mlx_linux/
	$(CC) -Lmlx -L/usr/lib -Imlx $(addprefix -I, $(INC_DIR)) $(OBJ) $(LIBS) -lz -o $(NAME)

VPATH = src

%.o: %.c
	$(CC) -I/usr/include $(DEBUG) $(addprefix -I, $(INC_DIR)) -Imlx_linux -O3 -g -c $< -o $@

co:
	rm -rf $(OBJ) $(NAME)

clean:
	@-rm -f $(OBJ)
	@$(MAKE) clean -C mlx_linux

fclean: clean
	@rm -rf $(NAME)

re: fclean all
