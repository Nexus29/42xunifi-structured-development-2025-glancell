/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:57:28 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:59:18 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood = analyze_user_mood();
    if (!mood)
        return (NULL);

    struct FilterSettings *filters = default_filters();
    if (!filters)
        return (free_mood_settings(mood), NULL);

    int variations = get_mood_variations(mood);
    for (int i = 0; i < variations; i++)
	{
        filters = refine_filters(filters);
        if (!filters)
            return (free_mood_settings(mood), NULL);
    }

    struct Playlist *playlist = NULL;
    int popular = filters_require_popular_song(filters);
    struct SongData *song = NULL;
    if (popular)
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
    if (song)
	{
        playlist = combine_with_mood_playlist(song, mood);
        free_song_data(song);
    }
    
    free_mood_settings(mood);
    free_filter_settings(filters);
    return (playlist);
}
