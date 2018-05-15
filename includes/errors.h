/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:27:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/04/19 09:02:15 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "errors.h"

/*
**	set_err:
**	setter to error variable
*/
void	set_err(char *err);

/*
**	get_err:
**	getter for error variable
*/
char	*get_err(void);

/*
**	try_set_err:
**	check if error variable is NULL then set it to input char *err
*/
void	try_set_err(char *err);

# include "errors_defines.h"

#endif
