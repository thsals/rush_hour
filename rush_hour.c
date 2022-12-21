#include <windows.h>
#include <stdio.h>
#define garo 40
#define sero 24
INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;
int startx,starty;
int redcarx = 10;
int redcary = 9;
int bluetruckx = 20;
int bluetrucky = 6;
int now = 0;        // red 2 blue 3
int last =0;
int stagex= 3;
int stagey =0 ;
int stagearr[5][5]  = {
    {1,6,11,16,21},
    {2,7,12,17,22},
    {3,8,13,18,23},
    {4,9,14,19,24},
    {5,10,15,20,25}
};
int map1[24][40] =
{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int redcar[3][10] = {
    {2,2,2,2,2,2,2,2,2,2},
    {3,2,2,2,2,2,2,2,4,2},
    {2,2,2,2,2,2,2,2,2,2}
};
int bluetruck[9][5] = {
    {2,2,2,2,2},
    {2,2,2,2,2},
    {2,2,2,2,2},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1}


};
enum colorName
{
    BLACK,
    D_BLUE,
    D_GREEN,
    D_SKYBLUE,
    D_RED,
    D_VIOLET,
    D_YELLOW,
    GRAY,
    D_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}
void drw(int bgColor, int textColor) {


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);

}
void makecar(int a) {

    int i,j;
    if(a == 1) {
        gotoxy(redcarx, redcary);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 10; j++) {
                map1[i+redcary][j+redcarx] = 2;
                if (redcar[i][j] == 2) {


                    gotoxy(redcarx + j, redcary + i);
                    drw(RED, RED);
                    printf(" ");
                }
                if (redcar[i][j] == 3) {

                    gotoxy(redcarx + j, redcary + i);
                    drw(BLACK, BLACK);
                    printf(" ");
                }
                if (redcar[i][j] == 4) {

                    gotoxy(redcarx + j, redcary + i);
                    drw(BLUE, BLUE);
                    printf(" ");
                }
            }
        }
    }
    if(a == 2) {
        gotoxy(bluetruckx, bluetrucky);
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 5; j++) {
                map1[i+bluetrucky][j+bluetruckx] = 3;
                if (bluetruck[i][j] == 1) {


                    gotoxy(bluetruckx + j, bluetrucky + i);
                    drw(D_BLUE, D_BLUE);
                    printf(" ");
                }
                if (bluetruck[i][j] == 2) {

                    gotoxy(bluetruckx + j, bluetrucky + i);
                    drw(BLUE, BLUE);
                    printf(" ");
                }
                if (bluetruck[i][j] == 3) {

                    gotoxy(bluetruckx + j, bluetrucky + i);
                    drw(BLUE, BLUE);
                    printf(" ");
                }
            }
        }
    }

}
void map1print() {
    int i, j;
    for (i = 0; i < sero; i++) {
        for (j = 0; j < garo; j++) {

            gotoxy(j, i);
            if (map1[i][j] == 1) {

                drw(GRAY, GRAY);
                printf(" ");
            }
        }
        Sleep(100);
    }


}
void stage() {
    int i,j;
    int cnt=1;

    for(j=0;j<25;j+=5) {
        for(i=0;i<5;i++){
            gotoxy(j,i);
            printf("%2d",cnt++);
        }
    }
    gotoxy(2,7);
    printf("Press The Space Bar");
    gotoxy(stagex,stagey);
    printf("0");
    while(1) {
        if(GetAsyncKeyState(VK_DOWN)) {
            if(stagey < 4) {
                gotoxy(stagex,stagey);
                drw(BLACK,BLACK);
                printf(" ");
                stagey+=1;
                drw(BLACK,WHITE);
                gotoxy(stagex,stagey);
                printf("0");
                Sleep(250);
            }
        }
        if(GetAsyncKeyState(VK_UP)) {
            if(stagey >0) {
                gotoxy(stagex,stagey);
                drw(BLACK,BLACK);
                printf(" ");
                stagey-=1;
                drw(BLACK,WHITE);
                gotoxy(stagex,stagey);
                printf("0");
                Sleep(250);
            }
        }
        if(GetAsyncKeyState(VK_LEFT)) {
            if(stagex >4) {
                gotoxy(stagex,stagey);
                drw(BLACK,BLACK);
                printf(" ");
                stagex-=5;
                drw(BLACK,WHITE);
                gotoxy(stagex,stagey);
                printf("0");
                Sleep(250);
            }
        }
        if(GetAsyncKeyState(VK_RIGHT)) {
            if(stagex < 20) {
                gotoxy(stagex,stagey);
                drw(BLACK,BLACK);
                printf(" ");
                stagex+=5;
                drw(BLACK,WHITE);
                gotoxy(stagex,stagey);
                printf("0");
                Sleep(250);
            }
        }
        if(GetAsyncKeyState(VK_SPACE)) {
            for(int i=0;i<10;i++) {
                for(int j=0;j<27;j++) {
                    gotoxy(j,i);
                    drw(BLACK,BLACK);
                    printf(" ");
                }
            }
            if(stagearr[stagey][stagex/5] == 1) {
                map1print();

                makecar(2);
                makecar(1);
                break;
            }
        }
    }
}

