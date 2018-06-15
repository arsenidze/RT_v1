/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:50 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:07:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "light.h"
#include "errors.h"
#include "libft.h"

static t_light	*parse_light_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_light			*parse_light(char *line)
{
	int			i;
	t_vect3d	pos;
	t_vect3d	components[3];

	if (!ft_strnequ(line, "\t"LIGHT_ID":", ID_LEN(LIGHT_ID) + 2))
		return (parse_light_failure(PARSER_LIGHT_ID_FAIL));
	i = ID_LEN(LIGHT_ID) + 2;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos))
		return (parse_light_failure(PARSER_LIGHT_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_light_failure(PARSER_LIGHT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AMBNT, &components[0]))
		return (parse_light_failure(PARSER_LIGHT_AMBIENT_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_light_failure(PARSER_LIGHT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, DIFF, &components[1]))
		return (parse_light_failure(PARSER_LIGHT_DIFFUSE_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_light_failure(PARSER_LIGHT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, SPEC, &components[2]))
		return (parse_light_failure(PARSER_LIGHT_SPECULAR_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_light_failure(PARSER_LIGHT_EOL_FAIL));
	return (light_new(pos, components));
}
