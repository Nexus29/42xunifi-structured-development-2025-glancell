/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:06:07 by glancell          #+#    #+#             */
/*   Updated: 2025/06/20 09:06:08 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Trim whitespace and lowercase a string for case-insensitive comparison.
static char *trim_lower(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == '\0') return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    for (char *p = str; *p; p++) *p = tolower(*p);
    return str;
}

Book *load_books(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    Book *books = malloc(1000 * sizeof(Book)); // Max 1000 books.
    char line[256];
    *count = 0;

    while (fgets(line, sizeof(line), file) && *count < 1000) {
        int id;
        char title[128], author[128];
        if (sscanf(line, "%d,%127[^,],%127[^\n]", &id, title, author) == 3) {
            books[*count].id = id;
            books[*count].title = strdup(title);
            books[*count].author = strdup(author);
            (*count)++;
        } else {
            fprintf(stderr, "Skipping malformed line: %s", line);
        }
    }
    fclose(file);
    return books;
}

void search_books(const Book *books, int count, const char *query, int search_by_title) {
    char query_lower[128];
    strncpy(query_lower, query, sizeof(query_lower));
    trim_lower(query_lower);

    int found = 0;
    for (int i = 0; i < count; i++) {
        char *field = search_by_title ? books[i].title : books[i].author;
        char field_lower[128];
        strncpy(field_lower, field, sizeof(field_lower));
        trim_lower(field_lower);

        if (strstr(field_lower, query_lower)) {
            printf("ID: %d | Title: %s | Author: %s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}

void free_books(Book *books, int count) {
    for (int i = 0; i < count; i++) {
        free(books[i].title);
        free(books[i].author);
    }
    free(books);
}