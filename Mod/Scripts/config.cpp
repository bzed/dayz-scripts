class CfgPatches
{
	class DayzAdminServerScripts
	{
		requiredAddons[] =
		{
			// ""
		};
	};
};

class CfgMods
{
	class DayzAdminServerScriptsMod
	{
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "Scripts/4_World" };
			};
		};
	};
};