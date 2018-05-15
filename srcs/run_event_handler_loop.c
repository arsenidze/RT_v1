/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_event_handler_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:27:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/10 23:28:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"

void	render_scene(t_pixel *pixels, t_scene *scene);

#define LOOP_QUIT	{quit = 1; break ;}

void	run_event_handler_loop(t_drawer *drawer, t_scene **scenes)
{
	short		quit;
	SDL_Event	event;
	int			curr_scene;

	curr_scene = 0;
	quit = 0;
	render_scene(drawer->pixels, scenes[curr_scene]);
	drawer_render(drawer);
//	exit(0);
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				LOOP_QUIT
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					LOOP_QUIT
				else if (event.key.keysym.scancode == SDL_SCANCODE_1)
				{
					curr_scene = 0;
					printf("test0\n");
				}
				else if (event.key.keysym.scancode == SDL_SCANCODE_2)
				{
					curr_scene = 1;
					printf("test1\n");
				}
				else
					continue ;
				printf("test2\n");
				render_scene(drawer->pixels, scenes[curr_scene]);
				drawer_render(drawer);
				printf("test3\n");
			}
		}
	}
}
