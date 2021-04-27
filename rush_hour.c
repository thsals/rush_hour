#include <windows.h>
#include <stdio.h>
#define garo 40
#define sero 24
INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;
int startx,starty;
int redcarx = 10;
int redcary = 10;
int now = 0;        // red 1
int last =0;
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
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int redcar[3][10] = {
    {2,2,2,2,2,2,2,2,2,2},
    {3,2,2,2,2,2,2,2,4,2},
    {2,2,2,2,2,2,2,2,2,2}
};
int bluetruck[3][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {}
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
void makeredcar() {
    int i,j;
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
    }

    gotoxy(garo + 1, sero + 1);
    for (i = sero + 1; i < sero + 6; i++) {
        for (j = garo; j < garo + 6; j++) {
            gotoxy(j, i);
            if (map1[i][j] == 1) {
                drw(BLACK, BLACK);
                printf(" ");
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

void click(int *xx, int *yy){
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
        if (rec.EventType == MOUSE_EVENT){// 마우스 이벤트일 경우

            if(map1[rec.Event.MouseEvent.dwMousePosition.Y][rec.Event.MouseEvent.dwMousePosition.X] == 2) {
                    now = 1;

                }
            else {
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
                if(last != now && now == 0) {
                    if(redcarx < mouse_x ) {
                        moveredcarright();
                    }
                    else if(redcarx >= mouse_x && map1[redcary][redcarx-5] == 0) moveredcarleft();
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
    //system("cis");
    map1print();
    CursorView(0);
    makeredcar();
    int xx,yy;
    while (1){

        click(&xx, &yy);
        drw(BLACK, WHITE);
        gotoxy(3,28);
        printf("%2d %2d\n",xx,yy);

    }

}
