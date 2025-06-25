/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:14:51 by glancell          #+#    #+#             */
/*   Updated: 2025/06/25 11:08:11 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 50
#define MAX_CITY_LEN 50
#define MAX_ADDRESS_LEN 100

typedef struct
{
    int id;
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    char city[MAX_CITY_LEN];
    char address[MAX_ADDRESS_LEN];
} Contact;

typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int count;
    int max_id;
} ContactManager;

// File operations
int load_contacts(ContactManager *manager, const char *filename);
int save_contacts(ContactManager *manager, const char *filename);

// Validation functions
int is_valid_email(const char *email);
int is_valid_phone(const char *phone);
int is_valid_id(const char *id_str, ContactManager *manager);

// CRUD operations
void add_contact(ContactManager *manager);
void update_contact(ContactManager *manager);
void delete_contact(ContactManager *manager);

// Search functions
void list_all_contacts(const ContactManager *manager);
void search_by_name(const ContactManager *manager, const char *query);
void search_by_city(const ContactManager *manager, const char *query);

// User interface
void run_contact_manager_ui(ContactManager *manager);

#endif