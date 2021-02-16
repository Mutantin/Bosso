#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iostream>
using namespace std;

int px,py,tx,ty,stepx,stepy;
int shampoo=0;
int gold=1000;
int borrow=0;
bool Johnson,JohnsonMet,JohnsonName,goldlend,bow,backdoor,rerunoptions,guard,guardwake,guardsword,Stolensword,Givengoods,ChangeMap,VSKey,OpenGates,theend,itemexists=0;
char vmap[22][29];
char vilmap[10000];
char NPCnames[5][20]= {"Shopkeeper","Stranger","Johnson","Guard"};
char inventory[10][20];
char *additem[20];

struct NPC{
    int NPCx;
    int NPCy;
    char *name;
};

struct NPC NPCarray[10];

struct item{
    char *name[20];
    int amount=0;
};

vector <item> Inventory;


void D2toD1(){ // To D2toD1 function metatrepei to disdiastato pinaka pou dimiourgeitai sto ExecutionVil se monodiastato. 
    int m=0;   
    

     for (int i=0;i<22;i++){
        for(int y=0;y<29;y++){

            if((vmap[i][y]=='=') && (vmap[i][y-1]=='=') && OpenGates){
                vmap[i][y]=' ';
                vmap[i][y-1]=' ';

            }

            if((px==tx) && (py==ty)){
                ChangeMap=1;
            }

            if(backdoor && vmap[i][y]=='T'){
                vmap[i][y]=' ';
                tx=i;
                ty=y;
            }
            if(vmap[i][y]=='X' && (i!=px || y!=py)){
                vmap[i][y]=' ';
            }
            if(px==i && py==y){
                vmap[i][y]='X';
            }

            if(vmap[i][y]=='O'){
                for(int j=0;j<10;j++){
                    if(i!=NPCarray[j].NPCx || y!=NPCarray[j].NPCy){
                        vmap[i][y]=' ';
                    }
                }
            }
            
            for(int j=0;j<10;j++){
                if(NPCarray[j].NPCx==i && NPCarray[j].NPCy==y && i!=0 && y!=0){
                    vmap[i][y]='O';
                }
            }
            vilmap[m]=vmap[i][y];
            m++;
        
            // if(vmap[i][y]='X'){
            //     px=i;
            //     py=y;
            // }    
        }
    }
}


void printarray(){ //Ena aplo function pou emfanizei to "map" array katharizontas ta proigoumena outputs. Xrisimopoieitai gia na min
    system("cls"); // epanalambanontai polles fores idia lines.
    printf("%s",vilmap);
    printf("\n\nGOLD: %i\n\n",gold);
    
}

void End(){ //Otan kaleitai termatizetai to programma.
    system("pause");
    system("cls");
    printf("\n\n\n\n\n\n\n GAME OVER! \n\n\n\n\n\n\n");
    system("pause");
    theend=1;
}


void ItemAdder(){ //Xrisimeuei stin prosthiki "antikeimenwn" ston paikti.
    for(int i=0;i<Inventory.size();i++){
        if(Inventory[i].name[0]==additem[0]){
            Inventory[i].amount++;
            itemexists=1;
        }
    }
    if (itemexists){
        itemexists=0;
        // printf("\n\nsize=%i,name=%s, amount=%i\n\n",Inventory.size(),Inventory[Inventory.size()-1].name[0],Inventory[Inventory.size()-1].amount);
    }
    else{
        
        Inventory.push_back(item());
        Inventory[Inventory.size()-1].name[0]=additem[0];
        Inventory[Inventory.size()-1].amount++;
        // printf("\n\nsize=%i,name=%s, amount=%i\n\n",Inventory.size(),Inventory[Inventory.size()-1].name[0],Inventory[Inventory.size()-1].amount);
    }
}


void JohnsonBabyShampoo(){ //Xrisimeuei ston dialogo paikti me ena NPC.
    int b;
    printf("\n\nSelect your answer:\n1:Shampoo? Of course I will probably need one.\n2:Baby Shampoo? Do I look like a baby to you? Have a nice day sir!\n");
    scanf("%i",&b);
    printarray();
    switch (b)
    {
    case 1:
        if(gold<9){
            printf("\n\nSTRANGE OLD MAN:\nAs I can see you have not enough gold.\nDon't worry. You can buy one an other time.\n\n");
            system("pause");
        }
        else{
            printf("\n\nSTRANGE OLD MAN:\nA wise choice! Here you go!\n\n");
            system("pause");
            printarray();
            printf("\n\nA Baby Shampoo has been added to your inventory.\n\n");
            system("pause");
            printarray();
            printf("\n\nJOHNSON:\nBy the way my name is Johnson.Happy to meet you!");
            shampoo++;
            gold-=9;
            JohnsonName=1;
            additem[0]="Baby Shampoo";
            ItemAdder();
        }
    break;
    case 2:
        printf("\n\nSTRANGE OLD MAN:\nWell...In my old eyes you are as young as a baby.\nBut in any case that was just a welcoming offer. If you don't like it, leave it.It's fine.\n\n");
    break;
    default:
        break;
    }
}

