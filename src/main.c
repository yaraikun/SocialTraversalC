/**
 * @file    main.c
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   The primary entry point of the Social Network program.
 *
 * This file contains only the `main()` function. Its sole purpose is to call
 * the `RunProgram()` function from the `app` module. This design separates the
 * standard C language entry point from the application's core logic,
 * promoting modularity and clarity.
 */

#include "app.h"

/**
 * main() - The main entry point of the program.
 *
 * Initializes and starts the graph processing application by calling
 * RunProgram().
 *
 * Return: 0 on successful completion.
 */
int main()
{
    RunProgram();
    return 0;
}
