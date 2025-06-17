/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:23:43 by glancell          #+#    #+#             */
/*   Updated: 2025/06/13 09:42:30 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

//this a basic file system manager it create always a node
// and it try to emulate the hierarchival structure of folder

// init and alloc a node with a name and a size
FSNode	*create_node(const char *name, int size)
{
	FSNode *node = malloc(sizeof(FSNode));
	node->name = strdup(name);
	node->size = size;
	node->child = node->sibling = NULL;
	return (node);
}

FSNode	*create_file(const char *name, int size)
{
	return (create_node(name, size));
}

FSNode	*create_folder(const char *name)
{
	return (create_node(name, 0));
}

void	add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child) return ;
	child->sibling = parent->child;
	parent->child = child;
}

FSNode	*get_children(const FSNode *parent)
{
	return (parent ? parent->child : NULL);
}

FSNode	*get_sibling(const FSNode *node)
{
	return (node ? node->sibling : NULL);
}


// int main()
// {
//     FSNode *root = create_folder("Root");
//     FSNode *file1 = create_file("file1.txt", 100);
//     FSNode *file2 = create_file("file2.txt", 200);
	
//     add_child(root, file1);
//     add_child(root, file2);
	
//     printf("Root's first child: %s\n", root->child->name); // Should print file2.txt
//     return 0;
// }
