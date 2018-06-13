/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/13 15:59:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object3d.h"
#include "object_ptr_arr.h"
#include "errors.h"
#include "libft.h"

static t_object3d	**parse_objects_failure(t_object3d **objects, char *err)
{
	try_set_err(err);
	object_ptr_arr_delete(objects);
	return (NULL);
}

t_object3d			**parse_objects(char **lines, int nobjects_nexpected)
{
	t_object3d	**objects;
	int			nlines;

	objects = NULL;
	nlines = ft_get_str_arr_size(lines);
	if (nobjects_nexpected > nlines)
		return (parse_objects_failure(objects, PARSER_OBJECT_NLINES));
	if (!(objects = malloc(sizeof(t_object3d *) * (nobjects_nexpected + 1))))
		return (parse_objects_failure(objects, PARSER_MEM_FAIL));
	objects[nobjects_nexpected] = NULL;
	i = 0;
	while (i < nobjects_nexpected)
	{
		if (!(objects[i] = parse_object(lines[i])))
			return (parse_objects_failure(objects, PARSE_FAIL));
		i++;
	}
	return (objects);
}
