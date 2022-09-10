idf_component_register(SRCS "service.c"
							"cli_shell.c"
							"cli_shell_commands.c"
					REQUIRES esp_system
                    INCLUDE_DIRS "include")

