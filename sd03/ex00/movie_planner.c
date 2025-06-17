/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:26:22 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:28:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *prefs = get_user_preferences();
	if (!prefs)
		return (NULL);

	struct MovieList *movies = find_movies(prefs);
	if (!movies)
		return (free(prefs), NULL);

	struct Plan *plan = build_plan(movies);
	free(prefs);
	free(movies);
	return (plan);
}
