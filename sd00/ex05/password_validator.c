/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:39:13 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 12:27:53 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

// ft_strlen - custom strcmp return the len of a string
size_t ft_strlen(const char *str)
{
	size_t len = 0;
	while (str && str[len])
		len++;
	return (len);
}

// ft_strcmp - custom strcmp return the relation between 2 strings
int ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return ((s1 == s2) ? 0 : 1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// ft_isupper - custom isupper
int ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

// ft_islower - custom islower
int ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

// ft_isdigit - custom isdigit
int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// ft_strchr - custom strchr it search for the first occurance of a char in string
char *ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;
	while (*s) {
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	return (c == '\0') ? (char *)s : NULL;
}

PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
	const char *specials = "@#$%ˆ&*";

	if (!new_pw || ft_strlen(new_pw) < 8) return (INVALID);
	if (curr_pw && ft_strcmp(new_pw, curr_pw) == 0) return (INVALID);
	
	for (int i = 0; new_pw[i]; i++)
	{
		if (ft_isupper(new_pw[i])) has_upper = 1;
		else if (ft_islower(new_pw[i])) has_lower = 1;
		else if (ft_isdigit(new_pw[i])) has_digit = 1;
		else if (ft_strchr(specials, new_pw[i])) has_special = 1;
	}
	return ((has_upper && has_lower && has_digit && has_special) ? VALID : INVALID);
}

// int main()
// {
//     const char *curr = "OldPass123!";
//     const char *new = "NewPass123!";
	
//     PwStatus status = validate_password(new, curr);
//     printf("Password valid? %s\n", status == VALID ? "Yes" : "No"); // Should print No
//     return 0;
// }
