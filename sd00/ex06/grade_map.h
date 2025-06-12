/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:32:10 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 12:50:03 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAP_H
#define GRADE_MAP_H

#include <stdio.h>

typedef const char *(*GradeMapper)(int score);

const char	*plus_minus_mapper(int score);
const char	*passfail_mapper(int score);
const char	*standard_mapper(int score);

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