void Inv(){ //Emfanizei to inventory.
    printf("\n\n----- INVENTORY -----\n\n");
    for (int i=0;i<Inventory.size();i++){
        printf("\n%i. %i X %s\n\n",i+1,Inventory[i].amount,Inventory[i].name[0]);
    }
    system("pause");
}

void Stealsword(){
    bool chicken,shampouan=0;
    int ans;
    for (int i=0;i<Inventory.size();i++){
        if(Inventory[i].name[0]=="Chicken Sandwich"){
            chicken=true;
        }
        if(Inventory[i].name[0]=="Baby Shampoo"){
            shampouan=true;
        }
    }
    if(chicken && shampouan && !Givengoods){
        printarray();
        printf("*At this point you remember that you have some stuff in your bag that may be useful to the guard: The Johnson Baby Shampoo and the Chicken Sanwich\nWould you like to:\n1.Give the goods to the guard\n2.Give them but try to steal his sword as well\n3.Leave\n\nSelect your answer:\n\n");
        scanf("%i",&ans);
        printarray();
        switch(ans){
            case 1:
            Givengoods=1;
            printf("*You bring out the stuff and show them to guard. Surprise fills his eyes and suddenly stops paying attention to you*\n*He grabs them out of your hands and without even looking at you he starts eating the sandwich...*\n\n");
            system("pause");
            printarray();
            printf("GUARD:\nHOLLY MOLLY! Thats tasty! *chomb* Thanks *chomb*\nNow go, as you can see I have work *chomb* to do!\n\n");

            case 2:
            Givengoods=1;
            Stolensword=1;
            printf("*You bring out the stuff and show them to guard. Surprise fills his eyes and suddenly stops paying attention to you*\n*He grabs them out of your hands and without even looking at you he starts eating the sandwich...*\n*At that moment sneaky like the fox and quick as the wind you slide your hand near his sword seath*\n*With absolute precesion you manage to unseath his sword and put it in your bag with just one move.*\n*The guard has completely noticed nothing!*\n\n");
            system("pause");
            printarray();
            printf("GUARD:\nHOLLY MOLLY! Thats tasty! *chomb* Thanks *chomb*\nNow go, as you can see I have work *chomb* to do!\n\n");
            system("pause");
            printarray();
            printf("\n\nGuard's sword has been added to your inventory.\n\n");
            system("pause");
            additem[0]="Guard's Sword";
            ItemAdder();

            case 3: 
            printf("You do as the guard says and turn around and leave.\n\n");
        }
        system("pause");
    }
}

