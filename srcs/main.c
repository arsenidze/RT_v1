/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 22:27:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "drawer.h"
#include "scene_ptr_arr.h"
#include "errors.h"
#include "libft.h"
#include "scenes.h"

t_scene	*get_scene_from_file(const char *file_name);
t_scene	**get_default_scenes(void);
void	run_event_handler_loop(t_drawer *drawer, t_scene **scenes);

static int	print_usage(void)
{
	ft_putendl(PROGNAME": ""[scene_file]");
	return (1);
}

int 	main(int argc, char *argv[])
{
	t_drawer		*drawer;
	t_scene			**scenes;

	if (argc > 2)
		return (print_usage());
	if (argc == 2)
	{
		if (!(scenes = malloc(sizeof(t_scene *) * 2)))
			return (err_print(strerror(errno)));
		scenes[1] = NULL;
		if (!(scenes[0] = get_scene_from_file(argv[1])))
			return (err_print(PROGNAME": "));
	}
	else
		scenes = get_default_scenes();
	if (!scenes)
		return (err_print(PROGNAME": "));
	drawer = drawer_new();
	if (!drawer)
		return (err_print(PROGNAME": "));
	run_event_handler_loop(drawer, scenes);
	drawer_delete(drawer);
	scene_ptr_arr_delete(scenes);
	return (0);
}
