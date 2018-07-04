/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:11:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 21:20:33 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "sphere.h"
#include "userinput.h"
#include "vect3d.h"
#include "libft.h"
void	render_scene(t_pixel *pixels, t_scene *scene, t_userinput *userinput);

#define NEED_REDRAW 1
#define DELTA_CAMEARA_STEP 20
#define DELTA_CAMERA_ANGEL (M_PI / 180.0) * 10.0

short	handle_key_down(int key_code, t_userinput *userinput, t_scene **scenes)
{
	if (key_code == SDL_SCANCODE_ESCAPE)
	{
		userinput->quit = 1;
		return (!NEED_REDRAW);
	}
	else if (key_code == SDL_SCANCODE_1)
		userinput->scene_index = 0;
	else if (key_code == SDL_SCANCODE_2)
		userinput->scene_index = 1;
	else if (key_code == SDL_SCANCODE_3)
		userinput->scene_index = 2;
	else if (key_code == SDL_SCANCODE_4)
		userinput->scene_index = 3;
	else if (key_code == SDL_SCANCODE_SPACE)
		scenes[userinput->scene_index]->camera->pos
			+= VECT3D_MULL_ON_SCALAR(
					scenes[userinput->scene_index]->camera->dir,
					DELTA_CAMEARA_STEP);
	else if (key_code == SDL_SCANCODE_RSHIFT)
		scenes[userinput->scene_index]->camera->pos
			+= VECT3D_MULL_ON_SCALAR(
					scenes[userinput->scene_index]->camera->dir,
					-DELTA_CAMEARA_STEP);
	else if (key_code == SDL_SCANCODE_KP_8)
		camera_rotateOY(scenes[userinput->scene_index]->camera,
				DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_5)
		camera_rotateOY(scenes[userinput->scene_index]->camera,
				-DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_4)
		camera_rotateOZ(scenes[userinput->scene_index]->camera,
				DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_6)
		camera_rotateOZ(scenes[userinput->scene_index]->camera,
				-DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_9)
		camera_rotateOX(scenes[userinput->scene_index]->camera,
				DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_7)
		camera_rotateOX(scenes[userinput->scene_index]->camera,
				-DELTA_CAMERA_ANGEL);
	else if (key_code == SDL_SCANCODE_Q)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[X]
			+= DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_A)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[X]
			+= -DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_W)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[Y]
			+= DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_S)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[Y]
			+= -DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_E)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[Z]
			+= DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_D)
		((t_sphere*)(scenes[userinput->scene_index]
			->objects[userinput->object_index]->primitive))->pos[Z]
			+= -DELTA_CAMEARA_STEP;
	else if (key_code == SDL_SCANCODE_KP_PLUS)
		userinput->step_in_pixels += 1;
	else if (key_code == SDL_SCANCODE_KP_MINUS)
		userinput->step_in_pixels += -1;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

#define LOOP_QUIT	{userinput.quit = 1; break ;}

void	event_handler_loop(t_drawer *drawer, t_scene **scenes)
{
	SDL_Event	event;
	t_userinput	userinput;

	ft_memset(&userinput, 0, sizeof(t_userinput));
	userinput.step_in_pixels = 1;
	render_scene(drawer->pixels, scenes[userinput.scene_index], &userinput);
	drawer_render(drawer);
	while (!userinput.quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				LOOP_QUIT
			else if (event.type == SDL_KEYDOWN)
			{
				if (handle_key_down(event.key.keysym.scancode, &userinput,
					scenes) == NEED_REDRAW)
				{
					render_scene(drawer->pixels, scenes[userinput.scene_index],
						&userinput);
					drawer_render(drawer);
				}
			}
		}
	}
}