void playerVilla(){ //Function gia tin metakinisi tou paikti (mesw switch kai getch).
    char ch;
    while(!ChangeMap && !theend){
        ch=getch(); 
    	
        switch(ch){
            
			        	
	        case 77:
            if (vmap[px][py+1]!=' '){
                D2toD1();
                printarray();
                Sleep(100);
            }
            else{	
                // vmap[px][py]=' ';
                // vmap[px][py+1]='X';
                py++;
                D2toD1();
                printarray();
                Sleep(100);
            }
            // D2toD1();
            // printf("%s",vilmap);
            // system("pause");
            // Sleep(100);
            break;

        	case 75:
            if (vmap[px][py-1]!=' '){
                printarray();
                Sleep(100);
            }
            else{
                // vmap[px][py]=' ';
                // vmap[px][py-1]='X';
                py--;
                D2toD1();
                printarray();
                Sleep(100);
                if(py==NPCarray[3].NPCy+5 && px==NPCarray[3].NPCx){
                    if(!Givengoods){
                        printf("\n\n*You can sense the smell of a horrible stench coming from the inside of the building...You feel like you are about to puke!*\n\n");
                        system("pause");
                    }
                    else{
                        printf("\n\n*You can feel a pleasant air of refreshment in your nostrils...It's magnificent! You pause for a while to take a breath.*\n\n");
                        system("pause");
                    }
                }
            }
            break;
            
            case 72:
            if ((vmap[px][py+1]=='_') || (vmap[px][py-1]=='_')){
                char a;
                printf("\n\n                     You are about to leave the village. Are you sure?(y/n)\n\n");
                scanf(" %c",&a);
                if((a=='y')  || (a=='Y')){
                    system("cls");
                    printf("\n\n                               You have have exited the village. A new journey begins!\n\n");
                    system("pause");
                    End();
                    break;
                }
                else{
                    px++;
                    D2toD1();
                    printarray();
                    Sleep(100);
                }
            }
            else if (vmap[px-1][py]!=' '){
                printarray();
                Sleep(100);
            }
            else{
                // vmap[px][py]=' ';
                // vmap[px-1][py]='X';
                px--;
                D2toD1();
                printarray();
                Sleep(100);
            }
            break;
            
            case 80:
            if (vmap[px+1][py]!=' '){
                printarray();
                Sleep(100);
            }
            else{
                // vmap[px][py]=' ';
                // vmap[px+1][py]='X';
                px++;
                D2toD1();
                printarray();
                Sleep(100);
            }
            break;

            case 32:
                D2toD1();
                printarray();
                if(vmap[px-1][py]=='P'){
                    printf("\n\nSIGNPOST:\nWelcome to the Scarn village!\n\n");
                    
                }
                if(px-2==NPCarray[0].NPCx && py==NPCarray[0].NPCy){
                    int a;
                    char b;
                    if(VSKey){
                        printf("\n\nOh my god...You actually did it! Congratulations!\nGo speak with Johnson. He will be very happy about it!\n\n");
                        system("pause");
                    }
                    else{
                        printf("\n\nSHOPKEEPER:\nOh! A traveler! How can we help you today?\n\n");
                        system("pause");
                        printarray();
                        printf("\n\nSelect an answer:\n1:Do you have anything for sale?\n2:Uh? Oh I was just looking around...\n");
                        if(Johnson){
                            printf("3.Johnson sent me here. He said you are selling a specific bow...\n\n");
                        }
                        scanf("%i",&a);
                        printarray();
                        switch(a){
                            case 1: 
                            printf("\n\nSHOPERKEEPER:\nWell...You are in a food store.\nWe make amazing sandwiches with meat from local chickens for just 100 gold each!\nWould you like one?\n\n");
                            system("pause");
                            system("cls");
                            printf("%s",vilmap);
                            printf("\n\nSelect an answer(y/n):\n\n");
                            scanf(" %c",&b);
                            system("cls");
                            printf("%s",vilmap);
                            if((b=='y') || (b=='Y')){

                                if(gold<100){
                                    printf("\n\nSHOPKEEPER:\nOh not enough gold right? Get some and come again...Farewell!\n\n");
                                }
                                else{
                                    printf("\n\nSHOPKEEPER:\nOh Really? Great! Here you go, thanks a lot and have a nice day!\n\n");
                                    system("pause");
                                    printarray();
                                    printf("\n\n A Chicken Sandwich has been added to your inventory.");
                                    gold-=100;
                                    additem[0]="Chicken Sandwich";
                                    ItemAdder();
                                }

                            }
                            else{

                                printf("\n\nSHOPKEEPER:\nAs expected...It's okay...Farewell.\n\n");
                            }
                            break;
                            
                            case 2:
                            printf("\n\nSHOPKEEPER:\nLooking around? Listen sir! Just buy some food or leave...\nWe are not wasting time here. Bye!\n\n");
                            break;

                            case 3:
                            char an;
                            if(bow){
                                printf("\n\nSHOPKEEPER:\nI already gave you the bow my friend. I am afraid I can't help you any more...\n\n");
                            }
                            else{
                                printf("\n\nSHOPKEEPER:\nVery interesting!\n...So he believes you are capable of defeating Mada...?\nIf he says so, then he must be right...\n\n");
                                system("pause");
                                system("cls");
                                printf("%s",vilmap);
                                printf("\n\nSHOPKEEPER:\nAlright then...So be it...\nI can sell you the Silvercrest Bow but only for 1000 gold\nAre you interested?\n\n");
                                system("pause");
                                system("cls");
                                printf("%s",vilmap);
                                printf("\n\nSelect an answer(y/n):\n\n");
                                scanf(" %c",&an);
                                system("cls");
                                printf("%s",vilmap);
                                if((an=='y') || (an=='Y')){
                                    if(gold<1000){
                                        printf("\n\nSHOPKEEPER:\nOh not enough gold right? Get some and come again...Farewell!\n\n");
                                        goldlend=1;

                                    }
                                    else{
                                        printf("\n\nSHOPKEEPER:\nHere it is!\nTake care of it! It's the only weapon that can kill MadaKnight\nGood luck!\n\n");
                                        system("pause");
                                        printarray();
                                        printf("\n\n Silvercrest Bow has been added to your inventory\n\n");
                                        gold-=1000;
                                        bow=1;
                                        additem[0]="Silvercreast Bow";
                                        ItemAdder();
                                    }
                                }    
                                else{
                                    printf("\n\nSHOPKEEPER:\nI knew you were not ready...\n It's okay...we are visited by many casual travelers anyway.Good journeys to you!\n\n");
                                }
                            }
                            break;
                        }
                    }
                }
                if((px-1==NPCarray[1].NPCx && py==NPCarray[1].NPCy)||(px+1==NPCarray[1].NPCx && py==NPCarray[1].NPCy)||(px==NPCarray[1].NPCx && py+1==NPCarray[1].NPCy)){
                    int a;
                    if(VSKey){
                        printf("\n\nSTRANGER:\nOh you are back!\nYou managed to kill him with this bow!\nNice!\n\n");
                        system("pause");
                        printarray();
                        if(borrow>0){
                            if(Stolensword){
                                int murd;
                                printf("\n\nSTRANGER:\nWait....WHERE IS MY LOOT? You didn't get my gold?\nSo how are you supposed to pay me back?\nYOU THIEF!\n\nGUA-\n\n");
                                printf("**Do you attempt to stop the shady man?**\n\n");
                                system("pause");
                                printarray();
                                printf("\nSelect an answer:\n1.Draw the Guard's sword and stab the bastard\n2.Wait and see what happens.\n\n");
                                scanf("%i",&murd);
                                printarray();
                                switch(murd){
                                case 1:
                                    printf("**You draw the sword and stab him in the heart...After a loud scream, he instantly drops dead on the ground\n\n**");
                                    system("pause");
                                    printf("You also search his pockets and find 500 gold!");
                                    NPCarray[1].NPCx=-50;
                                    NPCarray[1].NPCy=-50;
                                    gold+=500;
                                    goto exit;
                                    
                                case 2:
                                    printf("**After thinking for a while, you decide to keep your patience and stay rational...\n\n**");
                                    printarray();
                                    printf("STRANGER: GUARD! OVER HERE!\n\n");
                                    goto skip;

                                }    
                                                            
                            }
                            printf("\n\nSTRANGER:\nWait....WHERE IS MY LOOT? You didn't get my gold?\nSo how are you supposed to pay me back?\nYOU THIEF!\n\nGUARD! GUARD! COME OVER HERE!\n\n");
                            skip:
                            system("pause");
                            stepx=NPCarray[3].NPCx;
                            stepy=NPCarray[3].NPCy;
                            while(NPCarray[3].NPCy<py-1){
                                NPCarray[3].NPCy++;
                                D2toD1();
                                printarray();
                                Sleep(200);
                            }
                            while(NPCarray[3].NPCx!=px){
                                NPCarray[3].NPCx--;
                                D2toD1();
                                printarray();
                                Sleep(200);
                            }
                            printf("\n\nGUARD:\nWhat is the matter over here?\nDid you call me?\n\n");
                            system("pause");
                            printarray();
                            printf("\n\nSTRANGER:\nHim!Yes him! This guy over there!\nI gave him some gold to buy a bow but never returned it!\nHe owes me %i gold!\nArrest him immidiately! He is a thief!\n\n",borrow);
                            system("pause");
                            printarray();
                            if (guard){
                                printf("\n\nGUARD:\nOh look who it is!Long time no see...The naughty traveller again!\nI told you to improve you behavior but as I can see you keep trying to scam people.\nMaybe it's about time to fix it for you.Follow me.\n\n");
                                system("pause");
                                printarray();
                                while(NPCarray[3].NPCx<15){
                                    px=NPCarray[3].NPCx;
                                    py=NPCarray[3].NPCy;
                                    NPCarray[3].NPCx++;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }

                                while(vmap[NPCarray[3].NPCx-1][NPCarray[3].NPCy]!='='){
                                    px=NPCarray[3].NPCx;
                                    py=NPCarray[3].NPCy;
                                    NPCarray[3].NPCy--;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                Sleep(700);
                                vmap[NPCarray[3].NPCx-1][NPCarray[3].NPCy]=' ';
                                D2toD1();
                                printarray();
                                Sleep(400);
                                NPCarray[3].NPCy--;
                                D2toD1();
                                printarray();
                                printf("\n\nGUARD:\nGet in kiddo.\n\n");
                                system("pause");
                                while(py>NPCarray[3].NPCy+1){
                                    py--;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                for(int gg=0;gg<2;gg++){
                                    px--;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                NPCarray[3].NPCy++;
                                D2toD1();
                                printarray();
                                printf("\n\nGUARD:\nSayonara journey boy!\n\n");
                                system("pause");
                                vmap[px+1][py]='=';
                                px=NULL;
                                py=NULL;
                                D2toD1();
                                printarray();
                                printf("\n\n** SLAM! **\n\n");
                                system("pause");
                                system("cls");
                                printf("\n\n\n\n\n\n YOU HAVE BEEN IMPRISONED!\n\n\n\n\n");
                                End();
                            }
                            else{
                                printf("\n\nGUARD:\nSo what does this mean?...That you tell the truth?\nYou look like a paranoid to me.\n\n");
                                system("pause");
                                printarray();
                                printf("\n\nSTRANGER:\nB-B-But...IT IS the truth sir!He owes me!\n\n");
                                system("pause");
                                printarray();
                                printf("\n\nGUARD:\nSo what? Even if he does, he may give it back to you at a later time\nAnyways stop wasting my time with nonsense...\nHave a nice day gentlemen!\n\n");
                                system("pause");
                                for(int gg=0;gg<2;gg++){
                                    NPCarray[3].NPCx++;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                printf("\n\nSTRANGER:\nGuard! Wait! There's something more I need to tell you!\nThis guy just killed Mada Knight...I don't know how he accessed the castle!\nArrest him!\n\n");
                                system("pause");
                                printarray();
                                printf("\n\nGUARD:\nMada Knight? HAHAHA!\nWho cares? He was just another tyrannical useless failure.\nMaybe we should build a statue for traveller, not arrest him!\nHAHAHA!\nI hope we get a better leader next time...\nNow if you excuse me, I have a job to do. Good day!\n\n");
                                system("pause");
                                while(NPCarray[3].NPCx<stepx){
                                    NPCarray[3].NPCx++;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                while(NPCarray[3].NPCy>stepy){
                                    NPCarray[3].NPCy--;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                printf("\n\nSTRANGER:\nYou are so lucky! But believe me...We are not done yet.\n\n");

                            }
                        }
                        else{
                            printf("\n\nYou should go speak with Johnson...He will be happy about the news.\nAgain congratulations for your achievement!\n\n");
                        }
                        exit:{}
                    }
                    else{
                        printf("\n\nSTRANGER:\nHello there traveler...Are you looking for something?\n\n");
                        system("pause");
                        printarray();
                        printf("\n\nSelect an answer:\n\n1:I was just passing by...is there a problem with that?\n2:Do you know how I can pass that door in the west side?\n");
                        if(goldlend){
                            printf("3:I want some gold to buy something from the shop.Do you know where I can find some?\n\n");
                        }
                        scanf("%i",&a);
                        printarray();
                        switch(a){
                            case 1:
                            printf("\n\nSTRANGER:\nI don't like curious passengers...There's nothing here for you to see. Move on.\n\n");
                            system("pause");
                            break;

                            case 2:{
                            int yPOS=NPCarray[1].NPCy;
                            if(bow){
                                printf("\n\nSTRANGER:\nHmmm, I see you got the bow.Paying so much gold for it means you are confident.Maybe you will save our village after all...\nYou are lucky I have the key.I will open the door for you.You wait here.\n\n");
                                system("pause");
                                for(int i=0;i<50;i++){
                                    if(vmap[NPCarray[1].NPCx-1][NPCarray[1].NPCy-1]=='T'){
                                        NPCarray[1].NPCx--;
                                        D2toD1();
                                        printarray();
                                        Sleep(1000);
                                        backdoor=1;
                                        D2toD1();
                                        printarray();
                                        Sleep(1000);
                                        break;
                                    }
                                    else{
                                        NPCarray[1].NPCy--;
                                        D2toD1();
                                        printarray();
                                        Sleep(300);
                                    }
                                }
                                NPCarray[1].NPCx++;
                                D2toD1();
                                printarray();
                                Sleep(300);
                                while(NPCarray[1].NPCy<yPOS){
                                    NPCarray[1].NPCy++;
                                    D2toD1();
                                    printarray();
                                    Sleep(300);
                                }
                                Sleep(700);
                                printf("\n\nSTRANGER:\nHere you go my little one.The door is now open and you are free to go.\n ...But go only for the victory.Good luck!\n\n");
                                system("pause");
                                D2toD1();
                                printarray();
                                system("pause");
                                if(borrow>0){
                                    printarray();
                                    printf("\n\nSTRANGER\nOh wait! Also about the gold I lent you...Remember it's not free!\nYou owe me %i gold. I guess MadaKnight will have some good loot so you will be able to pay me back with a small interest.\nI hope you have some respect for my help\nBelieve me...you don't want to see me as an enemy.\n\n",borrow);
                                    system("pause");
                                }
                            }
                            else{
                                printf("\n\nSTRANGER:\nHow would I know? Its key is kept in a safe place to prevent random ignorants like you to access the castle...\nAnd no, don't ask me about it.I know nothing.Now get off.\n\n");
                            }
                            break;
                            }  

                            case 3:
                            int answer;
                            if (goldlend){
                                printf("\n\nSTRANGER:\nHaha! You came to the right person. Helping people in need is my speciality...\nBut first tell me how much gold you have and how much you want.\n\n");
                                printf("\nSelect your answer:\n1:Well...I need to buy a bow that costs 1000 gold and I only have %i...Is it possible?\n2:Well actually, now that I am thinking of it...never mind.\n\n",gold);
                                scanf("%i",&answer);
                                printarray();
                                switch (answer)
                                {
                                case 1:
                                    printf("\n\nSTRANGER:\nHmmm...1000 gold you say. So you need %i more...\nI think today is your day. I can give you this amount\nBut don't forget it's not for free, I expect it back.\nHere you go... and you better use it wisely.Have a nice day!\n\n",1000-gold);
                                    borrow=1000-gold;
                                    gold=1000;
                                break;

                                case 2:
                                    printf("\n\nSTRANGER:\nWhy? Are you scared? Hahaha! Go cry to your mummy butterboy.");
                                break;    
                                
                                default:
                                    break;
                                }
                            }
                            break;
                            
                        }
                    }


                }
                if((px-1==NPCarray[2].NPCx && py==NPCarray[2].NPCy)||(px==NPCarray[2].NPCx && py-1==NPCarray[2].NPCy)){
                    int a;
                    if(VSKey){
                        printf("\n\nJOHNSON:\nT-t...traveller! Is it you? You are back!...\n You actually defeated Mada...We are free once more!\nNow I will be able not only to farm but also sell my shampoos to the rest of the world!\nI could also run for mayor...haha!\nThanks so much for your service...\nNow give me the key to the Gates.\n\n");
                        system("pause");
                        printarray();
                        printf("\n\n Village key has been removed from your inventory.\n\n");
                        system("pause");
                        printarray();
                        printf("\n\nJOHNSON:\nAstonishing! The gates are now open for you to go! Happy journeys my boy.\nAnd don't forget! This village and my house will be always open for you.\nTake care!\n\n");
                        system("pause");
                        printarray();
                        printf("\n\nJOHNSON:\nOh wait!Before you go!\nTake this Baby Shampoo as a gift from me.\nYou will remember the village every time you take a bath!\nAlso advertise it a little bit...You see I am an old man I can't walk very much\n...Farewell!\n\n");
                        OpenGates=1;
                        additem[0]="Baby Shampoo";
                        ItemAdder();
                        system("pause");

    }
                    else{
                        if(Johnson){
                            char answershampoo;
                            if (!bow){
                                printf("\n\nJOHNSON:\n Come on traveller.Still to get the Bow? You need to hurry!\nThis is supposed to be a secret mission.");
                            }
                            else{
                                printf("\n\nJOHNSON:\n I see you bought the Bow! Excellent! Now go and get the job done...\nGood luck my friend!");
                            }
                            system("pause");
                            printarray();
                            printf("\n\nJOHNSON:\n Oh! I almost forgot...\nDo you want any baby shampoo?\n\n");
                            printf("Select an answer(y/n):");
                            scanf(" %c",&answershampoo);
                            printarray();
                            if((answershampoo='y') || (answershampoo='Y')){ //Strange error (polla ambiguous) emfanistike kata tin prosthesi tou answershampoo=='Y'. Ena restart tou VS code eksafanise to error...
                                printf("\n\nJOHNSON:\nA wise choice! Here you go! This will be 20 gold\n\n");
                                system("pause");
                                printarray();
                                if(gold<20){
                                    printf("\n\nJOHNSON:\nAs I can see you have not enough gold.\nDon't worry. You can buy one an other time.\n\n");
                                }
                                else{
                                    printf("\n\n A Baby Shampoo has been added to your inventory.\n\n");
                                    gold-=20;
                                    for(int i=0;i<Inventory.size();i++){
                                            if(Inventory[i].name[0]=="Baby Shampoo"){
                                                Inventory[i].amount++;
                                                itemexists=1;
                                            }
                                        }
                                        if (itemexists){
                                            itemexists=0;
                                        }
                                        else{
                                        Inventory.push_back(item());
                                        Inventory[Inventory.size()-1].name[0]="Baby Shampoo";
                                        Inventory[Inventory.size()-1].amount++;
                                        // printf("\n\nsize=%i,name=%s, amount=%i\n\n",Inventory.size(),Inventory[Inventory.size()-1].name[0],Inventory[Inventory.size()-1].amount);
                                        }

                                }
                            }
                            else{
                                printf("\n\nJOHNSON:\nAlrighty boy...Have a nice day!");
                            }

                        }
                        else{
                        if(!JohnsonMet){
                            if(!rerunoptions){
                                printf("\n\nSTRANGE OLD MAN:\nBy the Seven Seas! Look at that! A new traveler! What brings you to our lands my young one?\n\n");  
                            }
                            else{
                                printf("\n\nSTRANGE OLD MAN:\nOh look who it is! The traveler! So tell me... what are you doing?\n\n");
                                rerunoptions=0;
                            }
                        
                        
                        
                        printf("Select your answer:\n1:Let's just say I am exploring...Your village looks good to stay for a day or two.\n2:Where the heck I am and who are you?\n3:I have no time for wasting old man, bye.\n\n");
                        scanf("%i",&a);
                        printarray();
                        switch (a)
                        {
                        case 1:
                            printf("\n\nSTRANGE OLD MAN:\nOf course you can stay my son. Here,in Scarn Village, people are very friendly to foreigners and you are welcome!");
                            printarray();
                            printf("\n\nSTRANGE OLD MAN:\nWe as a family have a tradition in making Baby Shampoos.\n You will probably need one to take a shower.Travelling so much must have been a dirty job...\n I can give it to you from 20 gold for only 9.You really need one. What do you say?");
                            JohnsonBabyShampoo();
                            JohnsonMet=1;

                            

                        break;
                        
                        case 2:
                            printf("\n\nSTRANGE OLD MAN:\nWoah woah! Chill my little friend!\nYou are in the Scarn village and you are welcome here!\n\n");
                            system("pause");
                            printarray();
                            printf("\n\nSTRANGE OLD MAN:\nWe as a family have a tradition in making Baby Shampoos.\n You will probably need one to take a shower.Travelling so much must have been a dirty job...\n I can give it to you from 20 gold for only 9.You really need one. What do you say?\n\n");
                            JohnsonBabyShampoo();
                            JohnsonMet=1;

                            

                        break;

                        case 3:
                            printf("\n\nSTRANGE OLD MAN:\nSee you again boy!\n\n");
                            rerunoptions=1;
                        break;    
                        default:
                            break;
                        }
                        }
                        if(JohnsonMet){

                        system("pause");
                        printarray();
                        if(JohnsonName){
                            
                            printf("\n\nJOHNSON:\nWell now that we did our businesses, let's continue to another topic.\n\n");
                        }
                        else{
                            printf("\n\nSTRANGE OLD MAN:\nYou see this village's people have many economical problems and we are trying to live with the few things we have.\n\n");
                            system("pause");
                            printarray();
                            printf("\n\nJOHNSON:\nOh! I forgot to tell you my name...I am Johnson, happy to meet you.\n\n");

                        }
                        system("pause");
                        printarray();
                        printf("JOHNSON:\nA long time ago a royal knight by the name Mada or Madaknight moved in our area and declared this village under his ownership.\nSince then he started using us like slaves as we had to pay him 2/3 of our farming profits.\nAfter some months almost all villagers stopped farming because it was not worth anymore.\nSo they started making handedicrafts and would travel to sell them.\nWhen Mada learnt about this he forbid all exports and villager travels as a punishment for abandoning the farms.\nTherefore our only option is to overthrow him.\nLuckily enough my son who runs the shop north from here, recently found a rare bow\nThis bow is indeed able to penetrate Mada's iron armor not only because of the silver arrows it can shoot but also because of it's special design and the rare materials which is made of.\nUnfortunatelly no villager is in the physical condition to fight right now.\nIf you could sneak into his castle in the West and kill him the village will always be in your gratitude.\nIf you visit the Shopkeeper, tell him I sent you.\n\n");
                        Johnson=1;
                        }
                        

                        }
                    }
                }    
                if(px==NPCarray[3].NPCx && py-1==NPCarray[3].NPCy){
                    char ways[6][50]={"1:Start clapping","2:Shout loudly","3:Pour the remaining beer on his head","4:Slap him","5:Shake him"};
                    int pointy[6];
                    int a,b;
                    if (VSKey){
                        printf("\n\nGUARD:\nSo you actually did it! You defeated Mada...\nMaybe there is chance for me after all to become finally the leader Bahahah...*ahem*\nAnyways.\n");
                        if(guard){
                            printf("But now get lost...I don't like filthy thiefs around me.\nDon't think that I forgot your actions.");
                        }
                        else{
                            if (OpenGates){
                                printf("As I can see you have spoken with Johnson and has opened the gates already...\nFinally the villagers are free!\nI wish you happy journeys my friend and expecting to see you even stronger next time we meet!\n Farewell!");

                            }
                            else{
                                printf("Now go speak with Johnson! He will be very happy to learn the news.\nAlso give him the village key to open the gates.\nThe time of freedom has come!");
                            }
                        }


                    }
                    else{    
                        if(!guard){
                            printf("\n\nYou can see a guard looking guy with his back against you, sleeping on a table\nHe is snoring loudly and you can see his right hand slightly holding a big almost empty cup of beer.\nAt the left side of his belt you can see his sword in its sheath.\n\n");
                            printf("1:Wake up the guard.\n2:Attempt to steal his sword\n3:Walk away\n\n");
                            scanf("%i",&a);
                        }
                        
                        if(guardsword && !guardwake){
                            printf("You can see the guard sleeping on the table again holding another big cup of beer that's half empty!\n");
                            if(Stolensword){
                                printf("This time his sword is missing from it's seath though. Who knows if he has even noticed it...\nWhat's sure is that the sandwich has made him sleep for good.\n\n");
                            }
                            printf("1:Wake up the guard.\n2:**DONE**\n3:Walk away\n\n");
                            scanf("%i",&a);

                        }
                        if(guardwake && !guardsword){
                            printf("1:**DONE**\n2:Attempt to steal his sword\n3:Walk away\n\n");
                            scanf("%i",&a);

                        }
                        
                        if(guardwake && guardsword && !Givengoods){
                            printf("GUARD:\nARE YOU STILL HERE? *HIC*\nYou should have known that I am not in mood when my belly is only filled with *HIC* beer.\nUnless you have nothing to offer, leave right now.\nAnd don't *HIC* come again just for fun except if you want *HIC* to be arrested!\nLEAVE!");
                            system("pause");
                            printarray();
                            Stealsword();
                            Givengoods?a=NULL:3;
                        }
                        if(guardwake && guardsword && Givengoods){
                            printf("GUARD:\nHere AGAIN?\nListen fluffy...\nThe stuff you gave me earlier was not any bribe. Don't think I have forgotten about your intentions.\nNow leave, I hate talking when my belly is full.\n\n");
                            a=3;
                            system("pause");
                        }
                        printarray();
                        switch (a)
                        {
                        case 1:
                            printf("\n\nSelect the way to wake him up:\n1:Start clapping\n2:Shout loudly\n3:Pour the remaining beer on his head\n4:Slap him\n5:Shake him\n\n");
                            scanf("%i",&b);
                            printarray();
                            for(int i=0;i<5;i++){
                                if(i==4){
                                    break;
                                }
                                pointy[i]=b-1;
                                printarray();
                                printf("\n\nNothing happens.The guard keeps sleeping and snoring more audibly.\n\n");
                                system("pause");
                                printarray();
                                printf("\n");
                                for(int z=0;z<5;z++){
                                    bool bol=0;
                                    for(int p=0;p<5;p++){
                                        if(pointy[p]==z){
                                            bol=1;
                                            break;
                                        }
                                    }
                                    if(!bol){
                                        printf("%s\n",ways[z]);
                                    }
                                }
                                if(i<4){
                                printf("\n\nSelect one of the remaining options\n");
                                scanf("%i",&b);
                                }

                            }
                            printarray();
                            if(Givengoods){
                                printf("\n\nGUARD\n*HIC*YOU DAMN BASTARD!Can't you *HIC* see I'm on duty?\nDo you think that because you gave me a Chicken Sandwich *HIC* you are allowed to enter whenever you want? *HIC*\nNow leave or...*HIC*\n*The guard moves his hand to his sword's seath while staring at you.\n\n*");
                                system("pause");
                                if(Stolensword){
                                    int payup;
                                    printarray();
                                    printf("GUARD:\n\nWAIT WAIT WAIT! WHERE THE HECK *HIC* IS MY SWORD?\nDid you filthy animal stole *HIC* it?\n*HIC*GIVE IT BACK NOW RAT OR I WILL ARR-! *HIC* OR OR OR *HIC* just pay 200 heh...\nOr maybe no! 300 gold! Wait, no! What you did was *HIC* illegal, give me 500 gold HAHA!\n\n");
                                    system("pause");
                                    printarray();
                                    printf("Select an answer:\n\n1.Give the guard's sword back\n2.Pay 500 gold\n\n");
                                    scanf("%i",&payup);
                                    switch(payup){
                                        case 1:
                                            printf("GUARD\n\nAHA! Of course it was you!*HIC* My bluffing was successful\nNow give it back you peasant!");
                                            lolxD:
                                            Stolensword=0;
                                            for(int i=0;i<Inventory.size();i++){
                                                if(Inventory[i].name[0]=="Guard's Sword"){
                                                    Inventory.erase(Inventory.begin()+i);
                                                    i--;
                                                }
                                            }
                                            system("pause");
                                            printarray();
                                            printf("\n\nGuard's sword has been removed from your inventory.\n\n");

                                        case 2:
                                            if(gold<500){
                                                printf("GUARD:\n\nAs I can see you are a pleb. It's okay...you got a sword to give!");
                                                goto lolxD;
                                            }    
                                            else{
                                                gold-=500;
                                            }    
                                    }
                                    system("pause");
                                }
                                
                            }
                            else{
                                printf("\n\nGUARD\n*HIC*YOU DAMN BASTARD!Can't you *HIC* see I'm on duty?\nI have no time for *HIC* chitchating.\nNormally i should arrest you but *HIC* but I will let you off with just a fine for now.\nThe next time will be critical though\nNow pay up.It's *HIC* 50 gold.Or maybe wait...*HIC* 100 gold.\nHahaha!\n\n");
                                system("pause");
                                if(gold<100){
                                    printarray();
                                    printf("\n\nGUARD:\nOh so you are poor as well...!*HIC* Whatever...*HIC* Give me what you have and don't try *HIC* anything funny next time kid.\n\n");
                                    gold=0;
                                }
                                else{
                                gold-=100;
                                }
                                guard=1;
                                guardwake=1;
                            }
                        break;

                        case 2:
                            printf("\n\nYou slowly approach your hand near his belt\nYou grab his sword's handle and slowly try to draw it\n...\nSuddenly you hear a loud grunting sound and the guard wakes up\nHe instantly pushes you away\n\n");
                            py++;
                            system("pause");
                            D2toD1();
                            printarray();
                            printf("\n\nGUARD:\nHAHAHA!Nice try kid!*HIC* But you are not fast enough.\nNormally I would arrest you...but you see I don't gain *HIC* something from it.\nYou will have to pay...Let me think...*HIC* 200 gold for what you did.\nPay up kid.*HIC*\n\n");
                            system("pause");
                            Stealsword();
                            if(!Givengoods){
                                if(gold<200){
                                    printarray();
                                    printf("\n\nGUARD:\nOh so you are poor as well...!*HIC* Whatever...*HIC* Give me what you have and don't try *HIC* anything funny next time kid.\n\n");
                                    gold=0;
                                }
                                else{
                                gold-=200;
                                }
                            }
                            guard=1;
                            guardsword=1;
                        break;

                        case 3:
                            printarray();
                            printf("\n\nYou walk away...");
                        break;
                        
                        default:
                        break;
                        }
                    }
                }
                Sleep(100);
            break;

            case 73:
                printarray();
                Inv();
            break;

            case 105:
                printarray();
                Inv();
            break;

            case 13:
                printarray();
            break;

            default:
            system("cls");
            break;
            
        }
        fflush(stdin);
    } 
   
}       



int ExecutionVil(){ //Function antistoixo tou int main().
    char filename[50] = "village.txt";
    char c;
    int num=0;
    FILE* village = fopen(filename, "r");
        for (int i=0;i<22;i++){
            for(int y=0;y<29;y++){
                c = fgetc(village);
                vmap[i][y]=c;
                printf("%c",vmap[i][y]);
                

                if (vmap[i][y]=='X'){
                    if (ChangeMap){
                        py=ty+1;
                        ChangeMap=0;
                        vmap[i][y]=' ';
                    }
                    else{
                        px=i;
                        py=y;
                        vmap[i][y]=' ';
                    }
                }
                if(vmap[i][y]=='O'){
                    NPCarray[num].NPCx=i;
                    NPCarray[num].NPCy=y;
                    NPCarray[num].name=NPCnames[num];
                    num++;
                    vmap[i][y]=' ';
                }
            }
        }        

        // while((fgets(vilmap,10000,village))!=NULL){
        //     printf("%s",vilmap);
        // }
        
fclose(village);

// VSKey=1;
// Stolensword=1;
// borrow=1;
D2toD1();
printarray();
playerVilla();

return 1;
}

