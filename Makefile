# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/06/15 23:17:02 by amelihov         ###   ########.fr        #
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
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

obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/apply_light.o: /Users/amelihov/Projects/rtv1/github/includes/intersection.h
obj/camera.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/camera.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/camera.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/camera.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/cone.o: /Users/amelihov/Projects/rtv1/github/includes/cone.h
obj/cone.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/includes/drawer.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/includes/RTv1_defines.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/drawer.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/drawer_render.o: /Users/amelihov/Projects/rtv1/github/includes/drawer.h
obj/drawer_render.o: /Users/amelihov/Projects/rtv1/github/includes/RTv1_defines.h
obj/errors.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/errors.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/scene_ptr_arr.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/get_default_scenes.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/cone.h
obj/get_scene1.o: /Users/amelihov/Projects/rtv1/github/includes/plane.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/get_scene2.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/cone.h
obj/get_scene3.o: /Users/amelihov/Projects/rtv1/github/includes/plane.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/cone.h
obj/get_scene4.o: /Users/amelihov/Projects/rtv1/github/includes/plane.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/get_scene_from_file.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/is_intersect_smth.o: /Users/amelihov/Projects/rtv1/github/includes/intersection.h
obj/light.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/light.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/light.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/light.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/light_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/light_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/light_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/light_ptr_arr.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/drawer.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/RTv1_defines.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/scene_ptr_arr.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/scenes.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/main.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/object3d.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/object_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/object_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/object_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/object_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/object_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/object_ptr_arr.h
obj/plane.o: /Users/amelihov/Projects/rtv1/github/includes/plane.h
obj/plane.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/drawer.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/RTv1_defines.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/render_scene.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/drawer.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/RTv1_defines.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/includes/userinput.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/run_event_handler_loop.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/scene.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/scene_ptr_arr_delete.o: /Users/amelihov/Projects/rtv1/github/includes/scene_ptr_arr.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/sphere.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/trace_ray.o: /Users/amelihov/Projects/rtv1/github/includes/intersection.h
obj/parser/get_value_of_attr_with_name.o: parser/parser_private.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/get_value_of_attr_with_name.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/is_correct_eol.o: parser/parser_private.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/is_correct_eol.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/is_only_whitespaces.o: parser/parser_private.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/is_only_whitespaces.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/is_valid_radius.o: parser/parser_private.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/is_valid_radius.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/is_valid_slope.o: parser/parser_private.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/is_valid_slope.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_attr_of_type_double.o: parser/parser_private.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_attr_of_type_double.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_attr_of_type_vect3d.o: parser/parser_private.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_attr_of_type_vect3d.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_camera.o: parser/parser_private.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_camera.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_cone.o: parser/parser_private.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/cone.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_cone.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_cylinder.o: parser/parser_private.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/cylinder.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_cylinder.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_double.o: parser/parser_private.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_double.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_integer.o: parser/parser_private.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_integer.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_light.o: parser/parser_private.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_light.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_lights.o: parser/parser_private.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/light_ptr_arr.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_lights.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_object.o: parser/parser_private.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_object.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_objects.o: parser/parser_private.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/object_ptr_arr.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parse_objects.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/parse_plane.o: parser/parser_private.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/plane.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_plane.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_sphere.o: parser/parser_private.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/sphere.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parse_sphere.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parse_vect3d.o: parser/parser_private.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parse_vect3d.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parser_parse_scene.o: parser/parser_private.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/errors.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/includes/errors_defines.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/libft.h
obj/parser/parser_parse_scene.o: /Users/amelihov/Projects/rtv1/github/lib/libft/includes/get_next_line.h
obj/parser/skip_separator.o: parser/parser_private.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/skip_separator.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
obj/parser/str_with_digits_to_int.o: parser/parser_private.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/parser.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/scene.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/camera.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/vect3d.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/object3d.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/color.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/primitive.h
obj/parser/str_with_digits_to_int.o: /Users/amelihov/Projects/rtv1/github/includes/light.h
