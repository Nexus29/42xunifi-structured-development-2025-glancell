/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:02:35 by glancell          #+#    #+#             */
/*   Updated: 2025/06/18 20:12:44 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_book
{
	int id;
	char *title;
	char *author;
}	t_book;

typedef struct s_libary
{
	t_book *book;
	int count;
}	t_library

t_library *load_catalog(const char *filename);
void search_by_title(t_library *lib, const char *query);
void search_by_author(t_library *lib, const char *query);
void free_library(t_library *lib);

// objective of the program:
// Design a console-based software for a community library to manage a catalog of books.
// the flowchart of the programm will probably be:
// load ->
// store ->
// Prompt user ->
// Search ->
// Display the result ->
// exit
