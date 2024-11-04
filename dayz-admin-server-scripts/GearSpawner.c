class GearSpawner
{
	static const string helpMsgGear = "Available types: mil, ghillie, medic, nv, svd, m4, akm, fx45, medieval";
	static const string helpMsgAmmo = "Available ammo types: svd, m4, akm, fx45";

	static bool SpawnGear(PlayerBase player, string type) 
	{
		type.ToLower();

		vector pos = player.GetPosition();
		pos[0] = pos[0] + 1;
		pos[1] = pos[1] + 1;
		pos[2] = pos[2] + 1;
		
		// DONT spawn a mag as attachment, is buggy ingame, spawn mags in ground instead
		EntityAI item;
		EntityAI subItem;

		switch (type)
		{
			case "medieval":
				item = player.SpawnEntityOnGroundPos("SeaChest", pos);
				item.GetInventory().CreateEntityInCargo("Ammo_ImprovisedBolt_2");
				item.GetInventory().CreateEntityInCargo("Ammo_ImprovisedBolt_2");
				item.GetInventory().CreateEntityInCargo("Ammo_ImprovisedBolt_2");
				item.GetInventory().CreateEntityInCargo("MedievalBoots");
				item.GetInventory().CreateEntityInCargo("Sword");
				item.GetInventory().CreateEntityInCargo("WoolGloves_White");
				item.GetInventory().CreateEntityInCargo("Chainmail");
				item.GetInventory().CreateEntityInCargo("Chainmail_Coif");
				item.GetInventory().CreateEntityInCargo("Chainmail_Leggings");
				item.GetInventory().CreateEntityInCargo("Mace");
				//item.GetInventory().CreateEntityInCargo("NorseHelmet");

				item = player.SpawnEntityOnGroundPos("SeaChest", pos);
				item.GetInventory().CreateEntityInCargo("Crossbow_Wood");
				item.GetInventory().CreateEntityInCargo("Chestplate");
				item.GetInventory().CreateEntityInCargo("BandageDressing");
				item.GetInventory().CreateEntityInCargo("BandageDressing");
				item.GetInventory().CreateEntityInCargo("BandageDressing");
				item.GetInventory().CreateEntityInCargo("TunaCan");
				item.GetInventory().CreateEntityInCargo("TunaCan");
				item.GetInventory().CreateEntityInCargo("TunaCan");
				break;

			case "mil":
				// Head
				item = player.SpawnEntityOnGroundPos("Mich2001Helmet", pos);
				
				subItem = item.GetInventory().CreateAttachment("NVGoggles");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				player.SpawnEntityOnGroundPos("GP5GasMask", pos);
				
				// Vest
				item = player.SpawnEntityOnGroundPos("SmershVest", pos);
				item.GetInventory().CreateAttachment("SmershBag");
				
				// Body
				player.SpawnEntityOnGroundPos("TTsKOJacket_Camo", pos);
				player.SpawnEntityOnGroundPos("TTSKOPants", pos);
				player.SpawnEntityOnGroundPos("OMNOGloves_Gray", pos);
				
				// Waist
				item = player.SpawnEntityOnGroundPos("MilitaryBelt", pos);
				item.GetInventory().CreateAttachment("Canteen");
				item.GetInventory().CreateAttachment("PlateCarrierHolster");
				
				subItem = item.GetInventory().CreateAttachment("NylonKnifeSheath");
				subItem.GetInventory().CreateAttachment("CombatKnife");
				
				// Legs
				item = player.SpawnEntityOnGroundPos("MilitaryBoots_Black", pos);
				item.GetInventory().CreateAttachment("CombatKnife");
				
				// Back
				player.SpawnEntityOnGroundPos("AliceBag_Camo", pos);

				break;

			case "ghillie":
				player.SpawnEntityOnGroundPos("GhillieAtt_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieAtt_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieBushrag_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieHood_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieSuit_Woodland", pos);
				player.SpawnEntityOnGroundPos("GhillieTop_Woodland", pos);
				
				break;
				
			case "svd":
				item = player.SpawnEntityOnGroundPos("SVD", pos);
				
				item.GetInventory().CreateAttachment("AK_Suppressor");
				
				subItem = item.GetInventory().CreateAttachment("PSO1Optic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				item = player.SpawnEntityOnGroundPos("KazuarOptic", pos);
				item.GetInventory().CreateAttachment("Battery9V");				
				
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", pos);
				
				break;
			
			case "m4":
				item = player.SpawnEntityOnGroundPos("M4A1", pos);
				
				item.GetInventory().CreateAttachment("M4_Suppressor");
				item.GetInventory().CreateAttachment("M4_OEBttstck");
				item.GetInventory().CreateAttachment("M4_RISHndgrd");
				
				subItem = item.GetInventory().CreateAttachment("ReflexOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
		
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_STANAG_30Rnd", pos);
				
				player.SpawnEntityOnGroundPos("ACOGOptic", pos);
				
				break;
				
			case "akm":
				item = player.SpawnEntityOnGroundPos("AKM", pos);
				
				item.GetInventory().CreateAttachment("AK_Suppressor");
				item.GetInventory().CreateAttachment("AK_WoodBttstck");
				item.GetInventory().CreateAttachment("AK_RailHndgrd");
				
				subItem = item.GetInventory().CreateAttachment("KobraOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("UniversalLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				item = player.SpawnEntityOnGroundPos("PSO1Optic", pos);
				item.GetInventory().CreateAttachment("Battery9V");

				player.SpawnEntityOnGroundPos("Mag_AKM_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_30Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_Drum75Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_AKM_Drum75Rnd", pos);

				break;
			
			case "fx45":
				item = player.SpawnEntityOnGroundPos("FNX45", pos);
				
				item.GetInventory().CreateAttachment("PistolSuppressor");
				
				subItem = item.GetInventory().CreateAttachment("FNP45_MRDSOptic");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				subItem = item.GetInventory().CreateAttachment("TLRLight");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				player.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", pos);
				
				break;
			
			case "nv":
				item = player.SpawnEntityOnGroundPos("NVGHeadstrap", pos);
				
				subItem = item.GetInventory().CreateAttachment("NVGoggles");
				subItem.GetInventory().CreateAttachment("Battery9V");
				
				break;
				
			case "medic":
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("BandageDressing", pos);
				player.SpawnEntityOnGroundPos("SalineBagIV", pos);
				player.SpawnEntityOnGroundPos("Morphine", pos);
				player.SpawnEntityOnGroundPos("Epinephrine", pos);
				
				break;
				
			case "mosin":
				break;
				
			case "sks":
				break;
				
			default:
				ChatMessage.SendPlayerMessage(player, "Invalid gear type.");
			case "help":
				ChatMessage.SendPlayerMessage(player, helpMsgGear);
				return false;
		}
		
		return true;
	}
	
	static bool SpawnAmmo(PlayerBase player, string type, int amount = 1)
	{
		type.ToLower();

		vector pos = player.GetPosition();
		pos[0] = pos[0] + 1;
		pos[1] = pos[1] + 1;
		pos[2] = pos[2] + 1;
		
		string mag;
		string ammo;
		
		switch (type)
		{
			case "svd":
				mag = "Mag_SVD_10Rnd";
				ammo = "AmmoBox_762x54Tracer_20Rnd";
				break;
			
			case "m4":
				mag = "Mag_STANAG_30Rnd";
				ammo = "AmmoBox_556x45Tracer_20Rnd";
				break;
				
			case "akm":
				mag = "Mag_AKM_30Rnd";
				ammo = "AmmoBox_762x39Tracer_20Rnd";
				break;
			
			case "fx45":
				mag = "Mag_FNX45_15Rnd";
				ammo = "AmmoBox_45ACP_25rnd";
				break;
			
			default:
				ChatMessage.SendPlayerMessage(player, "Invalid ammo type.");
			case "help":
				ChatMessage.SendPlayerMessage(player, helpMsgAmmo);
				return false;
		}
		
		for (int i = 0; i < amount; i++)
		{
			player.SpawnEntityOnGroundPos(mag, pos);
			player.SpawnEntityOnGroundPos(ammo, pos);
		}
		
		return true;
	}
	
}