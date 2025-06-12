/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:36:30 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 12:15:02 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
#define CRITICALPASSWORD_VALIDATOR_H_WINDOWS_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    VALID,
    INVALID
}	PwStatus;

// utils
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);

PwStatus	validate_password(const char *new_pw, const char *curr_pw);

#endif
