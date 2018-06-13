/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_event_handler_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:27:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 16:56:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "userinput.h"
#include "libft.h"
void	render_scene(t_pixel *pixels, t_scene *scene);

float		g_specular_pow = 300.;
float		g_ambient = 0.3;
float		g_diffuse = 0.3;
float		g_specular = 0.3;

double	g_lx;
double	g_ly;
double	g_lz;

#define NACTIVE_KEYS 5

#define NEED_REDRAW		1

float 		g_delta1 = 0.1;
float 		g_delta2 = 100;
int			g_up = 0;
#define S(x) #x
#define PRINT(name, flag) printf(S(name) S(: %) S(flag), name);

short	handle_key_down(int key_code, t_userinput *userinput)
{
//	static int	key_code_array[NACTIVE_KEYS][1] = {
//		{SDL_SCANCODE_ESCAPE, set},
//		{}
//	};
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
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

#define LOOP_QUIT	{userinput.quit = 1; break ;}

void	run_event_handler_loop(t_drawer *drawer, t_scene **scenes)
{
//	short		quit;
	SDL_Event	event;
//	int			scene_index;
	t_userinput	userinput;

	userinput.scene_index = 0;
	userinput.quit = 0;
	render_scene(drawer->pixels, scenes[userinput.scene_index]);
	drawer_render(drawer);
	while (!userinput.quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				LOOP_QUIT
			else if (event.type == SDL_KEYDOWN)
			{
				if (handle_key_down(event.key.keysym.scancode, &userinput))
				{
					render_scene(drawer->pixels, scenes[userinput.scene_index]);
					drawer_render(drawer);
				}
			}
		}
	}
}
