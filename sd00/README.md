1. Setup and Preparation

    Create a GitHub repository named 42xunifi-structured-development-2025-<your-intra-login>

    Set up SonarQube/SonarCloud following the instructions in Chapter XVI (pages 17-18)

    Organize your repository with folders for each exercise (ez00/, ez01/, etc.)

2. Exercise Completion (Core)

Complete the 10 main exercises in order:
Exercise 00: Average (page 7)

    Create average.c and average.h in ez00/

    Implement function float average(const int *arr, int size)

    Validate inputs (0-100 range), ignore invalid values

    Calculate average of valid values

Exercise 01: first_last (page 8)

    Create first_last.c and first_last.h in ez01/

    Implement function void first_last(int arr[], int size, int target, int *first, int *last)

    Find first and last occurrence indices of target

    Return -1 if target not found

Exercise 02: segmented_runs (page 9)

    Create segmented_runs.c and segmented_runs.h in ez02/

    Implement function int count_segments(const int *arr, int size)

    Identify segments separated by -1

    Count segments with increasing sequences of ≥3 consecutive numbers

Exercise 03: critical_windows (page 10)

    Create critical_windows.c and critical_windows.h in ez03/

    Implement function int count_critical_windows(const int *readings, int size)

    Analyze 5-day sliding windows

    Check all three conditions for critical windows

Exercise 04: filesystem (page 11)

    Create filesystem.c and filesystem.h in ez04/

    Implement basic file system functions:

        create_file(), create_folder()

        add_child(), get_children(), get_sibling()

Exercise 05: password_validator (page 12)

    Create password_validator.c and password_validator.h in ez05/

    Implement function PtStatus validate_password(const char *new_pw, const char *curr_pw)

    Check all strength rules

    Compare with current password

Exercise 06: grade_mapping (page 13)

    Create grade_map.c and grade_map.h in ez06/

    Implement function void map_scores(const int *scores, int size, GradeMapper mapper, const char *mapped_grades)

    Support three different mapping strategies

3. Bonus Exercises (Optional)

Complete if you have time:
Exercise 07: filesystem manager (bonus) (page 14)

    Extend filesystem with:

        compute_total_size()

        print_structure()

        free_filesystem()

Exercise 08: Password Validator (bonus) (page 15)

    Enhance password validator with:

        History of last 3 passwords

        Edit distance check

        Expanded return status

Exercise 09: Grade Mapping (bonus) (page 16)

    Add grade distribution features:

        compute_distribution()

        print_distribution()

        free_distribution()

4. Submission

    Push all completed exercises to your GitHub repository

    Ensure everything is pushed by June 13 deadline

    Verify your solutions with SonarQube analysis
