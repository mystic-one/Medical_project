#ifndef NAME_AND_TIMER_H
#define NAME_AND_TIMER_H


// function for setting the cursor position
COORD coord = {0, 0};
void gotoxy(int x, int y) // function for setting the cursor postion
{						  // on the console
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// function declarations

void Shop_Name();
void timer();


void Shop_Name()
{
    gotoxy(83,2); // To set cursor position to the top center of screen
    printf("Medimart\n");
    gotoxy(76,3);
    printf("Get Well, Live Better!\n");
}

void timer()
{
    struct tm* local;
    time_t t = time(NULL);
    local = localtime(&t);
    gotoxy(100, 0);
    printf("%s", asctime(local));  // asctime converts structures to strings
}
#endif
