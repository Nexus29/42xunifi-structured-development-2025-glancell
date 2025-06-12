/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:47 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:54:18 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ing = get_current_ingredients();
    if (!ing)
        return (NULL);

    struct TasteProfile *taste = get_user_taste_profile();
    if (!taste)
        return (free_ingredients(ing), NULL);

    struct Recipe *recipe = NULL;
    int approved = 0;
    while (!approved)
	{
        if (recipe)
            free_recipe(recipe);

        recipe = create_recipe(ing, taste);
        if (!recipe)
            return (free_ingredients(ing), free_taste_profile(taste), NULL);
        approved = get_user_approval(recipe);
    }

    free_ingredients(ing);
    free_taste_profile(taste);
    return (recipe);
}
