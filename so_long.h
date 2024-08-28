/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:43:51 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 11:19:16 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define HEIGHT 32
# define WIDTH 32

# include "my_library/my_library.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef enum e_error
{
	TRUE = 1,
	FALSE = 0,
}	t_error;

typedef struct s_m_data
{
	void		*bground;
	void		*wall;
	void		*player_start;
	void		*collect;
	void		*exit;
	char		*path_bground;
	char		*path_wall;
	char		*path_player_start;
	char		*path_collect;
	char		*path_exit;
	int			coups;
	int			img_width;
	int			img_height;
	int			pos_x;
	int			pos_y;
	size_t		rows;
	size_t		columns;
	size_t		count;
	char		**map;
	void		*mlx_win;
	void		*mlx_ptr;
}	t_m_data;

// Utils
void	**free_double(char **s);
void	free_struct(char **tab, void *content);
int		close_game(t_m_data *m_data);
void	to_img(t_m_data *m_data, void *img, int x, int y);

// Manage input
int		manage_input(t_m_data **m_data, char *str);

// Check map
int		check_map(t_m_data **m_data);

// Is accesible
int		is_accessible(t_m_data **m_data);

// Render game
int		render_game(t_m_data *m_data);
int		render_sprites(t_m_data *m_data);

// Handle input
int		handle_input(int keysym, t_m_data *m_data);

// Init sprites
void	init_sprites(t_m_data *m_data);

#endif