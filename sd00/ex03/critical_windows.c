/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:00:16 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 23:19:34 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

// after you at this fuction an array of at last 5 elements
// it check every window of 5 consecutives elements
// and analyzze if it is critic
int	count_critical_windows(const int *readings, int size)
{
	int count = 0;

	if(!readings || size < 5) return (0);

	for(int i = 0; i <= size - 5; i++)
	{
		int high = 0, sum = 0, valid = 1;
		for(int j = 0; j < 5; j++)
		{
			if(readings[i + j] > 150) valid = 0;
			if(readings[i + j] >= 70) high++;
			sum += readings[i + j];
		}
		if(valid && high >= 3 && sum / 5 >= 90)
			count++;
	}
	return (count);
}

// int main() {
//     // Test 1: Caso dato in precedenza
//     int readings1[] = {85, 92, 110, 70, 95, 88, 72, 130, 67, 91, 89};
//     int size1 = sizeof(readings1) / sizeof(readings1[0]);
//     printf("Test 1: %d finestre critiche\n", count_critical_windows(readings1, size1));

//     // Test 2: Tutti sotto i 70
//     int readings2[] = {60, 50, 40, 65, 69, 55, 68};
//     int size2 = sizeof(readings2) / sizeof(readings2[0]);
//     printf("Test 2: %d finestre critiche\n", count_critical_windows(readings2, size2));

//     // Test 3: Tutti sopra i 70, nessuno oltre 150, ma media bassa
//     int readings3[] = {70, 71, 72, 73, 74, 75, 76};
//     int size3 = sizeof(readings3) / sizeof(readings3[0]);
//     printf("Test 3: %d finestre critiche\n", count_critical_windows(readings3, size3));

//     // Test 4: Tutte le condizioni soddisfatte, molte finestre critiche
//     int readings4[] = {100, 120, 95, 98, 105, 110, 115, 108, 102, 101};
//     int size4 = sizeof(readings4) / sizeof(readings4[0]);
//     printf("Test 4: %d finestre critiche\n", count_critical_windows(readings4, size4));

//     // Test 5: Un valore > 150 rovina tutte le finestre
//     int readings5[] = {100, 120, 151, 98, 105, 110, 115};
//     int size5 = sizeof(readings5) / sizeof(readings5[0]);
//     printf("Test 5: %d finestre critiche\n", count_critical_windows(readings5, size5));

//     // Test 6: Array troppo corto (<5 elementi)
//     int readings6[] = {100, 110, 120};
//     int size6 = sizeof(readings6) / sizeof(readings6[0]);
//     printf("Test 6: %d finestre critiche\n", count_critical_windows(readings6, size6));

//     return 0;
// }
