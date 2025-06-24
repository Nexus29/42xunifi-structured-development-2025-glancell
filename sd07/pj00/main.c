/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:13:32 by glancell          #+#    #+#             */
/*   Updated: 2025/06/24 23:13:35 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact_manager.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_printf("Usage: %s <contacts_file.csv>\n", argv[0]);
        return 1;
    }

    ContactManager manager;
    init_manager(&manager);

    if (!load_contacts(&manager, argv[1])) {
        return 1;
    }

    list_contacts(&manager);
    free_manager(&manager);
    return 0;
}
