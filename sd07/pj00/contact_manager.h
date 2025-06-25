/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:12:46 by glancell          #+#    #+#             */
/*   Updated: 2025/06/25 11:09:37 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "libft/libft.h"

#define MAX_CONTACTS 100
#define MAX_LINE 1024

typedef struct
{
    int id;
    char *name;
    char *phone;
    char *email;
    char *city;
    char *address;
} Contact;

typedef struct
{
    Contact *contacts;
    int count;
} ContactManager;

// Basic functions
void init_manager(ContactManager *manager);
void free_manager(ContactManager *manager);
int load_contacts(ContactManager *manager, const char *filename);
void list_contacts(const ContactManager *manager);

// simplified version of the ex02 for reason of time i don complete it

#endif
