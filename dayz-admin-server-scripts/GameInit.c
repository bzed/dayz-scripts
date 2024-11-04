class GameInit
{
	void CreatePlayer()
	{
		PlayerBase player;
		ItemBase item;
	
		// Create player
		player = PlayerBase.Cast( GetGame().CreatePlayer(NULL, "SurvivorF_Linda", "2200 10 2200", 0, "NONE") );
	
		// Spawn a black t-shirt
		item = player.GetInventory().CreateInInventory("TShirt_Black");
	
		// Spawn a green short jeans
		item = player.GetInventory().CreateInInventory("ShortJeans_Green");
		
		// Spawn a CombinationLock4
		item.GetInventory().CreateInInventory("CombinationLock4");
	
		// Spawn a ElectronicRepairKit
		item.GetInventory().CreateInInventory("ElectronicRepairKit");
	
		// Spawn a brown working boots
		item = player.GetInventory().CreateInInventory("WorkingBoots_Brown");
	
		// Spawn an apple in the t-shirt, don't redefine 'item' so we can still spawn other items in the t-shirt
		item.GetInventory().CreateInInventory("Apple");
	
		// Select player the client will be controlling
		GetGame().SelectPlayer(NULL, player);
	}
};
