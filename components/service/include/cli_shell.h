/*
 * cli_shell.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Admin
 */

#ifndef COMPONENTS_SERVICE_INCLUDE_CLI_SHELL_H_
#define COMPONENTS_SERVICE_INCLUDE_CLI_SHELL_H_

#include <stddef.h>

typedef struct Cli_Shell_Cmd_t Cli_Shell_Cmd;

struct Cli_Shell_Cmd_t{
	  const char *command;
	  int (*handler)(int argc, char *argv[]);
	  const char *help;
};

typedef struct Cli_ShellImpl {
  //! Function to call whenever a character needs to be sent out.
  int (*send_char)(char c);
} sCliShellImpl;

void cli_shell_boot(const sCliShellImpl *impl);

//! Call this when a character is received. The character is processed synchronously.
void cli_shell_receive_char(char c);

//! Print help command
int cli_shell_help_handler(int argc, char *argv[]);

//! Prints a line then a newline
void cli_shell_put_line(const char *str);


extern const Cli_Shell_Cmd *const g_shell_commands;
extern const size_t g_num_shell_commands;

#endif /* COMPONENTS_SERVICE_INCLUDE_CLI_SHELL_H_ */
