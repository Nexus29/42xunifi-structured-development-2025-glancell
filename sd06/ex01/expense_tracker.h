/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expense_tracker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:14:25 by glancell          #+#    #+#             */
/*   Updated: 2025/06/24 18:14:26 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#define MAX_EXPENSES 1000
#define MAX_CATEGORY_LEN 50
#define MAX_DESC_LEN 100
#define DATE_LEN 11

typedef struct {
    char date[DATE_LEN]; // YYYY-MM-DD format
    double amount;
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESC_LEN];
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// File operations
int load_expenses(ExpenseTracker *tracker, const char *filename);
int is_valid_date(const char *date);
int is_valid_amount(const char *amount_str);

// Filtering functions
void filter_by_category(const ExpenseTracker *tracker, const char *category);
void filter_by_date_range(const ExpenseTracker *tracker, 
                         const char *start_date, const char *end_date);

// Summary functions
void show_summary(const ExpenseTracker *tracker, 
                 const char *category_filter, 
                 const char *start_date, 
                 const char *end_date);

// User interface
void run_expense_tracker_ui(ExpenseTracker *tracker);

#endif