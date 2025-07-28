/**
 * @file    app.h
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   Main application logic declarations.
 *
 * This file declares the primary function that orchestrates the program's
 * execution flow. It serves as the entry point for the application's core
 * logic, separating the main function from the implementation details.
 */

#ifndef APP_H
#define APP_H

/**
 * RunProgram() - Executes the main application workflow.
 *
 * This function manages the entire process of the social network analysis.
 * It handles user interaction for file input, invokes the file parser,
 * generates the required output files, and manages the graph traversal
 * prompts and execution based on user-provided starting vertices.
 */
void RunProgram(void);

#endif /* APP_H */
