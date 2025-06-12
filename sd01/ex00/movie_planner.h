/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:25:50 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:34:12 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

struct Preferences;
struct MovieList;
struct Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

struct Plan *create_movie_night_plan(void);

#endif
