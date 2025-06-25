/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_watchlist.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:15:22 by glancell          #+#    #+#             */
/*   Updated: 2025/06/25 11:12:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_WATCHLIST_H
#define MOVIE_WATCHLIST_H

#define MAX_MOVIES 1000
#define MAX_TITLE_LEN 100
#define MAX_GENRE_LEN 50
#define DATE_LEN 11

typedef struct
{
    char date[DATE_LEN]; // YYYY-MM-DD format
    int rating; // 1-10
} WatchEntry;

typedef struct
{
    int id;
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    WatchEntry watch_data;
    int is_watched;
} Movie;

typedef struct
{
    Movie movies[MAX_MOVIES];
    int count;
    int max_id;
} MovieWatchlist;

// File operations
int load_watchlist(MovieWatchlist *watchlist, const char *filename);
int save_watchlist(MovieWatchlist *watchlist, const char *filename);

// Validation functions
int is_valid_watch_date(const char *date);
int is_valid_rating(int rating);

// Operations
void add_movie(MovieWatchlist *watchlist);
void mark_as_watched(MovieWatchlist *watchlist);
void update_movie(MovieWatchlist *watchlist);
void delete_movie(MovieWatchlist *watchlist);

// Filtering functions
void list_all_movies(const MovieWatchlist *watchlist);
void filter_by_title(const MovieWatchlist *watchlist, const char *query);
void filter_by_genre(const MovieWatchlist *watchlist, const char *query);
void filter_by_watched_status(const MovieWatchlist *watchlist, int watched);

// Statistics
void show_statistics(const MovieWatchlist *watchlist);

// User interface
void run_movie_watchlist_ui(MovieWatchlist *watchlist);

#endif