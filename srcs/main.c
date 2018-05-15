/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/10 22:36:33 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "errors.h"
#include "libft.h"

t_scene	**scenes_initial_data(void);
void	run_event_handler_loop(t_drawer *drawer, t_scene **scenes);

int		print_err(void)
{
	ft_putendl_fd(get_err(), 2);
	return (1);
}

#define CLEAR(smth) {smth##_clear(smth);}

int 	main(void)
{
	t_drawer	*drawer;
	t_scene		**scenes;

	drawer = drawer_init();
	if (!drawer)
		return (print_err());
	scenes = scenes_initial_data();
	if (!scenes)
		return (print_err());
	run_event_handler_loop(drawer, scenes);
//	CLEAR(scenes);
	CLEAR(drawer);
	return (0);
}
