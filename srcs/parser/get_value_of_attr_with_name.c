/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_of_attr_with_name.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:52:58 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 16:03:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "libft.h"

short	get_value_of_attr_with_name(char *line, int *line_index,
		char *attr_name)
{
	int	i;

	i = *line_index;
	while (line[i] && IS_WHITESPACE(line[i]))
		i++;
	name_len = ft_strlen(attr_name);
	if (!ft_strequ(&line[i], attr_name, name_len))
		return (NULL);
	i += name_len;
	if (line[i] != LEFT_BRACKET)
		return (NULL);
	j = i + 1;
	while (line[j] && line[j] != RIGHT_BRACKET)
		j++;
	if (line[j] == '\0')
		return (NULL);
	*line_index = j + 1;
	return (&line[i]);
}
