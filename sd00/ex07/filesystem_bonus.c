/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:36:35 by glancell          #+#    #+#             */
/*   Updated: 2025/06/13 09:43:01 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

int compute_total_size(FSNode *node)
{
	if (!node) return (0);
	
	int total = node->size;
	FSNode *child = node->child;
	while (child)
	{
		total += compute_total_size(child);
		child = child->sibling;
	}
	return (total);
}

void print_structure(const FSNode *node, int indent)
{
	if (!node) return ;

	for (int i = 0; i < indent; i++)
		printf("  ");
	if (node->size == 0)
		printf("[D] %s/\n", node->name);
	else
		printf("[F] %s (%d bytes)\n", node->name, node->size);
	FSNode *child = node->child;
	while (child)
	{
		print_structure(child, indent + 1);
		child = child->sibling;
	}
}

void free_filesystem(FSNode *node)
{
	if (!node) return ;

	FSNode *child = node->child;
	while (child)
	{
		FSNode *next = child->sibling;
		free_filesystem(child);
		child = next;
	}
	free(node->name);
	free(node);
}

// int main()
// {
//     // Create a filesystem structure
//     FSNode *root = create_folder("Root");
//     FSNode *docs = create_folder("Documents");
//     FSNode *pics = create_folder("Pictures");
//     FSNode *file1 = create_file("notes.txt", 150);
//     FSNode *file2 = create_file("report.pdf", 450);
//     FSNode *file3 = create_file("photo.jpg", 1200);

//     // Build the hierarchy
//     add_child(root, docs);
//     add_child(root, pics);
//     add_child(docs, file1);
//     add_child(docs, file2);
//     add_child(pics, file3);

//     // Test the bonus functions
//     printf("Filesystem Structure:\n");
//     print_structure(root, 0);

//     int total_size = compute_total_size(root);
//     printf("\nTotal size of filesystem: %d bytes\n", total_size);

//     // Clean up
//     free_filesystem(root);

//     return 0;
// }
