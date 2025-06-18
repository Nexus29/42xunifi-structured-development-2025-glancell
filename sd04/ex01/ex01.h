/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:10:14 by glancell          #+#    #+#             */
/*   Updated: 2025/06/18 20:19:56 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_expense
{
	char *date;
	float amount;
	char *category;
	char *description;
}	t_expense;

typedef struct s_expense_tracker
{
	t_expense *expenses;
	int count;
}	t_expense_tracker;

t_expense_tracker	*load_expenses(const char *filename);
void				filter_by_category(t_expense_tracker *tracker, const char *query);
void				filter_by_date_range(t_expense_tracker *tracker, const char *start, const char *end);
void				show_summary(t_expense_tracker *tracker);

// objective of the program:
// Design a console program who can track and summarize the expenses
// the flowchart of the programm will probably be:
// load and validate expenses in a files
// filter everything in category/date range/all
// validate input
// Calculate totals, averages and category breakdowns
// Display the results
// exit
