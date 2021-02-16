#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>



char plat[50][50];
int mx; int my; int Bopx; int Bopy; int Madahealth = 10;
bool PlayerDeath,VillageKey,newtry=0;

void Makearray() { //Dimiourgei kai emfanizei enan pinaka ws platforma metakinisis tou paikti.
    char OneArray[5000];
    int index = 0;
    system("cls");

    for (int i = 0; i < 50; i++) {
        for (int y = 0; y < 50; y++) {
            
            if ((int)(plat[i][y]) + 256 != 167 && (int)(plat[i][y]) + 256 != 254 && plat[i][y] != 'X' && plat[i][y] != 'A') {
                plat[i][y] = ' ';
            }

            // if ((int)(plat[i][y]) + 256 == 254 && mx!=i && my!=y){
            //     plat[i][y] = ' ';
            //     printf("\nSTOP RIGHT THERE.mx=%i, my=%i, i=%i, y=%i\n",mx,my,i,y);
            // }

            if (newtry && plat[i][y]=='A'){
                plat[i][y]=' ';
            }

            if ((y==48) || (y==0)){
                plat[i][y]='|';
            }

            if((i==0)||(i==49)){
                plat[i][y]='=';
            }

            if (y == 49) {
                OneArray[index] = '\n';
            }
            else {
                OneArray[index] = plat[i][y];
            }
            index++;
        }
    }
    newtry=0;
    OneArray[index] = 0;
    printf("%s\n\nMadaKnight Health: %i",OneArray,Madahealth);
    
}

void MadaKnight_Spawn(int a, int b) { //Emfanizei to Boss.
    plat[a][b] = 254;
    if(newtry){
        plat[mx][my]=' ';
    }
    mx = a;
    my = b;

}

void MadaKnight_Move(int a, int b) { //Epitrepei tin metakinisei tou Boss.

    if  (Bopx > a) {
        plat[a][b] = ' ';
        a++;
        plat[a][b] = 254;

    }
    else if  (Bopx < a) {
        plat[a][b] = ' ';
        a--;
        plat[a][b] = 254;

    }
    else if (Bopy > b) {
        plat[a][b] = ' ';
        b++;
        plat[a][b] = 254;
    }
    else if (Bopy < b) {
        plat[a][b] = ' ';
        b--;
        plat[a][b] = 254;
    }

    mx = a;
    my = b;

    if((mx==Bopx) && (my==Bopy)){
        Makearray();
        printf("\n\nYou are dead.\n\n");
        PlayerDeath=1;
        system("pause");
    }

}

void MadaKnight_Attack(int a, int b) { //Epitrepei tin epithesi tou Boss ston paikti.

    if ((a > Bopx - 3 && b == Bopy && a < Bopx) || (a < Bopx + 3 && b == Bopy && a > Bopx) || (a == Bopx && b > Bopy - 5 && b < Bopy) || (a == Bopx && b<Bopy + 5 && b>Bopy)) {



        if (a > Bopx) {

            plat[a - 1][b] = 'A';
            plat[a - 2][b] = 'A';
            plat[a - 3][b] = 'A';
        }

        else if (a < Bopx) {

            plat[a + 1][b] = 'A';
            plat[a + 2][b] = 'A';
            plat[a + 3][b] = 'A';
        }

        else if (b < Bopy) {

            plat[a][b + 1] = 'A';
            plat[a][b + 2] = 'A';
            plat[a][b + 3] = 'A';
            plat[a][b + 4] = 'A';
            plat[a][b + 5] = 'A';
        }

        else if (b > Bopy) {

            plat[a][b - 1] = 'A';
            plat[a][b - 2] = 'A';
            plat[a][b - 3] = 'A';
            plat[a][b - 4] = 'A';
            plat[a][b - 5] = 'A';
        }

        Makearray();
        printf("\n\nYou are dead.\n\n");
        PlayerDeath=1;
        system("pause");




    }

    else {
        MadaKnight_Move(mx, my);
    }

}






void weaponry(int s, int b) { //Function pou xrisimopoieitai gia tin epithesi tou paikti.
    int dx = mx - Bopx;
    int dy = my - Bopy;
    int sa = 0; int ba = 0;

    if (dx < 0) {
        if (dy < 0) {
            if (abs(dx) > abs(dy)) {
                sa = -1;
            }
            else {
                ba = -1;
            }
        }
        else {
            if (abs(dx) > abs(dy)) {
                sa = -1;
            }
            else {
                ba = 1;
            }
        }
    }
    else {

        if (dy < 0) {
            if (abs(dx) > abs(dy)) {
                sa = 1;
            }
            else {
                ba = -1;
            }
        }
        else {
            if (abs(dx) > abs(dy)) {
                sa = 1;
            }
            else {
                ba = 1;
            }
        }


    }
    for (int counter = 0; counter < 11; counter++) {
        s = s + sa;
        b = b + ba;
        if ((int)(plat[s][b]) + 256 == 254) {
            Madahealth--;
            plat[s - sa][b - ba] = ' ';
            if (Madahealth==0){
                VillageKey=1;
                system("cls");
                printf("\n\n\n\n\n\n\n                       VICTORY!\n\n Village Key has been added to your inventory.\n\n\n\n");
                system("pause");
            }
            else{
            Makearray();
            MadaKnight_Move(mx, my);
            }
            break;
        }
        else {
            plat[s][b] = 167;
        }
        Makearray();
        Sleep(200);
        plat[s][b] = ' ';
    }
    Makearray();
    

    
}

void player(int a, int b) { //Funtion metakinisis tou paikti panw ston pinaka tou Makearray().

    plat[a][b] = 'X';
    Makearray();
    int i; int y;
    i = a;
    y = b;
    char ch;
    while (!PlayerDeath && !VillageKey) {
        ch = getch();



        switch (ch) {


        case 77:
            if (plat[i][y+1]!=' '){
                Makearray();
                Sleep(100);
                Bopx = i;
                Bopy = y;
            }
            else{
                plat[i][y] = ' ';
                plat[i][y + 1] = 'X';
                y++;
                Sleep(100);
                Bopx = i;
                Bopy = y;
                MadaKnight_Attack(mx, my);
                Makearray();
            }    
            break;

        case 75:
            if (plat[i][y-1]!=' '){
                Makearray();
                Sleep(100);
                Bopx = i;
                Bopy = y;
            }
            else{
                plat[i][y] = ' ';
                plat[i][y - 1] = 'X';
                y--;
                Sleep(100);
                Bopx = i;
                Bopy = y;
                MadaKnight_Attack(mx, my);
                Makearray();
            }
            break;

        case 72:
            if (plat[i-1][y]!=' '){
                Makearray();
                Sleep(100);
                Bopx = i;
                Bopy = y;
            }
            else{
                plat[i][y] = ' ';
                plat[i - 1][y] = 'X';
                i--;
                Sleep(100);
                Bopx = i;
                Bopy = y;
                MadaKnight_Attack(mx, my);
                Makearray();
            }
            break;

        case 80:
            if (plat[i+1][y]!=' '){
                Makearray();
                Sleep(100);
                Bopx = i;
                Bopy = y;
            }
            else{
                plat[i][y] = ' ';
                plat[i + 1][y] = 'X';
                i++;
                Sleep(100);
                Bopx = i;
                Bopy = y;
                MadaKnight_Attack(mx, my);
                Makearray();
            }
            break;

        case 32:
            weaponry(i , y);
            break;


        default:
            system("cls");
            break;
        }


    }
}

int Bossario() { //to int main() pou kalei ta ypoloipa funtions.
    MadaKnight_Spawn(10, 10);
    player(47, 2);

    return 1;

}
