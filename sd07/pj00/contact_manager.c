/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:13:14 by glancell          #+#    #+#             */
/*   Updated: 2025/06/25 11:11:14 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact_manager.h"
#include <fcntl.h>

void init_manager(ContactManager *manager)
{
    manager->contacts = NULL;
    manager->count = 0;
}

void free_manager(ContactManager *manager)
{
    for (int i = 0; i < manager->count; i++) {
        free(manager->contacts[i].name);
        free(manager->contacts[i].phone);
        free(manager->contacts[i].email);
        free(manager->contacts[i].city);
        free(manager->contacts[i].address);
    }
    free(manager->contacts);
}

int load_contacts(ContactManager *manager, const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        ft_printf("Error opening file\n");
        return 0;
    }

    char *line;
    while ((line = get_next_line(fd)))
	{
        char **fields = ft_split(line, ',');
        free(line);
        
        if (!fields || !fields[0] || !fields[1] || !fields[2] || !fields[3] || !fields[4])
		{
            ft_free_split(fields);
        }
        Contact *new_contacts = ft_calloc(manager->count + 1, sizeof(Contact));
        if (!new_contacts)
		{
            ft_free_split(fields);
            close(fd);
            return 0;
        }

        for (int i = 0; i < manager->count; i++) {
            new_contacts[i] = manager->contacts[i];
        
        new_contacts[manager->count] = (Contact)
		{
            .id = ft_atoi(fields[0]),
            .name = ft_strtrim(fields[1], " \t\n"),
            .phone = ft_strtrim(fields[2], " \t\n"),
            .email = ft_strtrim(fields[3], " \t\n"),
            .city = ft_strtrim(fields[4], " \t\n"),
            .address = fields[5] ? ft_strtrim(fields[5], " \t\n") : ft_strdup("")
        };
        free(manager->contacts);
        manager->contacts = new_contacts;
        manager->count++;

        ft_free_split(fields);
    	}
	}
    close(fd);
    return 1;
}

void list_contacts(const ContactManager *manager)
{
    for (int i = 0; i < manager->count; i++) {
        ft_printf("ID: %d\n", manager->contacts[i].id);
        ft_printf("Name: %s\n", manager->contacts[i].name);
        ft_printf("Phone: %s\n", manager->contacts[i].phone);
        ft_printf("Email: %s\n", manager->contacts[i].email);
        ft_printf("City: %s\n", manager->contacts[i].city);
        ft_printf("Address: %s\n\n", manager->contacts[i].address);
    }
}

