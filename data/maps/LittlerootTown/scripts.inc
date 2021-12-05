LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0


LittlerootTown_OnTransition::
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	return


LittlerootTown_OnFrame::
	call LittlerootTown_EventScript_StepOffTruck
	return


LittlerootTown_EventScript_StepOffTruck::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	releaseall
	return


LittlerootTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_OnWarp::
	return

