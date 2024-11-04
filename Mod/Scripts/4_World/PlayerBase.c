// Script File
modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		switch (rpc_type)
		{
			case 19770001:
			{
				string detail_text;
				ctx.Read(detail_text);
				Print(detail_text);
				DayZPlayer player = GetGame().GetPlayer();
				DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( player ), false );
				
				break;
			}
		}
	}
}