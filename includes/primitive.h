/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:14:38 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:41:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

//# include "sphere.h"

# define N	_new
# define I	_intersection
# define GN	_get_normal
# define D	_delete
//# define PRIMITIVE(n, ...) (void *[]){n##N(__VA_ARGS__),n##I,n##GN,n##D}

# define PRIMITIVE(n, ...) (void *[]){n##_new(__VA_ARGS__),n##_intersection, \
							n##_get_normal, n##_delete}
# undef N
# undef I
# undef GN
# undef D

#endif
