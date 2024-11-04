// This class allow to manage admins
class Admins
{
	// SteamIDs of all admin players stored here
	private ref TStringArray m_admins;

	void Admins()
	{
		LoadAdmins();
	}
	
	private void LoadAdmins()
	{
		m_admins = new TStringArray;
		
		string path = "$profile:admins.txt";
		
		Debug.LogInfo("Loading admins from: " + path);

		FileHandle file = OpenFile(path, FileMode.READ);
		
		// If file doesnt exist, create it
		if ( file == 0 )
		{
			Debug.LogInfo("admins not found, create admin.txt in server profiles");
			file = OpenFile(path, FileMode.WRITE);
			
			FPrintln(file, "// This file contains SteamID64 of all server admins. Add them below.");
			FPrintln(file, "// Line starting with // means a comment line.");
			
			CloseFile(file);
			return;
		}

		Debug.LogInfo("Admins file found");

		string line;
		
		while ( FGets( file, line ) > 0 )
		{
			if (line.Length() < 2) continue;
			if (line.Get(0) + line.Get(1) == "//") continue;

			Debug.LogInfo("    Add amdin:" + line);

			m_admins.Insert(line);
		}
		
		CloseFile(file);
	}
	
	bool IsAdmin(PlayerBase player)
	{
		if(!player)
		{
			return false;
		}
		return m_admins.Find( player.GetIdentity().GetPlainId() ) != -1;
	}

};