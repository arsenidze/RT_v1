/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   event_handler_loop.c                               :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:11:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 21:20:33 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "scene_ptr_arr.h"
#include "userinput.h"
#include "vect3d.h"
#include "libft.h"
void	render_scene(t_pixel *pixels, t_scene *scene, t_userinput *userinput);
int		clampi(int x, int a, int b);
void	move_current_object(t_scene **scene, t_userinput *userinput,
		t_vect3d step);

#define NEED_REDRAW			1
#define DELTA_CAM_STEP		20
#define DELTA_CAM_ANGEL		(M_PI / 180.0) * 10.0
#define MAX_STEP_IN_PIXELS	10

short	camera_active_keys(int key_code, t_userinput *ui, t_scene **scenes)
{
	if (key_code == SDL_SCANCODE_SPACE)
		camera_move(scenes[ui->scene_index]->camera, DELTA_CAM_STEP);
	else if (key_code == SDL_SCANCODE_RSHIFT)
		camera_move(scenes[ui->scene_index]->camera, -DELTA_CAM_STEP);
	else if (key_code == SDL_SCANCODE_KP_8)
		camera_rotateOY(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_5)
		camera_rotateOY(scenes[ui->scene_index]->camera,-DELTA_CAM_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_4)
		camera_rotateOZ(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_6)
		camera_rotateOZ(scenes[ui->scene_index]->camera, -DELTA_CAM_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_7)
		camera_rotateOX(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key_code == SDL_SCANCODE_KP_9)
		camera_rotateOX(scenes[ui->scene_index]->camera, -DELTA_CAM_ANGEL);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

short	object_active_keys(int key_code, t_userinput *userinput,
		t_scene **scenes)
{
	if (key_code == SDL_SCANCODE_Q)
		move_current_object(scenes, userinput, VECT3D(DELTA_CAM_STEP, 0, 0));
	else if (key_code == SDL_SCANCODE_A)
		move_current_object(scenes, userinput, VECT3D(-DELTA_CAM_STEP, 0, 0));
	else if (key_code == SDL_SCANCODE_W)
		move_current_object(scenes, userinput, VECT3D(0, DELTA_CAM_STEP, 0));
	else if (key_code == SDL_SCANCODE_S)
		move_current_object(scenes, userinput, VECT3D(0, -DELTA_CAM_STEP, 0));
	else if (key_code == SDL_SCANCODE_E)
		move_current_object(scenes, userinput, VECT3D(0, 0, DELTA_CAM_STEP));
	else if (key_code == SDL_SCANCODE_D)
		move_current_object(scenes, userinput, VECT3D(0, 0, -DELTA_CAM_STEP));
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

short	handle_key_down(int key_code, t_userinput *userinput, t_scene **scenes)
{
	if (key_code == SDL_SCANCODE_ESCAPE)
	{
		userinput->quit = 1;
		return (!NEED_REDRAW);
	}
	if (key_code == SDL_SCANCODE_KP_MULTIPLY)
		userinput->scene_index= clampi(++userinput->scene_index, 0,
			userinput->nscenes);
	if (key_code == SDL_SCANCODE_KP_PLUSMINUS)
		userinput->scene_index = clampi(++userinput->scene_index, 0,
			userinput->nscenes);
	else if (key_code == SDL_SCANCODE_KP_PLUS)
		userinput->step_in_pixels = clampi(++userinput->step_in_pixels, 1,
			MAX_STEP_IN_PIXELS);
	else if (key_code == SDL_SCANCODE_KP_MINUS)
		userinput->step_in_pixels = clampi(--userinput->step_in_pixels, 1,
			MAX_STEP_IN_PIXELS);
	else if (camera_active_keys(key_code, userinput, scenes) == NEED_REDRAW)
		;
	else if (object_active_keys(key_code, userinput, scenes) == NEED_REDRAW)
		;
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
	userinput.nscenes = scene_ptr_arr_size(scenes);
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
