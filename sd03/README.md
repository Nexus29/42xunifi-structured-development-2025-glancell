Based on the PDF document, here's a step-by-step checklist of what you need to do:
1. Understand the Workshop Fundamentals

    Read through Chapters I-IV to understand:

        The three pillars of Structured Development (Programming, Design, Analysis)

        Key concepts of coupling (low is good) and cohesion (high is good)

        Evaluation criteria (reasoning behind choices is most important)

        General instructions about the exercises

2. Setup Your Development Environment

    Create a GitHub repository named: 42xunifi-structured-development-2025<your-intra-login>

    Set up SonarQube/SonarCloud (follow Chapter XIII instructions)

        Sign up with GitHub

        Import organization

        Authorize access to your repository

        Create project

3. Complete the Exercises

    There are 7 exercises (00-06) of increasing difficulty

    For each exercise:

        Create the required directory (ez00/, ez01/, etc.)

        Create the required files (.c and .h)

        Design the function hierarchy/control flow (no need for full implementations)

        Focus on clean, modular design with low coupling and high cohesion

Exercise Details:

    00: movie_planner
    Design function hierarchy for movie night planning (get preferences → find movies → build plan)

    01: food_order
    Design control logic for food delivery app (check status → create appropriate confirmation → send notification)

    02: music_organizer
    Design function hierarchy for music library organization (create library → scan files → process files → update library)

    03: workout_scheduler
    Design workout scheduling system (get user data → build plan → refine plan → assign exercises/tips)

    04: recipe_generator
    Design iterative recipe generation (get ingredients → get taste profile → generate/approve recipe loop)

    05: playlist_creator
    Design playlist generation (analyze mood → build/refine filters → fetch songs → create playlist)

    06: task_scheduler
    Design multicore task scheduler (profile tasks → compute priorities → assign to cores)

4. Submission Requirements

    Organize exercises in their respective directories

    Push all completed exercises to your GitHub repository before June 13 deadline

    Remember: Peer collaboration is encouraged but formal evaluations won't be available

5. Quality Assurance

    Use CCCC tool to analyze your code metrics:

        Cyclomatic complexity

        Module fan-out/fan-in

        Other design metrics

    Use SonarQube to get additional quality insights

Additional Notes:

    You don't need to implement full functions - focus on the design structure

    Code must compile but minor errors may be tolerated

    42 Norm is recommended but not required

    You can use AI tools sparingly (only after trying yourself and asking peers)

    The exercises are meant to challenge you - don't worry if you can't complete all

Remember that the primary focus is on your design decisions and reasoning, not just working code. Document your thought process in comments if helpful.
