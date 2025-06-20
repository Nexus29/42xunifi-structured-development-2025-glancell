/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:06:04 by glancell          #+#    #+#             */
/*   Updated: 2025/06/20 09:06:05 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_H
#define BOOK_H

#include <stdlib.h>

typedef struct s_book {
    int id;
    char *title;
    char *author;
} Book;

// Load books from file. Returns NULL on error.
Book *load_books(const char *filename, int *count);

// Case-insensitive substring search (by title or author).
void search_books(const Book *books, int count, const char *query, int search_by_title);

// Free all allocated books.
void free_books(Book *books, int count);

#endif