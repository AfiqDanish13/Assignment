#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <cmath>
using namespace std;
class Game
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
    Game(int dimX = 15, int dimY = 5);
    void init(int dimX, int dimY);
    void display() const;

    int getDimX() const;
    int getDimY() const;

    void setObject(int &x, int &y, char ch);
    void removeObject(int x, int y, string n);

    bool isEmpty(int x, int y);
    bool isInsideMap(int x, int y);
};
class Alien
{
private:
    int x_, y_;
    int dimX = 15;
    int dimY = 5;
    char heading_; // either '^', '>', '<' or 'v'
public:
    Alien();
    void land(Game &Game);
    int getX() const;
    int getY() const;
    char getHeading() const;
    void move(Game &Game, string n);
};
Alien::Alien()
{
}
Game::Game(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Game::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' '};
    int noOfObjects = 5; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)

    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}
void Alien::land(Game &Game)
{
    x_ = ceil(double(dimX) / 2);
    y_ = ceil(double(dimY) / 2);
    Game.setObject(x_, y_, 'A');
}
int Alien::getX() const
{
    return x_;
}

int Alien::getY() const
{
    return y_;
}
char Alien::getHeading() const
{
    return heading_;
}

void Alien::move(Game &Game, string n)
{
    if (n == "up")
    {
        y_ = y_ + 1;
        Game.setObject(x_, y_, 'A');
        Game.removeObject(x_, y_, n);
        // Game.setObject(x_, y_ - 1, heading_ = ' ');
    }
    else if (n == "right")
    {
        x_ = x_ + 1;
        Game.setObject(x_, y_, 'A');
        Game.removeObject(x_, y_, n);
        // Game.setObject(x_ - 1, y_, heading_ = ' ');
    }
    else if (n == "left")
    {
        x_ = x_ - 1;
        Game.setObject(x_, y_, 'A');
        Game.removeObject(x_, y_, n);
        // Game.setObject(x_ - 1, y_, heading_ = ' ');
    }
    else if (n == "down")
    {
        y_ = y_ - 1;
        Game.setObject(x_, y_, 'A');
        Game.removeObject(x_, y_, n);
        // Game.setObject(x_ - 1, y_, heading_ = ' ');
    }
}
void Game::removeObject(int x, int y, string n)
{
    if (n == "up")
    {
        int delX = x;
        int delY = y - 1;
        map_[dimY_ - delY][delX - 1] = '.';
    }
    else if (n == "right")
    {
        int delX = x - 1;
        int delY = y;
        map_[dimY_ - delY][delX - 1] = '.';
    }
    else if (n == "left")
    {
        int delX = x + 1;
        int delY = y;
        map_[dimY_ - delY][delX - 1] = '.';
    }
    else if (n == "down")
    {
        int delX = x;
        int delY = y + 1;
        map_[dimY_ - delY][delX - 1] = '.';
    }
}
int Game::getDimX() const 
{
    return dimX_;
}
int Game::getDimY() const
{
    return dimY_;
}
void Game::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " .: groot, Welcome to Game:." << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
void Game::setObject(int &x, int &y, char ch)
{
    int boundX_ = x;
    if (y > dimY_)
    {
        cout << "Oops ! You hit the boundaries, therefore you stop here" << endl;
        y = y - 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (y == 0)
    {
        cout << "Oops ! You hit the boundaries, therefore you stop here" << endl;
        y = y + 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (x > dimX_)
    {
        cout << "Oops ! You hit the boundaries, therefore you stop here" << endl;
        x = x - 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (x == 0)
    {
        cout << "Oops ! You hit the boundaries, therefore you stop here" << endl;
        x = x + 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else
    {
        map_[dimY_ - y][x - 1] = 'A';
    }
}

bool Game::isEmpty(int x, int y)
{
    return map_[dimY_ - y][x - 2] == ' ';
}

bool Game::isInsideMap(int x, int y)
{
    return x >= 1 && x <= dimX_ && y >= 1 && y <= dimY_;
}
void test2_2()
{
    Game Game;
    Alien groot;
    groot.land(Game);
    Game.display();
    while (true)
    {
        string n;
        cout << "Enter command: " << endl;
        cin >> n;
        if (n == "up") // move
        {
            for (int i = 0; i < 5-3; i++)
            {
                groot.move(Game, n);
                Game.display();
            }
        }
        else if (n == "down") // turn left
        {
            for (int i = 0; i < 5-3; i++)
            {
                groot.move(Game, n);
                Game.display();
            }
        }
        else if (n == "left") // turn left
        {
            for (int i = 0; i < 15-8; i++)
            {
                groot.move(Game, n);
                Game.display();
            }
        }
        else if (n == "right") // turn right
        {
            for (int i = 0; i < 15-8; i++)
            {
                groot.move(Game, n);
                Game.display();
            }
        }
    }
}
int main()
{

    srand(1); // use this for fixed map during testing
    // srand(time(NULL)); // try this for random map
    // test1_1();
    // test1_3();
    // test1_4();
    // test1_5();
    // test1_6();
    // test2_1();
    test2_2();
}