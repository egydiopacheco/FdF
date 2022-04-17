/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum	e_error
{
	FDF_BUILD_ERROR		= 100,
	LANDSCAPE_BUILD_ERROR	= 101,
	IMAGE_BUILD_ERROR	= 102,
	POV_BUILD_ERROR		= 103,
	INPUT_ERROR		= 104,
	EXTENSION_MISMATCH	= 105,
	BROKEN_SIMMETRY		= 106,
	ALLOCATE_ERROR		= 107,
	FILE_DESCRIPTOR_ERROR	= 108,
	PLANE_BUILD_ERROR	= 109,
	NULL_VECTOR		= 110,
	IN_BOUNDS		= 111,
	OUT_OF_BOUNDS		= 112,
	COLOR_INIT_ERROR = 113,
	VECTOR_INIT_ERROR = 114,
};

#endif
