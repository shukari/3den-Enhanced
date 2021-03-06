#define DIALOG_W 160
#define DIALOG_H 111

class Enh_TextureFinder
{
	idd = ENH_IDD_TEXTUREFINDER;
	movingEnable = true;
	onLoad = "[] spawn Enh_fnc_textureFinder_findTextures";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = $STR_ENH_textureFinder_header;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class TextureList: ctrlListbox
		{
			idc = 1500;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = 52 * GRID_H;
			onLBSelChanged = "((findDisplay 140000) displayCtrl 1200 ) ctrlsetText ((_this # 0) lbText (lbCurSel (_this # 0)))";
			onKeyDown = "_this call Enh_fnc_textureFinder_exportTexturePath";
		};
		class TexturePreview: ctrlStaticPictureKeepAspect
		{
			idc = 1200;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 58 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = 40 * GRID_H;
			colorBackground[] = {1,1,1,1};
		};
		class ProgessText: ctrlStatic
		{
			idc = 1002;
			style = ST_CENTER;
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 99 * GRID_H;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Progress: ctrlProgress
		{
			idc = 1001;
			x = CENTERED_X(DIALOG_W - 2);
			y = DIALOG_TOP + 104 * GRID_H;
			w = (DIALOG_W - 2) * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class UpdateList: ctrlButton
		{
			text = $STR_ENH_textureFinder_updateList;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
			action = "[] spawn Enh_fnc_textureFinder_fillTextureLB";
		};
		class SearchTextBox: ctrlEdit
		{
			idc = 1600;
			x = CENTERED_X(DIALOG_W) + 1 * GRID_W;
			y = DIALOG_TOP + 58 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class SearchButton: ctrlButtonSearch
		{
			idc = 1700;
			x = CENTERED_X(DIALOG_W) + 31 * GRID_W;
			y = DIALOG_TOP + 58 * GRID_H;
			w = 5 * GRID_W;
			h = CTRL_DEFAULT_H;
			onButtonClick = "_this call Enh_fnc_textureFinder_search";
		};
		class Filter: ctrlToolbox
		{
			x = CENTERED_X(DIALOG_W) + 63 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 65 * GRID_W;
			h = CTRL_DEFAULT_H;
            rows = 1;
            columns = 3;
            strings[] = 
            {
                $STR_ENH_textureFinder_filterAll,
                $STR_ENH_textureFinder_filterJPG,
				$STR_ENH_textureFinder_filterPAA
            };
            values[] = {0,1,2};
			onLoad = "params ['_ctrl']; _ctrl lbSetCurSel 0; Enh_TextureFinder_Filter = 0";//Default value
			onToolBoxSelChanged  = "params ['_ctrl']; Enh_TextureFinder_Filter = lbCurSel _ctrl";
        };
		class Close: ctrlButtonClose
		{
			x = CENTERED_X(DIALOG_W) + 129 * GRID_W;
			y = DIALOG_TOP + 110 * GRID_H;
			w = 30 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};