# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/05/14 17:27:24 by amelihov         ###   ########.fr        #
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

SRC = $(wildcard $(SRC_DIR)/*.c)
_SRC = $(patsubst $(SRC_DIR)/%.c, %.c, $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

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

all:
	make -C $(LIB_DIR)/libft/
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(LD) $(OBJ) $(LFLAGS) -rpath ./lib/Frameworks -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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

.PHONY: all clean fclean re depend
# DO NOT DELETE

obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/apply_light_effects.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/sphere.h
obj/camera.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/camera.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/camera.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors.h
obj/camera.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors_defines.h
obj/cone.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/cone.h
obj/cone.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/cone.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/cone.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/cylinder.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/drawer.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/RTv1_defines.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors_defines.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/libft.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/get_next_line.h
obj/drawer_render.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/drawer.h
obj/drawer_render.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/RTv1_defines.h
obj/errors.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors.h
obj/errors.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors_defines.h
obj/light.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/light.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/drawer.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/RTv1_defines.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors_defines.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/libft.h
obj/main.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/get_next_line.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/plane.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/plane.h
obj/plane.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/plane.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/plane.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/drawer.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/RTv1_defines.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/drawer.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/RTv1_defines.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/errors_defines.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/libft.h
obj/scene.o: /Users/amelihov/Projects/rtv1/amelihov1/lib/libft/includes/get_next_line.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/sphere.h
obj/scene_initial_data.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/cylinder.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/sphere.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/scene.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/camera.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/vect3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/object3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/color.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/amelihov1/includes/light.h
