class StatusBar: ctrlControlsGroupNoScrollbars
{
	class Controls
	{
		class Version;//EditBox
		class TextZ;//Icon
		class Enh_SessionTime: Version
		{
			idc = 668;
			tooltip = $STR_ENH_statusBar_sessionTimer_tooltip;
			x = ORIGIN_X_STATUSBAR - 49 * GRID_W - SPACE_X;
			onLoad = "(_this # 0) ctrlEnable false";
			style = ST_CENTER + ST_NO_RECT;
		};
		//Selected entities counter, controls are hidden by default and managed by Enh_fnc_statusbar_entityCounter
		class Enh_NumberMarkers: Version
		{
			idc = 669;
			x = ORIGIN_X_STATUSBAR - 56 * GRID_W - 2 * SPACE_X;
			w = 7 * GRID_W;
			onLoad = "(_this # 0) ctrlSetFade 1; (_this # 0) ctrlEnable false; (_this # 0) ctrlSetText '0'";
			style = ST_CENTER + ST_NO_RECT;
		};
		class Enh_IconMarkers: TextZ
		{
			idc = 670;
			x = ORIGIN_X_STATUSBAR - 59 * GRID_W  - 2 * SPACE_X;
			onLoad = "(_this # 0) ctrlSetFade 1";
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
		};
		class Enh_NumberSystems: Enh_NumberMarkers
		{
			idc = 671;
			x = ORIGIN_X_STATUSBAR - 66 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconSystems: TextZ
		{
			idc = 672;
			x = ORIGIN_X_STATUSBAR - 69 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
		};
		class Enh_NumberWaypoints: Enh_NumberMarkers
		{
			idc = 673;
			x = ORIGIN_X_STATUSBAR - 76 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconWaypoints: TextZ
		{
			idc = 674;
			x = ORIGIN_X_STATUSBAR - 79 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
		};
		class Enh_NumberTriggers: Enh_NumberMarkers
		{
			idc = 675;
			x = ORIGIN_X_STATUSBAR - 86 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconTriggers: TextZ
		{
			idc = 676;
			x = ORIGIN_X_STATUSBAR - 89 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
		};
		class Enh_NumberGroups: Enh_NumberMarkers
		{
			idc = 677;
			x = ORIGIN_X_STATUSBAR - 96 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconGroups: TextZ
		{
			idc = 678;
			x = ORIGIN_X_STATUSBAR - 99 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
		};
		class Enh_NumberObjects: Enh_NumberMarkers
		{
			idc = 679;
			x = ORIGIN_X_STATUSBAR - 106 * GRID_W - 2 * SPACE_X;
		};
		class Enh_IconObjects: TextZ
		{
			idc = 680;
			x = ORIGIN_X_STATUSBAR - 109 * GRID_W - 2 * SPACE_X;
			text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
		};
	};
};