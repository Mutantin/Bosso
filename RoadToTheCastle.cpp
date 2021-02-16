#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iostream>
using namespace std;
#include "./VSVillage.cpp"


int pxRTC,pyRTC,br1x,br2x,br1y,br2y,cgatex,cgatey;
bool checkpoint,tempo,ChangeToVil,ChangeToCastle,vkeyrtc,respawn=0;
char rtcmap[20][100];
char rtcmap1D[1500];



void D2toD1_rtc(){  //Antistoixo tou D2toD1 sto VSVillage.cpp. Metatrepei disdiastato se monodiastato pinaka.
    int m=0;
    
     for (int i=0;i<20;i++){
        for(int y=0;y<100;y++){

            if(rtcmap[pxRTC-1][pyRTC]=='|'){
                ChangeToVil=1;
            }
            
            else if(rtcmap[pxRTC][pyRTC+1]=='='){
                ChangeToCastle=1;
                cgatex=pxRTC;
                cgatey=pyRTC;
            } 
            
            if(rtcmap[i][y]=='X' && (i!=pxRTC || y!=pyRTC)){
                if((i==br1x) && (y==br1y)){
                    rtcmap[i][y]='[';
                }
                else if((i==br2x) && (y==br2y)){
                    rtcmap[i][y]=']';
                }
                else if((rtcmap[i][y-1]=='[') || (rtcmap[i][y+1]==']')){
                    rtcmap[i][y]='*';
                }
                else{
                rtcmap[i][y]=' ';
                }
            }
            if(pxRTC==i && pyRTC==y){
                rtcmap[i][y]='X';
            }


            if (rtcmap[i][y]==NULL){
                break;
            }

            rtcmap1D[m]=rtcmap[i][y];
            m++;
        }
    }
    if (rtcmap[pxRTC][pyRTC-1]=='['){
        checkpoint=1;
    }
}
void printarray_rtc(){ //Emfanizei to map.
    system("cls");
    printf("%s",rtcmap1D);
    if(checkpoint && (!tempo)){
        printf("\n\n\nCHECKPOINT REACHED!\n\n\n");
        system("pause");
        tempo=1;
    }
}

void player_rtc(){ //Function gia tin metakinisi tou paikti (mesw switch kai getch).
    char ch;
    while(!ChangeToVil && !ChangeToCastle){
        ch=getch();

        switch(ch){

            case 77:
            if ((rtcmap[pxRTC][pyRTC+1]!=' ') && (rtcmap[pxRTC][pyRTC+1]!='[') && (rtcmap[pxRTC][pyRTC+1]!=']') && (rtcmap[pxRTC][pyRTC+1]!='*')){
                D2toD1_rtc();
                printarray_rtc();
                Sleep(100);
            }
            else{	
            
                pyRTC++;
                D2toD1_rtc();
                printarray_rtc();
                Sleep(100);
            }
            
            break;

        	case 75:
            if ((rtcmap[pxRTC][pyRTC-1]!=' ') && (rtcmap[pxRTC][pyRTC-1]!='[') && (rtcmap[pxRTC][pyRTC-1]!=']') && (rtcmap[pxRTC][pyRTC-1]!='*')){
                printarray_rtc();
                Sleep(100);
            }
            else{
            
                pyRTC--;
                D2toD1_rtc();
                printarray_rtc();
                Sleep(100);

            }
            break;
            
            case 72:
            if ((rtcmap[pxRTC-1][pyRTC]!=' ') && (rtcmap[pxRTC-1][pyRTC]!='[') && (rtcmap[pxRTC-1][pyRTC]!=']') && (rtcmap[pxRTC-1][pyRTC]!='*')){
                printarray_rtc();
                Sleep(100);
            }
            else{
       
                pxRTC--;
                D2toD1_rtc();
                printarray_rtc();
                Sleep(100);
            }
            break;
            
            case 80:
            if ((rtcmap[pxRTC+1][pyRTC]!=' ') && (rtcmap[pxRTC+1][pyRTC]!='[') && (rtcmap[pxRTC+1][pyRTC]!=']') && (rtcmap[pxRTC+1][pyRTC]!='*')){
                printarray_rtc();
                Sleep(100);
            }
            else{
                pxRTC++;
                D2toD1_rtc();
                printarray_rtc();
                Sleep(100);
            }
            break;

            case 32:
                if((rtcmap[pxRTC-1][pyRTC]=='O')||(rtcmap[pxRTC][pyRTC-1]=='O')||(rtcmap[pxRTC][pyRTC+1]=='O')){
                    printf("\n\nUNKNOWN MAN:\n IT'S POINTLESS!\nPointless! Pointless! Pointless! Pointless! \nPointless! Pointless! Pointless! Pointless!\n\n");
                    system("pause");

                }
            break;

            case 73:
                printarray_rtc();
                Inv();
            break;

            case 105:
                printarray_rtc();
                Inv();
            break;

            case 13:
                printarray_rtc();
            break;



            default:
            system("cls");
            break;
        }
    }

}

int RoadToTheCastle(){ //Antistoixo tou int main().
    char c;
    char *filename="RoadToTheCastle.txt";
    FILE *RTC=fopen(filename,"r");
    for (int i=0;i<20;i++){
        int len;
        char lens[100];
        if(fgets(lens,1000,RTC)==NULL){
            break;
        }
        
        len = strlen(lens);
        // if(len==0){
        //     break;
        // }
        for(int y=0;y<len;y++){
            rtcmap[i][y]=lens[y];

            if (rtcmap[i][y]=='X'){
               
               if (ChangeToVil){
                   ChangeToVil=0;
               }

               if(vkeyrtc){
                   pxRTC=cgatex+1;
                   pyRTC=cgatey;
               }
               else if(respawn){
                   pxRTC=br1x;
                   pyRTC=br1y+1;
               }
               else{
                    pxRTC=i;
                    pyRTC=y;
               }
               
                rtcmap[i][y]=' ';
            }

            if (rtcmap[i][y]=='['){
                br1x=i;
                br1y=y;
            }
            if (rtcmap[i][y]==']'){
                br2x=i;
                br2y=y;
            }    
            
            
            //printf("%c",rtcmap[i][y]);
        }
    }  

fclose(RTC);
if(vkeyrtc){
    rtcmap[cgatex][cgatey]='=';
    rtcmap[br1x][br1y+1]='*';
    additem[0]="Village Key";
    ItemAdder();
}
D2toD1_rtc();
printarray_rtc();
player_rtc();

if (ChangeToVil){
    return 2;
}
else{
    return 3;
}

}