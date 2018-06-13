/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/13 16:35:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object3d.h"
#include "errors.h"
#include "libft.h"

static t_object3d	*parse_object_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

static t_object3d	*(*match_primitive_parser(
					char *line, t_vect3d components[3]))(char *value)
{
	if (ft_strequ(value, "sphere"))
		return (&parse_sphere);
	if (ft_strequ(value, "cylinder"))
		return (&parse_cylinder);
	if (ft_strequ(value, "cone"))
		return (&parse_cone);
	if (ft_strequ(value, "plane"))
		return (&parse_plane);
	return (NULL);
}

t_object3d			*parse_object(char *line)
{
	int			i;
	t_vect3d	components[3];
	char		*value;

	if (!ft_strequ(line, "\t"OBJECT_ID, ID_LEN(OBJECT_ID) + 1))
		return (parse_object_failure(PARSER_OBJECT_ID_FAIL));
	i = ID_LEN(OBJECT_ID) + 1;
	if (!parse_attr_of_type_vect3d(line, &i, AMBNT, &components[0]))
		return (parse_object_failure(PARSER_OBJECT_AMBNT_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_object_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, DIFF, &components[1]))
		return (parse_object_failure(PARSER_OBJECT_DIFFUSE_FAIL));
	if (!(skip_separator(&line, &i)))
		return (parse_object_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, SPEC, &components[2]))
		return (parse_object_failure(PARSER_OBJECT_SPEC_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_object_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	if (!(value = get_value_of_attr_with_name(line, &i, PRIMIT)))
		return (parse_object_failure(PARSER_OBJECT_PRIMITIVE_FAIL));
	if (!(primitive_parser = match_primitive_parser(value)))
		return (parse_object_failure(PARSER_OBJECT_PRIMITIVE_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_object_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	return (primitive_parser(&line[i], components));
}
