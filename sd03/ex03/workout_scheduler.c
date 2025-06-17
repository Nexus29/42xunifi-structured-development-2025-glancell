/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:30 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 15:46:52 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
    if (!username)
        return (NULL);
   
    struct UserData *data = get_user_data(username);
    if (!data)
        return (NULL);
   
    struct WorkoutPlan *plan = build_base_plan(data);
    if (!plan)
        return (free_user_data(data), NULL);

    plan = refine_plan(plan, data);
    if (!plan)
        return (free_user_data(data), NULL);

    int duration = determine_duration(plan);
    if (duration <= 0)
        return (free_workout_plan(plan), free_user_data(data), NULL);
    for (int day = 0; day < duration; day++)
	{
        assign_daily_exercises(plan, day);
        assign_daily_tips(plan, day);
    }
    free_user_data(data);
    return (plan);
}
