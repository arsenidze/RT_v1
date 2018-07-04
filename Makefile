# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/07/04 11:37:41 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
PWD = $(shell pwd)

CC     = gcc
LD     = $(CC)
DEPEND = makedepend

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = lib
FRM_DIR = frm

#SRC = $(foreach m, $(MODULES), $(wildcard $(m)/*.c))
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/parser/*.c)
_SRC = $(patsubst $(SRC_DIR)/%.c, %.c, $(SRC))
#OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
#OBJ = $(addprefix $(OBJ_DIR)/, $(_SRC))
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

INC = $(INC_DIR)/*.h

LIBFT = $(LIB_DIR)/libft/libft.a
LIBFT_INC = $(LIB_DIR)/libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

SDL_INC =	-I ./lib/Frameworks/SDL2.framework/Headers/
SDL_FLAGS = -F ./lib/Frameworks -framework SDL2

CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -g
HFLAGS = -I $(PWD)/$(INC_DIR) -I $(PWD)/$(LIBFT_INC) $(SDL_INC) 
LFLAGS = $(LIBFT_FLAGS) $(SDL_FLAGS) 
##

#test:
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

depend:
	@echo "make depend"
	@cd $(SRC_DIR); \
	$(DEPEND) -Y -f ../Makefile -p $(OBJ_DIR)/ -- $(HFLAGS) -- $(_SRC); \
	cd ..; \
	rm Makefile.bak

r: all
	./$(NAME) scene1
.PHONY: all clean fclean re depend
