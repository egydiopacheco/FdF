/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vector	*initialize_vector(t_point p_a, t_point p_b, t_landscape *landscape)
{
	t_vector	*vector;
	float		max2d;
	float		max3d;

	max2d = ft_max_value_between(landscape->horizontal_boundaries,
			landscape->vertical_boundaries);
	max3d = landscape->maximum_depth - landscape->minimum_depth;
	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->p_a.x = p_a.x;
	vector->p_a.y = p_a.y;
	vector->p_a.z = p_a.z;
	vector->p_a.color = p_a.color;
	vector->p_b.x = p_b.x;
	vector->p_b.y = p_b.y;
	vector->p_b.z = p_b.z;
	vector->p_b.color = p_b.color;
	vector->z = ft_max_value_between(max3d, max2d);
	return (vector);
}
