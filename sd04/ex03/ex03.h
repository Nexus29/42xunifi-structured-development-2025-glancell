/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:27:58 by glancell          #+#    #+#             */
/*   Updated: 2025/06/18 20:38:09 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_movie
{
	int id;
	char *title;
	char *genre;
	int watched;
	int rating;
	char *date_watched;
}	t_movie;

typedef struct s_watchlist
{
	t_movie *movies;
	int count;
}	t_watchlist;

t_watchlist	*load_watchlist(const char *filename);
void		mark_as_watched(t_watchlist *watchlist, int id);
void		show_stats(t_watchlist *watchlist);

// objective of the program:
// Design a console program who work like a movie watchlist app
// the flowchart of the programm will probably be:
// load and validate watchlist
// Display the menu'
// validate input*(ratings, genre and stuff like this)
// Save the changes
// Display the results
// exit
