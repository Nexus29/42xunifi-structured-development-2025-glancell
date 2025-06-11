/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:16:58 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 14:32:56 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

// it search for the first and last occurance of a values int an array of it
void    first_last(int array[], int size, int target, int *first, int *last)
{
	*first = *last = -1;

	if(array == NULL || size <= 0)
		return ;

	for(int i = 0; i < size; i++)
	{
		if(array[i] == target)
		{
			*first = (*first == -1) ? i : *first;
			*last = i;
		}

	}
}

// int main(void) 
// {
// 	int arr[] = {10, 20, 30, 20, 40, 20, 50};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	int target = 20;
// 	int first, last;

// 	first_last(arr, size, target, &first, &last);
// 	printf("Testing with:\n");
// 	printf("Array: [10, 20, 30, 20, 40, 20, 50]\n");
// 	printf("Target: 20\n");
// 	printf("First index: %d (should be 1)\n", first);
// 	printf("Last index: %d (should be 5)\n", last);
	
// 	return 0;
// }
