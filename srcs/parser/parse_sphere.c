/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:19:50 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 21:22:12 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object3d.h"
#include "sphere.h"
#include "errors.h"
#include <stddef.h>

static t_object3d	*parse_sphere_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object3d			*parse_sphere(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	double		radius;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos))
		return (parse_sphere_failure(PARSER_SPHERE_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_sphere_failure(PARSER_SPHERE_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, RADIUS, &radius))
		return (parse_sphere_failure(PARSER_SPHERE_RADIUS_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_sphere_failure(PARSER_SPHERE_EOL_FAIL));
	return (object3d_new(components, PRIMITIVE(sphere, pos, radius)));
}
