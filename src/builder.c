/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	build_fdf(t_fdf **fdf)
{
	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (*fdf == NULL)
		raise_error(FDF_BUILD_ERROR);
}

void	build_landscape(t_fdf **fdf, char *filename)
{
	(*fdf)->landscape = parse_landscape(filename);
	if (!(*fdf)->landscape)
	{
		free(*fdf);
		raise_error(LANDSCAPE_BUILD_ERROR);
	}
}

void	build_image(t_fdf **fdf)
{
	(*fdf)->image = initialize_image(*fdf);
	if (!(*fdf)->image)
		close_landscape(*fdf, 5);
}

void	build_pov(t_fdf **fdf)
{
	(*fdf)->pov = initialize_pov((*fdf)->landscape);
	if (!(*fdf)->pov)
		close_all(*fdf, 6);
}
