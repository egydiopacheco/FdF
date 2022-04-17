/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_pov	*initialize_pov(t_landscape *landscape)
{
	t_pov	*pov;

	pov = malloc(sizeof(t_pov));
	if (!pov)
		return (NULL);
	fill_pov_params(&pov, landscape);
	return (pov);
}

void	fill_pov_params(t_pov **pov, t_landscape *landscape)
{
	(*pov)->projection = ISOMETRIC;
	(*pov)->color_pallet = false;
	(*pov)->params.scaling_factor = fit_screen(landscape);
	(*pov)->params.depth_scale = 1;
	(*pov)->pos.x = WINDOW_WIDTH / 1.75;
	(*pov)->pos.y = WINDOW_HEIGHT / 1.5;
	(*pov)->params.a = 0;
	(*pov)->params.b = 0;
	(*pov)->params.c = 0;
}
