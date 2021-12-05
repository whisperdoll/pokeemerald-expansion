LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruck
	.2byte 0


LittlerootTown_OnTransition::
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	return


LittlerootTown_OnFrame::
	map_script_2
	call LittlerootTown_EventScript_StepOffTruck
	return


LittlerootTown_EventScript_StepOffTruck::
	lockall
	delay 15
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	waitmovement 0
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
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

