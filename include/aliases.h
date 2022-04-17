/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliases.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIASES_H
# define ALIASES_H

# define TITLE	 	        "FdF - A 3D Wireframe Viewer"
# define WINDOW_WIDTH		1280
# define WINDOW_HEIGHT		1024

# define ESC                65307
# define ARROW_UP           65362 
# define ARROW_DOWN         65364
# define ARROW_LEFT         65361
# define ARROW_RIGHT        65363
# define KEY_Q              113
# define KEY_W              119
# define KEY_E              101
# define KEY_A              97
# define KEY_S              115
# define KEY_D              100
# define KEY_Z              122
# define KEY_X              120
# define KEY_C              99
# define KEY_V              118
# define KEY_1              49
# define KEY_2	            50
# define KEY_3	            51
# define KEY_4	            52
# define KEY_SPACE          32
# define MOUSE_RIGHT_CLICK  1
# define MOUSE_SCROLL_CLICK 2
# define MOUSE_LEFT_CLICK   3
# define MOUSE_SCROLL_UP    4
# define MOUSE_SCROLL_DOWN  5
# define HEXA_BASE	        "0123456789abcdef"
# define DEG_1				0.01745329
# define DEG_30				0.52359877
# define DEG_45				0.78539816

enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP_DOWN
};

enum e_bool
{
	false,
	true
};

#endif
