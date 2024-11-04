static class Teleporter
{

	void TeleportPlayer(PlayerBase from, PlayerBase to, int distance)
	{
		if (!from)
		{
			return;
		}

		if (!to)
		{
			return;
		}
		
		vector toPos = to.GetPosition();

		float pos_x = toPos[0] + distance;
		float pos_z = toPos[2] + distance;
		float pos_y = GetGame().SurfaceY(pos_x, pos_z);
		
		vector pos = Vector(pos_x, pos_y, pos_z);
		
		from.SetPosition(pos);
	}
}