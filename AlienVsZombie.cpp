// ***************************************************************************************************** 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT7L 
// Names: MUHAMMAD AFIQ DANISH BIN SUNARDI | MUHAMMAD AMIR ADIB BIN MOHD AMINUDDIN | HAKEEM BIN AMINUDIN 
// IDs: 1211103424 | 1211103233 | 1211103830 
// Emails: 1211103424@student.mmu.edu.my | 1211103233@student.mmu.edu.my | 1211103830@student.mmu.edu.my 
// Phones: 0102870286 | 0183831880 | 01121380773 
// ***************************************************************************************************** 


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
    Game(int dimX, int dimY);
    void init(int dimX, int dimY);
    void display() const;

    void setObject(int &x, int &y, char ch);
    void removeObject(int x, int y, string n);
};
class Alien
{
private:
    int x_, y_;
    int dimX;
    int dimY;
public:
    Alien(int rowNumber, int columnNumber);
    void land(Game &Game);

    void move(Game &Game, string n);
};

Alien::Alien(int rowNumber, int columnNumber)
{
    this->dimX = rowNumber;
    this->dimY = columnNumber;
}



Game::Game(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Game::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', 'h', 'p', ' ', 'r', ' ', ' ' ,'^', '>', 'v', '<'};
    int noOfObjects = 12; // number of objects in the objects array
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

void Game::display() const
{
    //display header
    for (int i= 0; i<dimX_/2 + 1; ++i)
    {
        cout << "__--";
    }
    cout << "_" << endl;
    if (dimX_ > 9)
    {
        for (int i= 0; i<dimX_/2 ; ++i)
        {
        cout << " ";
        }
    }
    
    cout << " .: Alien vs Zombie :." << endl;
    for (int i= 0; i<dimX_/2 + 1; ++i)
    {
        cout << "__--";
    }
    cout << "_" << endl;

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
        cout << setw(2) << (i+1);
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
    cout << "  ";
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
    cout << "  ";
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
        y = y - 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (y == 0)
    {
        y = y + 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (x > dimX_)
    {
        x = x - 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else if (x == 0)
    {
        x = x + 1;
        map_[dimY_ - y][x - 1] = 'A';
    }
    else
    {
        map_[dimY_ - y][x - 1] = 'A';
    }
}

void test(int board[])
{
    int dimX = board[1], dimY = board[0];
    int x, y;
    x = ceil(double(dimX)/2);
    y = ceil(double(dimY)/2);
    Game Game(dimX, dimY);
    Alien groot(dimX, dimY);
    groot.land(Game);
    Game.display();
    while (true)
    {
        string n;
        cout << "<Enter help for more details on the commands>" << endl;
        cout << "Enter command: " << endl;
        cin >> n;
        if (n == "up") // move
        {
            int y_ = dimY - y;
            for (int i = 0; i < y_; i++)
            {
                groot.move(Game, n);
                Game.display();
                y = y + 1;
                system("pause");
            }
        }
        else if (n == "down") // turn left
        {
            int y_ = y-1;
            for (int i = 0; i < y_; i++)
            {
                groot.move(Game, n);
                Game.display();
                y = y - 1;
                system("pause");
            }
        }
        else if (n == "left") // turn left
        {
            int x_ = x - 1;
            for (int i = 0; i < x_; i++)
            {
                groot.move(Game, n);
                Game.display();
                x = x - 1;
                system("pause");
            }
        }
        else if (n == "right") // turn right
        {
            int x_ = dimX  - x;
            for (int i = 0; i < x_; i++)
            {
                groot.move(Game, n);
                Game.display();
                x = x + 1;
                system("pause");
            }
        }

        else if (n=="help")
        {
            cout<<"\nCommands:"<<endl;
            cout<< "1. up - Move up.\n";
            cout<< "2. down - Move down.\n";
            cout<< "3. right - Move right.\n";
            cout<< "4. left - Move left.\n";
            cout<< "5. help - Display these commands.\n"<<endl;


            system("pause");
            
            cout<<endl;
        }
    }
}

void startgame(int &rowNumber, int &columnNumber, int &zombieNumber)
{
    int board[] = {5, 9, 1};
    char response;
    cout << "\nDefault Game Settings" << endl;
    cout << "------------------------" << endl;
    cout << "Board Rows      : " << board[0] << endl;
    cout << "Board Columns   : " << board[1] << endl;
    cout << "Zombie Count    : " << board[2] << endl;

    cout << "\nDo you want to change the game settings? (y/n)\n=> ";
    cin >> response;

    if (response == 'n')
    {
        //system("Pause");

        srand(1);
        test(board);
    }

    else if (response == 'y')
    {
        while (true)
        {
            cout << "\nIntructions:" << endl;
            cout << "1. Insert only odd numbers when customizing the board size!" << endl;
            cout << "2. Row and Column number must be bigger than 1" << endl;

            cout << "\nBoard Settings" << endl;
            cout << "-----------------" << endl;

            cout << "Enter number of row => ";
            cin >> rowNumber;

            if (rowNumber % 2 == 0)
            {
                cout << "\nPlease insert an odd number!" << endl;
                continue;
            }

            else if(rowNumber <2)
            {
                cout << "\nPlease insert a number bigger than 1!" << endl;
                continue;
            }

            cout << "Enter number of columns => ";
            cin >> columnNumber;

            if (columnNumber % 2 == 0)
            {
                cout << "\nPlease insert an odd number!" << endl;
                continue;
            }

            else if(columnNumber <2)
            {
                cout << "\nPlease insert a number bigger than 1!" << endl;
                continue;
            }

            break;
        }

        cout << "\nZombie Settings" << endl;
        cout << "-----------------" << endl;

        cout << "Enter number of zombies => ";
        cin >> zombieNumber;

        cout << endl;

        board[0] = rowNumber; //y axis
        board[1] = columnNumber; //x axis
        board[2] = zombieNumber;


        //passing the entered_input into the object variables
        Alien obj(rowNumber , columnNumber);

        cout << "Settings Updated!";

        cout << endl;
        //system("Pause");


        srand(1);
        test(board);
    }
}

int main()
{
    int choice;
    bool gameOn = true;
    int board[] = {5, 9, 1};
    while (gameOn)
    {
        cout << "+---------------------------------------------+" << endl;
        cout << "|              Alien vs Zombie                |" << endl;
        cout << "|=============================================|" << endl;
        cout << "| Select:                                     |" << endl;
        cout << "| 1 => Start                                  |" << endl;
        cout << "| 2 => Load                                   |" << endl;
        cout << "| 3 => Quit                                   |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "Choice => ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int rowNumber, columnNumber, zombieNumber;
            startgame(rowNumber, columnNumber, zombieNumber);            
            break;

        case 2:

            gameOn = false;
            int loadchoice;
            bool loadmenu = true;
            cout << " Choose your save file \n";
            cout << " 1 => raja.txt \n";
            cout << " 2 => hakeem.txt\n";

            cout << " choose your file \n";

            cin >> loadchoice;

            if (loadchoice == 1)
            {
                char mainmenuselector;

                cout << "file one selcted\n";
                while (loadmenu)
                {
                    cout << "Do you want to go back?(y/n) \n";

                    cin >> mainmenuselector;
                    if (mainmenuselector == 'y')
                    {
                        loadmenu = false;
                        gameOn = true;
                    }
                    else if (mainmenuselector == 'n')
                    {
                        gameOn = false;
                        break;
                    }
                    else
                    {
                        loadmenu = true;
                    }
                }
            }
        }
    }
}