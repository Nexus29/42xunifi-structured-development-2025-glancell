/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:58:20 by glancell          #+#    #+#             */
/*   Updated: 2025/06/11 22:00:07 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRITICAL_WINDOWS_H
#define CRITICAL_WINDOWS_H

#include <unistd.h>
#include <stdio.h>

int count_critical_windows(const int *readings, int size);

#endif
