/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:20:16 by glancell          #+#    #+#             */
/*   Updated: 2025/06/18 20:24:59 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_contact
{
	int id;
	char *name;
	char *phone;
	char *email;
	char *city;
	char *address;
}	t_contact;

typedef struct s_contact_manager
{
	t_contact *contacts;
	int count;
}	t_contact_manager;

t_contact_manager	*load_contacts(const char *filename);
void				add_contact(t_contact_manager *manager);
void				search_contact(t_contact_manager *manager, const char *query);
void				save_contacts(t_contact_manager *manager, const char *filename);	

// objective of the program:
// Design a console program who work like an address book
// the flowchart of the programm will probably be:
// load and validate contacts files
// Display the menu'
// validate input(email, ID and other stuffs)
// Save the changes
// Display the results
// exit
