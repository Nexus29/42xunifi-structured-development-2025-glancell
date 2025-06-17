/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:41:27 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 15:20:42 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

// in input i receive an array of numbers,
// i indentify the segments of numbers with "-1" and i check if the segment
// is valid(they have to be strictly increasing consecutive numbers) or not
int	count_segments(const int *array, int size)
{
    int segment_count = 0;
    int in_segment = 0;
    int seq_length = 1;

	if(array == NULL || size <= 0)
		return (0);

	for(int i = 0; i < size; i++)
	{
		if(array[i] == -1)
			{
				if(in_segment && seq_length >= 3)
					segment_count++;
				in_segment = 0;
				seq_length = 1;
			}
		else
			{
				if(!in_segment)
					{
						in_segment = 1;
						seq_length = 1;
					}
				else
					{
						if(array[i] == array[i - 1] + 1)
							seq_length++;
						else
							seq_length = 1;
					}
			}
	}
	if(in_segment && seq_length >= 3)
		segment_count++;
	return (segment_count);
}

// int main(void) 
// {
//     // Simple test case with 3 segments, 2 of which have runs ≥ 3
//     int arr[] = {1, 2, -1, 4, 5, 6, 7, -1};
//     int size = sizeof(arr)/sizeof(arr[0]);
    
//     int count = count_segments(arr, size);
    
//     printf("Your function returned: %d\n", count);
    
//     return (0);
// }
