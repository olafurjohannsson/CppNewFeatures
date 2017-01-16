

#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>

const int WIDTH = 40;
const int HEIGHT = 20;

char SCREEN[WIDTH][HEIGHT];
char OLD_SCREEN[WIDTH][HEIGHT];

void reset() {
    std::memset((char*)SCREEN, 0x00, 40 * 20);
}

enum Color
{
    NONE = 0,
    BLACK, RED, GREEN,
    YELLOW, BLUE, MAGENTA,
    CYAN, WHITE
};

static std::string set_color(Color foreground = NONE, Color background = NONE)
{
    std::stringstream s;
    s << "\033[";
    if (!foreground && ! background){
        s << "0"; // reset colors if no params
    }
    if (foreground) {
        s << 29 + foreground;
        if (background) s << ";";
    }
    if (background) {
        s << 39 + background;
    }
    s << "m";
    return s.str();
}

bool game_running = true;
int main() {
    
    while (game_running) 
    {
        system("clear");
        for (int i = 0; i < WIDTH + 2; i++)
        {
            if (i == 0 || i == WIDTH)
                std::cout << "*";
            else
                std::cout << " ";

            for (int j = 0; j < HEIGHT + 2; j++)
            {
                if (j == 0 || j == HEIGHT)
                    std::cout << "*";
            }
            std::cout << std::endl;
        }
        usleep(2000);
    }
    


}
