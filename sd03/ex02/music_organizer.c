/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:40:32 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:41:40 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    if (!directory_path)
        return (NULL);

    struct MusicLibrary *library = create_music_library();
    if (!library)
        return (NULL);
 
    const char **files = scan_directory(directory_path);
    if (!files)
        return (free(library), NULL);

    for (int i = 0; files[i]; i++)
	{
        struct MusicFile *song = process_music_file(directory_path, files[i]);
        if (song)
		{
            update_music_library(library, song);
            free(song);
        }
    }
    free(files);
    return (library);
}
