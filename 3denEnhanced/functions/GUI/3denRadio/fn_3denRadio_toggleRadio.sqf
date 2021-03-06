/*
	Author: Revo

	Description:
	Enable or disables the radio and updates other controls accordingly.

	Parameter(s):
	STRING: _input - "BUTTON", "ONLOAD"

	Returns:
	BOOLEAN: true
*/

disableSerialization;

params ["_input"];

private _display = findDisplay 60000;
private _ctrlToggleRadio = _display displayCtrl 2300;
private _ctrlCurrentSong = _display displayCtrl 2200;
private _radioState = profileNamespace getVariable ["Enh_3denRadio_Enabled",false];
private _playlist = profileNamespace getVariable ["Enh_3denRadio_Playlist",[]];

_fnc_enableRadio =
{
	call Enh_fnc_3denRadio_selectNewSong;
	Enh_3denRadio_MusicEH = addMusicEventHandler ["MusicStop",
	{
		call Enh_fnc_3denRadio_selectNewSong;
	}];

	profileNamespace setVariable ["Enh_3denRadio_Enabled",true];
	_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_pause.paa";
};

_fnc_disableRadio =
{
	playMusic "";
	if !(isNil "Enh_3denRadio_MusicEH") then {removeMusicEventHandler["MusicStop",Enh_3denRadio_MusicEH]; Enh_3denRadio_MusicEH = nil};

	profileNamespace setVariable ["Enh_3denRadio_Enabled",false];
	profileNamespace setVariable ["Enh_3denRadio_CurrentSong",""];

	_ctrlCurrentSong ctrlSetText "";
	_ctrlToggleRadio ctrlSetText "\3denEnhanced\data\icon_play.paa";
};

if (_input isEqualTo "BUTTON" && _radioState) exitWith {call _fnc_disableRadio};
if (_input isEqualTo "BUTTON" && !_radioState && !(_playlist isEqualTo [])) exitWith {call _fnc_enableRadio};

//Check if radio is enabled but not running
if (_input isEqualTo "ONLOAD" && _radioState && isNil "Enh_3denRadio_MusicEH") then {call _fnc_enableRadio};
if (_input isEqualTo "ONLOAD" && (_playlist isEqualTo [])) then {call _fnc_disableRadio};

true