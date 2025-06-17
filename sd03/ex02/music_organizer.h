/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:39:21 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:40:18 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
#define MUSIC_ORGANIZER_H

struct MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song)

struct MusicLibrary *organize_music_library(const char *directory_path);

#endif
