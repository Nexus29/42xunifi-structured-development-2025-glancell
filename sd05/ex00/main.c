/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:05:37 by glancell          #+#    #+#             */
/*   Updated: 2025/06/20 09:05:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <catalog_file>\n", argv[0]);
        return 1;
    }

    int count;
    Book *books = load_books(argv[1], &count);
    if (!books) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    printf("Loaded %d books.\n", count);
    printf("Search by:\n1. Title\n2. Author\n> ");
    int choice;
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        fprintf(stderr, "Invalid choice.\n");
        free_books(books, count);
        return 1;
    }

    printf("Enter search query: ");
    char query[128];
    scanf(" %127[^\n]", query); // Read entire line (spaces allowed).

    search_books(books, count, query, choice == 1);
    free_books(books, count);
    return 0;
}
