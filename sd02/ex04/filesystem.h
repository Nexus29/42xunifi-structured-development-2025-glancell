/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:21:43 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 23:36:56 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FSNode
{
	char			*name; // name of the file/folder
	int				size; // size of the files (0 for folders)
	struct FSNode	*child; // points to the first child
	struct FSNode	*sibling; // points at the next node in the tree
}	FSNode;

FSNode	*create_file(const char *name, int size);
FSNode	*create_folder(const char *name);
void	add_child(FSNode *parent, FSNode *child);
FSNode	*get_children(const FSNode *parent);
FSNode	*get_sibling(const FSNode *node);

#endif
