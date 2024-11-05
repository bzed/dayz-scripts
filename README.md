# dayz-scripts
Custom scripts for DayZ Standalone Server

init.c - Server intialization sample script for Custom Mission in offline mod => https://github.com/Arkensor/DayZCommunityOfflineMode.

init.namalsk.c - Server intialization sample for Namalsk server script for Custom Mission in Server. Should be located under the mission folder.

start.bat - Server startup/control/restart script. Should be in the server root dir, same than the server executable.

serverDZ.cfg - Server general configuration file. Should be located in server root. Needs customization.

If you found these scripts useful, please give a STAR and even FOLLOW the repository to receive upcoming changes and updates!

# Init.c features

- Server side built-in commands using chat
- Spawning vehicles (few predefined vehicles)
- Spawning items/weapons/gear/ammo (customizable)
- Killing players, committing suicide
- Teleporting from/to coordinates
- Player listing and stats/details
- God mode / restore health
- Admin list read in startup from text file
- Admin FreeCamera (Need to be part of a server/client mod to work, otherwise nothing will apen when using /free command)

# Getting started

Start off by installing the DayZ Standalone server (e.g. from [Steam](https://store.steampowered.com/about/))

The server installation path depends e.g. on your Steam settings

Once installed, simply copy over the files contained in this repo:
  [start.bat](start.bat), [serverDZ.cfg](serverDZ.cfg) into the server folder root 
  
  (e.g. C:\Program Files (x86)\Steam\steamapps\common\DayZServer\)
  
  [init.namalsk.c](init.namalsk.c) into the Mission folder and rename it init.c
  
  (e.g. C:\Program Files (x86)\Steam\steamapps\common\DayZServer\mpmissions\regular.namalsk\)
  
  You might need to override the existing init.c file (or keep it as backup and rename it as init.c.old)

  Create a folder named dayz-admin-server-scripts into server root folder so server have access to them and copy content of [dayz-admin-server-scripts](dayz-admin-server-scripts)
  
  (e.g. C:\Program Files (x86)\Steam\steamapps\common\DayZServer\)

Configure the server by editing the [serverDZ.cfg](serverDZ.cfg) file to your liking (e.g. server name, password player count, ..)

To access chat commands, you need to add the player's Steam64ID (in decimal format) to the admins.txt file. You can find the user's SteamID using any any Steam profile info webpage, e.g. [SteamFinder](https://www.steamidfinder.com/). E.g. steamID64 (Dec): 76561197960287930

Copy the ID(s) over into the admins.txt file. The file is located in the user profile folder (e.g. C:\Users\USERNAME\AppData\Local\DayZ\admins.txt, aka %USERPROFILE%\AppData\Local\DayZ\admins.txt in Windows). Create the file if it does not exist yet (it is automatically created during the first launch of the server, so you should first move on to launch the server at least once before defining the admins, and then restart the server after. Simply insert the IDs into the file, separated by newlines and save the file.

Once finished, launch off the server by running [start.bat](start.bat). A Server GUI log window opens and the server should start in a few moments. Ensure a log message says that the cloud Hive is connected, and forward required server ports to ensure your server will be listed in the public server listing.

Once the server is up and running, test your server by launching DayZ and connecting to your server using the server menu.

Once you are in the game, you can issue chat commands by sending a chat message starting with '/' (e.g. '/help').

# Create a mod for FreeCam
If you want FreeCam to work, you will need a mod on your server
From Folder [Mod/Scripts](Mod/Scripts) you can create your own server mod thanks to DayZTools
(TODO: Publish a minimalist mod for FreeCamera, so admins will only need to add this mod)

# Special mentions

Thanks [antonioganea](https://github.com/antonioganea/), great job with creating a code injector [tci](https://github.com/antonioganea/tci) to allow dynamic updates in the server code logic and lot faster and more robust development process for the server-side scripting.
