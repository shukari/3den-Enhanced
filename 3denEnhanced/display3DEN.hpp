class Display3DEN
{
	class ContextMenu: ctrlMenu
	{
		class Items
		{
			#include "contextMenu.hpp"
		};
	};
	class Controls
	{
		#include "statusbar.hpp"
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				items[] += {"Enh_3rdPartyTools","Enh_About"};//new main categories
				#include "menuStrip_3rdPartyTools.hpp"
				#include "menuStrip_about.hpp"
				#include "menuStrip_tools.hpp"
				#include "menuStrip_help.hpp"
			};
		};
	};
};