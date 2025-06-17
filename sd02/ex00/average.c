/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:28:14 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 14:40:21 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

// Validate inputs (0-100 range), ignore invalid values
float average(const int *array, int size)
{
	int sum = 0, count = 0;

	if(size <= 0 || array == NULL)
		return (0);

	for(int i = 0; i < size; i++)
	{
		if(array[i] >= 0 && array[i] <= 100)
		{
			sum += array[i];
			count++;
		}
	}
	if (count == 0) return (0);
	return ((float)sum / count);
}

// int main() {
// 	int test1[] = {50, 60, 70, 80, 90};    // all valid
	
// 	printf("Test 1: %.2f\n", average(test1, 5)); // 70.00
// 	printf("Test 5: %.2f\n", average(NULL, 5));  // 0.00(NULL)
	
// 	return (0);
// }
