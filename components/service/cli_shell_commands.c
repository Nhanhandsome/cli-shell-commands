/*
 * cli_shell_command.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Admin
 */

#include <cli_shell.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <esp_system.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/*bool kv_store_write(const char *key, const void *val, uint32_t len) {
  // Stub
  return true;
}

int cli_cmd_kv_write(int argc, char *argv[]) {
  // We expect 3 arguments:
  // 1. Command name
  // 2. Key
  // 3. Value
  if (argc != 3) {
    cli_shell_put_line("> FAIL,1");
  }

  const char *key = argv[1];
  const char *value = argv[2];

  bool result = kv_store_write(key, value, strlen(value));
  if (!result) {
	  cli_shell_put_line("> FAIL,2");
  }
  cli_shell_put_line("> OK");
  return 0;
}*/

int cli_cmd_hello(int argc, char *argv[]) {
	cli_shell_put_line("Hello World!");
  return 0;
}
int cli_cmd_restart(int argc, char *argv[]){
	cli_shell_put_line("Board restart!");
	esp_restart();
	return 0;
}
static const Cli_Shell_Cmd s_shell_commands[] = {
  /*{"kv_write", cli_cmd_kv_write, "Write a Key/Value pair"},*/
  {"hello", cli_cmd_hello, "Say hello"},
  {"restart", cli_cmd_restart, "Restart board"},
  {"help", cli_shell_help_handler, "Lists all commands"},

};

const Cli_Shell_Cmd *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);
