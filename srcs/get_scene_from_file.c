/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 22:16:57 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/12 22:52:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "scene.h"
#include "parser.h"
#include "libft.h"
#include "errors.h"

t_scene *get_scene_from_file(const char *file_name)
{
	t_scene	*scene;
	char 	**lines;

	if (!(lines = read_file(file_name)))
	{
		try_set_err(strerror(errno));
		return (NULL);
	}
	if (!(scene = parser_parse_scene(lines)))
	{
		try_set_err(PARSER_PARSE_FAIL);
	}
	free_strs(lines, 0);
	return (scene);
}
