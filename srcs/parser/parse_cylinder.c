/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:13 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/13 16:57:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

static t_object3d	*parse_cylinder_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object3d			*parse_cylinder(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	axis;
	double		radius;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos))
		return (parse_cylinder_failure(PARSER_CYLINDER_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cylinder_failure(PARSER_CYLINDER_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AXIS, &axis))
		return (parse_cylinder_failure(PARSER_CYLINDER_AXIS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cylinder_failure(PARSER_CYLINDER_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, RADIUS, &radius))
		return (parse_cylinder_failure(PARSER_CYLINDER_RADIUS_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_light_failure(PARSER_CYLINDER_EOL_FAIL));
	return (object3d_new(components, PRIMITIVE(cylinder, pos, axis, radius)));
}
