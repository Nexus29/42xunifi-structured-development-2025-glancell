/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:32:54 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:38:00 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
    if (!request)
        return (0);
        
    int status = check_restaurant_status(request);
    struct OrderConfirmation *confirmation = NULL;
    if (status)
        confirmation = create_standard_confirmation();
	else
        confirmation = create_preorder_confirmation();

    if (!confirmation)
        return (0);

    send_confirmation_notification(confirmation);
    free(confirmation);
    return (1);
}
