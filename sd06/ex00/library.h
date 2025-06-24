/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:13:35 by glancell          #+#    #+#             */
/*   Updated: 2025/06/24 18:13:36 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 1000
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// File operations
int load_catalog(Library *lib, const char *filename);
void handle_file_error(const char *filename);

// Search functions
void search_by_title(const Library *lib, const char *query);
void search_by_author(const Library *lib, const char *query);

// Utility functions
void trim_whitespace(char *str);
int case_insensitive_contains(const char *str, const char *substr);
void clear_input_buffer();

// User interface
void run_interactive_mode(Library *lib);

#endif