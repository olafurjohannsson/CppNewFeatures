#include <iostream>

int width = 40;
int height = 20;

void Draw()
{
    std::system("clear");
    for (int i=0; i < width + 2; i++)
        std::cout << "\xB2";
    std::cout << std::endl;
}

void Input()
{

}

void Logic()
{

}


int main() {
    Draw();
    Input();
    Logic();
}
