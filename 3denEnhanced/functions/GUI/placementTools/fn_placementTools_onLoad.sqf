/*
   Author: Revo

   Description:
   Initializes the Enh_Pattern GUI.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

params ["_display"];

uiNamespace setVariable ["Enh_PlacementTools_Display",_display];

["ShowPanelLeft",false] call BIS_fnc_3DENInterface;

if (isNil "Enh_PlacementTools_Center") then
{
   Enh_PlacementTools_Center = if (get3DENActionState "ToggleMap" == 1) then
   {
      (findDisplay 313 displayCtrl 51 ctrlMapScreenToWorld [0.5,0.5]) + [0];//ctrlMapScreenToWorld only returns [x,y], add another 0 to have [x,y,z]
   }
   else
   {
      screenToWorld [0.5,0.5];
   };
};

//Draw an icon where the center is
["Enh_PlacementTools_CenterIcon", "onEachFrame", 
{
	drawIcon3D["\A3\modules_f\data\iconStrategicMapMission_ca.paa",[1,0.1,1,1], Enh_PlacementTools_Center,1,1,0,"Center / Start Position"];
}] call BIS_fnc_addStackedEventHandler;

#define STEP_SIZE_INDEX (missionNamespace getVariable ["Enh_PlacementTools_stepSizeIndex",4])

//Setup toolbox
(_display displayCtrl 250) lbSetCurSel STEP_SIZE_INDEX;

//Set up sliders
private _stepSize = [0.0001,0.001,0.01,0.1,1,10,100] select STEP_SIZE_INDEX;

{
   _x params ["_idc","_varName","_defaultvalue"];
   private _ctrlSlider = _display displayCtrl _idc;
   _ctrlSlider sliderSetSpeed [_stepSize,_stepSize];
   _ctrlSlider sliderSetPosition (missionNamespace getVariable [_varName,_defaultValue]);

   //If variable was not declared, set it to default value
   if (isNil format ["%1",_varName]) then
   {
      missionNamespace setVariable [_varName,_defaultValue];
   };
} forEach [
   [10,"Enh_PlacementTools_Radius",50],
   [20,"Enh_PlacementTools_InitialAngle",0],
   [30,"Enh_PlacementTools_CentralAngle",360],
   [40,"Enh_PlacementTools_Spacing",10],
   [50,"Enh_PlacementTools_NumColums",2],
   [60,"Enh_PlacementTools_SpaceX",2],
   [70,"Enh_PlacementTools_SpaceY",2],
   [80,"Enh_PlacementTools_A",100],
   [90,"Enh_PlacementTools_B",100],
   [130,"Enh_PlacementTools_RectangleA",100],
   [140,"Enh_PlacementTools_RectangleB",100],
   [150,"Enh_PlacementTools_RectangleSpacing",2]
];

true