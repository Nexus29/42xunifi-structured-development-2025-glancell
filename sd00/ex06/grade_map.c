/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:34:51 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 12:54:35 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

const char *plus_minus_mapper(int score)
{
	if(score < 0 || score > 100) return("Invalid");

	if(score >= 97) return("A+");
	if(score >= 93) return("A");
	if(score >= 90) return("A-");
	if(score >= 87) return("B+");
	if(score >= 83) return("B");
	if(score >= 80) return("B-");
	if(score >= 77) return("C+");
	if(score >= 73) return("C");
	if(score >= 70) return("C-");
	if(score >= 67) return("D+");
	if(score >= 63) return("D");
	if(score >= 60) return("D-");
	return("F");
}

const char *passfail_mapper(int score)
{
	if(score < 0 || score > 100) return("Invalid");
	
	return((score >= 60) ? "P" : "F");
}

const char *standard_mapper(int score)
{
	if(score < 0 || score > 100) return("Invalid");
	
	if(score >= 90) return("A");
	if(score >= 80) return("B");
	if(score >= 70) return("C");
	if(score >= 60) return("D");
	return("F");
}

// map grader based on 3 mappers
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if(!scores || !mapper || !mapped_grades || size <= 0) return ;

	for(int i = 0; i < size; i++)
		mapped_grades[i] = mapper(scores[i]);
}

// void print_grades(const int *scores, int size, const char *title, GradeMapper mapper)
// {
//     const char *grades[size];
    
//     map_scores(scores, size, mapper, grades);
    
//     printf("%s:\n", title);
//     for (int i = 0; i < size; i++) {
//         printf("%3d -> %s\n", scores[i], grades[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int scores[] = {95, 62, 78, 100, 55, 83, 91, 72};
//     int size = sizeof(scores)/sizeof(scores[0]);
    
//     print_grades(scores, size, "Plus/Minus Grading", plus_minus_mapper);
//     print_grades(scores, size, "Pass/Fail Grading", passfail_mapper);
//     print_grades(scores, size, "Standard Grading", standard_mapper);
    
//     return 0;
// }
