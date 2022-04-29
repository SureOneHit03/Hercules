/**
 * This file is part of Hercules.
 * http://herc.ws - http://github.com/HerculesWS/Hercules
 *
 * Copyright (C) 2012-2020 Hercules Dev Team
 * Copyright (C) Athena Dev Teams
 *
 * Hercules is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef API_API_H
#define API_API_H

#include "common/hercules.h"
#include "common/core.h" // CORE_ST_LAST
#include "common/db.h"
#include "common/mapindex.h"
#include "common/mmo.h"

#include <stdio.h>
#include <stdarg.h>

enum E_APISERVER_ST {
	APISERVER_ST_RUNNING = CORE_ST_LAST,
	APISERVER_ST_SHUTDOWN,
	APISERVER_ST_LAST
};

/*=====================================
* Interface : api.h
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct api_interface {

	/* vars */
	bool minimal;     ///< Starts the server in minimal initialization mode.
	bool scriptcheck; ///< Starts the server in script-check mode.

	/** Additional scripts requested through the command-line */
	char **extra_scripts;
	int extra_scripts_count;

	int retval;
	int count;

	bool ip_set;
	bool char_ip_set;
	bool login_ip_set;

	char db_path[256];

	char help_txt[256];
	char charhelp_txt[256];

	char wisp_server_name[NAME_LENGTH];

	char *NET_CONF_NAME;
	char *LOG_CONF_NAME;
	char *API_CONF_NAME;
	char *BATTLE_CONF_FILENAME;
	char *ATCOMMAND_CONF_FILENAME;
	char *SCRIPT_CONF_NAME;
	char *MSG_CONF_NAME;
	char *GRF_PATH_FILENAME;

	char autotrade_merchants_db[32];
	char autotrade_data_db[32];
	char npc_market_data_db[32];
	char npc_barter_data_db[32];
	char npc_expanded_barter_data_db[32];

	char default_codepage[32];
	char default_lang_str[64];
	uint8 default_lang_id;

	int server_port;
	char server_ip[32];
	char server_id[32];
	char server_pw[100];
	char server_db[32];
	struct Sql *mysql_handle;

	uint16 port;

	int ip_connections_limit;

	int (*setipport) (unsigned short map_index, uint32 ip, uint16 port);
	bool (*config_read) (const char *filename, bool imported);
	bool (*config_read_console) (const char *filename, struct config_t *config, bool imported);
	bool (*config_read_connection) (const char *filename, struct config_t *config, bool imported);
	bool (*config_read_inter) (const char *filename, struct config_t *config, bool imported);

	int (*check_connect_login_server) (int tid, int64 tick, int id, intptr_t data);

	void (*do_shutdown) (void);
};

#ifdef HERCULES_CORE
void api_defaults(void);
#endif // HERCULES_CORE

HPShared struct api_interface *api;

#endif /* API_API_H */
