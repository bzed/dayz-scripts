class CarSpawner
{
	const string helpMsg = "Available types: offroad, olga, olgablack, sarka, gunter, truck, m1025";
	
	bool Spawn(PlayerBase player, string type)
	{
		type.ToLower();
		
		// Set car pos near player
		// TODO get cursor position
		vector pos = player.GetPosition();
		pos[0] = pos[0] + 5;
		pos[1] = pos[1] + 5;
		pos[2] = pos[2] + 5;

		Car car;
		bool truck = false;
		switch (type)
		{
			case "offroad":
				OffRoad(pos, player);
				break;
			case "olga":
				Olga(pos, player);
				break;
			case "olgablack":
				OlgaBlack(pos, player);
				break;
			case "sarka":
				Sarka(pos, player);
				break;
			case "gunter":
				Gunter(pos, player);
				break;
			case "truck":
				Truck(pos, player);
				break;
			case "m1025":
				M1025(pos, player);
				break;
			default:
				ChatMessage.SendPlayerMessage(player, "ERROR: Car type invalid.");
			case "help":
				ChatMessage.SendPlayerMessage(player, helpMsg);
				return false;
		}
		
		
		return true;
	}
	
	private void AddBaseAttachementsAndInit(Car car)
	{
		car.GetInventory().CreateAttachment("HeadlightH7");
		car.GetInventory().CreateAttachment("HeadlightH7");
		
		// Fill all the fluids
		car.Fill(CarFluid.FUEL, car.GetFluidCapacity(CarFluid.FUEL));
		car.Fill(CarFluid.OIL, car.GetFluidCapacity(CarFluid.OIL));
		car.Fill(CarFluid.BRAKE, car.GetFluidCapacity(CarFluid.BRAKE));
		car.Fill(CarFluid.COOLANT, car.GetFluidCapacity(CarFluid.COOLANT));
		
		// Set neutral gear
		car.GetController().ShiftTo(CarGear.NEUTRAL);
	}
	
	private void AddCarAttachements(Car car)
	{
		car.GetInventory().CreateAttachment("CarRadiator");
		car.GetInventory().CreateAttachment("CarBattery");
		car.GetInventory().CreateAttachment("SparkPlug");
		AddBaseAttachementsAndInit(car);
	}
		
	private void OffRoad(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("OffroadHatchback", pos));
		
		car.GetInventory().CreateAttachment("HatchbackTrunk");
		car.GetInventory().CreateAttachment("HatchbackHood");
		car.GetInventory().CreateAttachment("HatchbackDoors_CoDriver");
		car.GetInventory().CreateAttachment("HatchbackDoors_Driver");
		
		car.GetInventory().CreateAttachment("HatchbackWheel");
		car.GetInventory().CreateAttachment("HatchbackWheel");
		car.GetInventory().CreateAttachment("HatchbackWheel");
		car.GetInventory().CreateAttachment("HatchbackWheel");
		AddCarAttachements(car);

		ChatMessage.SendPlayerMessage(player, "OffroadHatchback spawned.");
	}
	
	private void OlgaCommon(Car car)
	{
		car.GetInventory().CreateAttachment("CivSedanWheel");
		car.GetInventory().CreateAttachment("CivSedanWheel");
		car.GetInventory().CreateAttachment("CivSedanWheel");
		car.GetInventory().CreateAttachment("CivSedanWheel");
	}
	
	private void Olga(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("CivilianSedan_Wine", pos));
		
		car.GetInventory().CreateAttachment("CivSedanHood_Wine");
		car.GetInventory().CreateAttachment("CivSedanTrunk_Wine");
		
		car.GetInventory().CreateAttachment("CivSedanDoors_Driver_Wine");
		car.GetInventory().CreateAttachment("CivSedanDoors_CoDriver_Wine");
		car.GetInventory().CreateAttachment("CivSedanDoors_BackLeft_Wine");
		car.GetInventory().CreateAttachment("CivSedanDoors_BackRight_Wine");
		OlgaCommon(car);
		AddCarAttachements(car);
		
		ChatMessage.SendPlayerMessage(player, "CivilianSedan_Wine spawned.");
	}
	
	private void OlgaBlack(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("CivilianSedan_Black", pos));
		
		car.GetInventory().CreateAttachment("CivSedanHood_Black");
		car.GetInventory().CreateAttachment("CivSedanTrunk_Black");
		
		car.GetInventory().CreateAttachment("CivSedanDoors_Driver_Black");
		car.GetInventory().CreateAttachment("CivSedanDoors_CoDriver_Black");
		car.GetInventory().CreateAttachment("CivSedanDoors_BackLeft_Black");
		car.GetInventory().CreateAttachment("CivSedanDoors_BackRight_Black");
		OlgaCommon(car);
		AddCarAttachements(car);
		
		ChatMessage.SendPlayerMessage(player, "CivSedan_Black spawned.");
	}
	
	private void Sarka(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("Sedan_02", pos));
		
		car.GetInventory().CreateAttachment("Sedan_02_Hood");
		car.GetInventory().CreateAttachment("Sedan_02_Trunk");
		
		car.GetInventory().CreateAttachment("Sedan_02_Door_1_1");
		car.GetInventory().CreateAttachment("Sedan_02_Door_1_2");
		car.GetInventory().CreateAttachment("Sedan_02_Door_2_1");
		car.GetInventory().CreateAttachment("Sedan_02_Door_2_2");
		
		car.GetInventory().CreateAttachment("Sedan_02_Wheel");
		car.GetInventory().CreateAttachment("Sedan_02_Wheel");
		car.GetInventory().CreateAttachment("Sedan_02_Wheel");
		car.GetInventory().CreateAttachment("Sedan_02_Wheel");
		AddCarAttachements(car);
		
		ChatMessage.SendPlayerMessage(player, "Sedan_02 spawned.");
	}
	
	private void Gunter(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("Hatchback_02_Black", pos));
		
		car.GetInventory().CreateAttachment("Hatchback_02_Hood_Black");
		car.GetInventory().CreateAttachment("Hatchback_02_Trunk_Black");
		
		car.GetInventory().CreateAttachment("Hatchback_02_Door_1_1_Black");
		car.GetInventory().CreateAttachment("Hatchback_02_Door_1_2_Black");
		car.GetInventory().CreateAttachment("Hatchback_02_Door_2_1_Black");
		car.GetInventory().CreateAttachment("Hatchback_02_Door_2_2_Black");
		
		car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
		car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
		car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
		car.GetInventory().CreateAttachment("Hatchback_02_Wheel");
		AddCarAttachements(car);
		
		ChatMessage.SendPlayerMessage(player, "Hatchback_02_Black spawned.");
	}
	
	private void AddTruckAttachements(Car car)
	{
		car.GetInventory().CreateAttachment("TruckBattery");
		car.GetInventory().CreateAttachment("SparkPlug");
		AddBaseAttachementsAndInit(car);
	}
	
	private void Truck(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("Truck_01_Covered", pos));
		
		car.GetInventory().CreateAttachment("Truck_01_Hood");
		
		car.GetInventory().CreateAttachment("Hatchback_02_Trunk_Black");
		
		car.GetInventory().CreateAttachment("Truck_01_Door_1_1");
		car.GetInventory().CreateAttachment("Truck_01_Door_1_2");
		car.GetInventory().CreateAttachment("Truck_01_Door_2_1");
		car.GetInventory().CreateAttachment("Truck_01_Door_2_2");
		
		car.GetInventory().CreateAttachment("Truck_01_Wheel");
		car.GetInventory().CreateAttachment("Truck_01_Wheel");
		car.GetInventory().CreateAttachment("Truck_01_Wheel"); // secour 1
		car.GetInventory().CreateAttachment("Truck_01_Wheel"); // secour 2
		
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		
		AddTruckAttachements(car);
		ChatMessage.SendPlayerMessage(player, "Truck_01_Covered spawned.");
	}
	
	private void M1025(vector pos, PlayerBase player)
	{
		// Spawn and build the car
		Car car = Car.Cast(GetGame().CreateObject("Offroad_02", pos));
		
		car.GetInventory().CreateAttachment("Offroad_02_Door_1_1");
		car.GetInventory().CreateAttachment("Offroad_02_Door_1_2");
		car.GetInventory().CreateAttachment("Offroad_02_Door_2_1");
		car.GetInventory().CreateAttachment("Offroad_02_Door_2_2");
		
		car.GetInventory().CreateAttachment("Offroad_02_Hood");
		car.GetInventory().CreateAttachment("Offroad_02_Trunk");
		
		car.GetInventory().CreateAttachment("Offroad_02_Wheel");
		car.GetInventory().CreateAttachment("Offroad_02_Wheel");
		car.GetInventory().CreateAttachment("Offroad_02_Wheel");
		car.GetInventory().CreateAttachment("Offroad_02_Wheel");
		car.GetInventory().CreateAttachment("Offroad_02_Wheel"); // secours
		
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");
		car.GetInventory().CreateAttachment("Truck_01_WheelDouble");

		car.GetInventory().CreateAttachment("GlowPlug");

		ChatMessage.SendPlayerMessage(player, "Truck_01_Covered spawned.");
	}
}