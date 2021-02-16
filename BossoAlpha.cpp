#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
//#include "./VSVillage.cpp"
#include "./RoadToTheCastle.cpp"
#include "./Bosso_v.2.1.cpp"


// To BossoAlpha.cpp einai to kentriko file pou syndiazei ola ta ta ypoloipa cpp (VSvillage,RoadToTheCastle,Bossov2.1) kai 
// to file apo to opoio ksekinaei to game.

int main(){ //H main kalei ta enarktiria functions twn diaforetikwn included cpps allazontas kai merikes global variables opou xriastei.
	int MapSwitch;
	printf("\n\nWelcome to Bosso!\nThis game is played with arrows to move, 'Spacebar' to interact and 'I' to open inventory.\n\n");
	system("pause");
	MapSwitch=ExecutionVil();
	// MapSwitch=3;
	
	
	while(1){

	switch(MapSwitch){

		case 1:
			system("cls");
			if(!theend){
			MapSwitch=RoadToTheCastle();
			}
			else{
				return 0;
			}
		break;

		case 2:
			system("cls");
			MapSwitch=ExecutionVil();

		break;

		case 3:
			system("cls");
			MapSwitch=Bossario();
			VillageKey==1? VSKey=1:0;
			VillageKey==1? vkeyrtc=1:0;
			if(PlayerDeath){
				if (checkpoint){
					respawn=1;
					system("cls");
					printf("\n\n\n\nRespawn Imminent...Please wait!\n\n\n");
					system("pause");
					PlayerDeath=0;
					newtry=1;
					Madahealth=10;
				}
				else{
					system("cls");
					printf("\n\n\n\nWASTED\n\n\n");
					system("pause");
					MapSwitch=0;
				}
			}
			// ((PlayerDeath==1) && (checkpoint==1))? respawn=1:0;
			// ((PlayerDeath==1) && (checkpoint==0))? respawn=1:0;
			ChangeToCastle=0;

		break;
		

		default:
			return 0;
		break;

	}
	
	}

	return 0;
}


   
  