void moveredcarright(){
    int i,j;
    for(i=0;i<3;i++) {
        for(j=0;j< 10;j++) {
            map1[i+redcary][j+redcarx] = 0;
            gotoxy(redcarx + j, redcary + i);
            drw(BLACK,BLACK);
            printf(" ");
        }
    }
    redcarx+=5;
    gotoxy(redcarx, redcary);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
                map1[i+redcary][j+redcarx] = 2;
            if (redcar[i][j] == 2) {

                gotoxy(redcarx + j, redcary + i);
                drw(RED, RED);
                printf(" ");
            }
            if (redcar[i][j] == 3) {

                gotoxy(redcarx + j, redcary + i);
                drw(BLACK, BLACK);
                printf(" ");
            }
            if (redcar[i][j] == 4) {

                gotoxy(redcarx + j, redcary + i);
                drw(BLUE, BLUE);
                printf(" ");
            }
        }
    }

}
void moveredcarleft(){
    int i,j;
    for(i=0;i<3;i++) {
        for(j=0;j< 10;j++) {
            map1[i+redcary][j+redcarx] = 0;
            gotoxy(redcarx + j, redcary + i);
            drw(BLACK,BLACK);
            printf(" ");
        }
    }
    redcarx-=5;
    gotoxy(redcarx, redcary);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
                map1[i+redcary][j+redcarx] = 2;
            if (redcar[i][j] == 2) {

                gotoxy(redcarx + j, redcary + i);
                drw(RED, RED);
                printf(" ");
            }
            if (redcar[i][j] == 3) {

                gotoxy(redcarx + j, redcary + i);
                drw(BLACK, BLACK);
                printf(" ");
            }
            if (redcar[i][j] == 4) {

                gotoxy(redcarx + j, redcary + i);
                drw(BLUE, BLUE);
                printf(" ");
            }
        }
    }

}
void moveseroup() {
    int i,j;
    for(i=0;i<9;i++) {
        for(j=0;j< 5;j++) {
            map1[i+bluetrucky][j+bluetruckx] = 0;
            gotoxy(bluetruckx + j, bluetrucky + i);
            drw(BLACK,BLACK);
            printf(" ");
        }
    }
    bluetrucky-=3;
    gotoxy(bluetruckx, bluetrucky);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
                map1[i+bluetrucky][j+bluetruckx] = 3;
            if (bluetruck[i][j] == 1) {

                gotoxy(bluetruckx + j, bluetrucky + i);
                drw(D_BLUE, D_BLUE);
                printf(" ");
            }
            if (bluetruck[i][j] == 2) {

                gotoxy(bluetruckx + j, bluetrucky + i);
                drw(BLUE,BLUE);
                printf(" ");
            }

        }
    }

}
void moveserodown() {
    int i,j;
    for(i=0;i<9;i++) {
        for(j=0;j< 5;j++) {
            map1[i+bluetrucky][j+bluetruckx] = 0;
            gotoxy(bluetruckx + j, bluetrucky + i);
            drw(BLACK,BLACK);
            printf(" ");
        }
    }
    bluetrucky+=3;
    gotoxy(bluetruckx, bluetrucky);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 5; j++) {
                map1[i+bluetrucky][j+bluetruckx] = 3;
            if (bluetruck[i][j] == 1) {

                gotoxy(bluetruckx + j, bluetrucky + i);
                drw(D_BLUE, D_BLUE);
                printf(" ");
            }
            if (bluetruck[i][j] == 2) {

                gotoxy(bluetruckx + j, bluetrucky + i);
                drw(BLUE,BLUE);
                printf(" ");
            }

        }
    }

}
void click(int *xx, int *yy){
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
        if (rec.EventType == MOUSE_EVENT){// 마우스 이벤트일 경우

            if(map1[rec.Event.MouseEvent.dwMousePosition.Y][rec.Event.MouseEvent.dwMousePosition.X] == 2) {
                    now = 2;

            }
            if(map1[rec.Event.MouseEvent.dwMousePosition.Y][rec.Event.MouseEvent.dwMousePosition.X] == 3) {
                    now = 3;

            }
            if(map1[rec.Event.MouseEvent.dwMousePosition.Y][rec.Event.MouseEvent.dwMousePosition.X] == 0) {
                    now = 0;
            }

            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED){ // 좌측 버튼이 클릭되었을 경우
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
                drw(BLACK, WHITE);
                gotoxy(3,26);
                printf("%2d %2d\n",mouse_x,mouse_y);


                drw(BLACK, WHITE);
                gotoxy(3,27);
                printf("%d %d",last,now);
                if(mouse_y<=sero&&mouse_x<=garo) {
                    gotoxy(3,30);
                    printf("%d", map1[mouse_y][mouse_x]);
                }
                if(last != now && now == 0 &&last==2) {
                    if(redcarx < mouse_x && map1[redcary][redcarx+10]  == 0) {
                        moveredcarright();
                    }
                    else if(redcarx >= mouse_x && map1[redcary][redcarx-5] == 0) moveredcarleft();
                }
                if(last != now && now == 0 &&last==3) {
                    if(bluetrucky > mouse_y && map1[bluetrucky-3][bluetruckx]  == 0) {
                        moveseroup();
                    }
                    else if(redcarx < mouse_x && map1[bluetrucky+9][bluetruckx] == 0) moveserodown();
                }
                *xx=mouse_x; //x값을 넘김
                *yy=mouse_y; //y값을 넘김



                break;
            }
            last = now;
        }
    }
}




int main(){
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    //마우스 입력모드로 바꿈
    CursorView(0);
    //system("cis");
    stage();

    int xx,yy;
    while (1){

        click(&xx, &yy);
        drw(BLACK, WHITE);
        gotoxy(3,28);
        printf("%2d %2d\n",xx,yy);

    }

}
