# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/07/05 16:29:09 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

CC     = gcc
LD     = $(CC)

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = lib

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

INC = $(INC_DIR)/*.h

LIBFT = $(LIB_DIR)/libft/libft.a
LIBFT_INC = $(LIB_DIR)/libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

SDL_INC =	-I ./lib/Frameworks/SDL2.framework/Headers/
SDL_FLAGS = -F ./lib/Frameworks -framework SDL2

CFLAGS = -Wall -Wextra -Werror -g
HFLAGS = -I $(PWD)/$(INC_DIR) -I $(PWD)/$(LIBFT_INC) $(SDL_INC) 
LFLAGS = $(LIBFT_FLAGS) $(SDL_FLAGS) 

#testO:
#	$(OBJ)
#
#testS:
#	$(SRC)

all:
	make -C $(LIB_DIR)/libft/
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(LD) $(OBJ) $(LFLAGS) -rpath ./lib/Frameworks -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INC)
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIB_DIR)/libft/

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)/libft/

re: fclean all

r: all
	./$(NAME) scene1
.PHONY: all clean fclean re depend
