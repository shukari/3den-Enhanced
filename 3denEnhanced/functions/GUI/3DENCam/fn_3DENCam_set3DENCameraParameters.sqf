
/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Sets 3DEN camera parameters according to selected listBox entry.

   Parameter(s):
   0: CONTROL - ListBox
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlLB","_selectedIndex"];

private _data = call compile (_ctrlLB lbData _selectedIndex);

_data params ["_world","_camPosition","_camVectorDir","_camVectorUp"];

if !(_world isEqualTo worldName) exitWith
{
	[localize "STR_ENH_3DENCam_wrongWorld",1] call BIS_fnc_3DENNotification;
};

[true] call BIS_fnc_EXP_camp_setCinematicMode;

private _cam3DEN = get3DENCamera;

_cam3DEN setPos _camPosition;
_cam3DEN setVectorDirAndUp [_camVectorDir,_camVectorUp];

[false] call BIS_fnc_EXP_camp_setCinematicMode;

true