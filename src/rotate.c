/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_pov *pov, t_vector *vector)
{
	rotate_x(vector, vector->p_a.y, vector->p_b.y, pov->params.a);
	rotate_y(vector, vector->p_a.x, vector->p_b.x, pov->params.b);
	rotate_z(vector, vector->p_a.x, vector->p_b.x, pov->params.c);
}

void	rotate_x(t_vector *V, float a_y, float b_y, double theta)
{
	V->p_a.y = V->p_a.y * cos(theta) - V->p_a.z * sin(theta);
	V->p_a.z = a_y * sin(theta) + V->p_a.z * cos(theta);
	V->p_b.y = V->p_b.y * cos(theta) - V->p_b.z * sin(theta);
	V->p_b.z = b_y * sin(theta) + V->p_b.z * cos(theta);
}

void	rotate_y(t_vector *V, float a_x, float b_x, double theta)
{
	V->p_a.x = V->p_a.x * cos(theta) + V->p_a.z * sin(theta);
	V->p_a.z = (-a_x) * sin(theta) + V->p_a.z * cos(theta);
	V->p_b.x = V->p_b.x * cos(theta) + V->p_b.z * sin(theta);
	V->p_b.z = (-b_x) * sin(theta) + V->p_b.z * cos(theta);
}

void	rotate_z(t_vector *V, float a_x, float b_x, double theta)
{
	V->p_a.x = V->p_a.x * cos(theta) - V->p_a.y * sin(theta);
	V->p_a.y = a_x * sin(theta) + V->p_a.y * cos(theta);
	V->p_b.x = V->p_b.x * cos(theta) - V->p_b.y * sin(theta);
	V->p_b.y = b_x * sin(theta) + V->p_b.y * cos(theta);
}
