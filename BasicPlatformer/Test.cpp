#include <iostream>
#include <conio.h> // For _getch() and _kbhit()

using namespace std;

// Define the game area
const int width = 20;
const int height = 10;

// Player position
int playerX, playerY;

// Input flag
bool bInput;

// Initialize the game
void Setup() {
    playerX = width / 2;
    playerY = height - 2;
    bInput = false;
}

// Draw the game area and player
void Draw() {
    system( "cls" );
    for ( int i = 0; i < width + 2; i++ ) cout << "#";
    cout << endl;

    for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < width; j++ ) {
            if ( j == 0 ) cout << "#";
            if ( i == playerY && j == playerX ) cout << "P";
            else cout << " ";
            if ( j == width - 1 ) cout << "#";
        }
        cout << endl;
    }

    for ( int i = 0; i < width + 2; i++ ) cout << "#";
    cout << endl;
}

// Handle player input
void Input() {
    bInput = _kbhit();
    if ( bInput ) {
        char ch = _getch();
        switch ( ch ) {
        case 'a':
            if ( playerX > 0 ) playerX--;
            break;
        case 'd':
            if ( playerX < width - 1 ) playerX++;
            break;
        case 'w':
            if ( playerY > 0 ) playerY--;
            break;
        case 's':
            if ( playerY < height - 1 ) playerY++;
            break;
        }
    }
}

int main() {
    Setup();
    while ( true ) {
        Draw();
        Input();
    }
    return 0;
}
