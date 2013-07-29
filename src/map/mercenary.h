// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder
#ifndef _MERCENARY_H_
#define _MERCENARY_H_
#include "status.h" // struct status_data, struct status_change
#include "unit.h" // struct unit_data
// number of cells that a mercenary can walk to from it's master before being warped
#define MAX_MER_DISTANCE 15
enum {
	ARCH_MERC_GUILD,
	SPEAR_MERC_GUILD,
	SWORD_MERC_GUILD,
};
struct s_mercenary_db {
	int class_;
	char sprite[NAME_LENGTH], name[NAME_LENGTH];
	unsigned short lv;
	short range2, range3;
	struct status_data status;
	struct view_data vd;
	struct {
		unsigned short id, lv;
	} skill[MAX_MERCSKILL];
};
struct mercenary_data {
	struct block_list bl;
	struct unit_data ud;
	struct view_data *vd;
	struct status_data base_status, battle_status;
	struct status_change sc;
	struct regen_data regen;
	struct s_mercenary_db *db;
	struct s_mercenary mercenary;
	char blockskill[MAX_SKILL];

	struct map_session_data *master;
	int contract_timer;
	
	unsigned devotion_flag : 1;
	unsigned int masterteleport_timer;
};







/**
 * atcommand.c required
 **/


/*=====================================
* Interface : mercenary.h 
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct mercenary_interface {
	/* vars */
	
	struct s_mercenary_db mercenary_db[MAX_MERCENARY_CLASS];
	/* funcs */
	
	bool (*merc_class) (int class_);
	struct view_data * (*merc_get_viewdata) (int class_);
	
	int (*merc_create) (struct map_session_data *sd, int class_, unsigned int lifetime);
	int (*merc_data_received) (struct s_mercenary *merc, bool flag);
	int (*save) (struct mercenary_data *md);
	
	void (*heal) (struct mercenary_data *md, int hp, int sp);
	int (*dead) (struct mercenary_data *md);
	
	int (*merc_delete) (struct mercenary_data *md, int reply);
	void (*merc_contract_stop) (struct mercenary_data *md);
	
	int (*get_lifetime) (struct mercenary_data *md);
	int (*get_guild) (struct mercenary_data *md);
	int (*get_faith) (struct mercenary_data *md);
	int (*set_faith) (struct mercenary_data *md, int value);
	int (*get_calls) (struct mercenary_data *md);
	int (*set_calls) (struct mercenary_data *md, int value);
	int (*kills) (struct mercenary_data *md);
	
	int (*checkskill) (struct mercenary_data *md, uint16 skill_id);
	int (*read_mercenarydb) (void);
	int (*read_skilldb) (void);
	
	int (*do_init_mercenary) (void);
} mercenary_s;

struct mercenary_interface *mercenary;

void mercenary_defaults(void);

#endif /* _MERCENARY_H_ */
