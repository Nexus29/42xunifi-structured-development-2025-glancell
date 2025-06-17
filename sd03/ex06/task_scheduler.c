/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:03:51 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 16:09:01 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task_scheduler.h"

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    if (!tasks)
        return (NULL);

    struct TaskProfile *profile = profile_tasks(tasks);
    if (!profile)
        return (NULL);

    struct PriorityMap *priorities = compute_priorities_mock(profile);
    if (!priorities)
        return (free_task_profile(profile), NULL);

    int core_count = get_available_core_count();
    if (core_count <= 0)
        return (free_priority_map(priorities), free_task_profile(profile), NULL);

    struct ScheduleResult *result = create_schedule_result(core_count);
    if (!result)
        return (free_priority_map(priorities), free_task_profile(profile), NULL);
    for (int core_id = 0; core_id < core_count; core_id++)
	{
        int task_id = select_best_task(profile);
        if (task_id == -1)
            break;   
        update_schedule_entry(result, core_id, task_id);
    }
    free_priority_map(priorities);
    free_task_profile(profile);
    return (result);
}
