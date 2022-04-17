/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_color	*initialize_color(t_point p_a, t_point p_b)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->gradient.begin.encoded = p_a.color;
	color->gradient.begin.r = (RED & p_a.color) >> 16;
	color->gradient.begin.g = (GREEN & p_a.color) >> 8;
	color->gradient.begin.b = (BLUE & p_a.color);
	color->gradient.end.encoded = p_b.color;
	color->gradient.end.r = (RED & p_b.color) >> 16;
	color->gradient.end.g = (GREEN & p_b.color) >> 8;
	color->gradient.end.b = (BLUE & p_b.color);
	color->dr = (color->gradient.end.r - color->gradient.begin.r);
	color->dg = (color->gradient.end.r - color->gradient.begin.g);
	color->db = (color->gradient.end.b - color->gradient.begin.b);
	return (color);
}

t_color	*initialize_color_scheme(int min_color, int max_color)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->gradient.begin.encoded = min_color;
	color->gradient.begin.r = (RED & min_color) >> 16;
	color->gradient.begin.g = (GREEN & min_color) >> 8;
	color->gradient.begin.b = (BLUE & min_color);
	color->gradient.end.encoded = max_color;
	color->gradient.end.r = (RED & max_color) >> 16;
	color->gradient.end.g = (GREEN & max_color) >> 8;
	color->gradient.end.b = (BLUE & max_color);
	color->dr = (color->gradient.end.r - color->gradient.begin.r);
	color->dg = (color->gradient.end.g - color->gradient.begin.g);
	color->db = (color->gradient.end.b - color->gradient.begin.b);
	return (color);
}
