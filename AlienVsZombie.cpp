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
#include <fstream>

using namespace std;
// game class
class Game
{
private:
    int column, row, zombie;

public:
    Game(int row, int column, int zombie);
    void start(int row, int column, int zombie);
    void al(int &alife, int &aattack);
    void board(int row, int column, int zombie, char *random, int alife, int aattack, int *zombdata);
};

Game::Game(int row, int column, int zombie)
{
}


// create gameboard
void Game::board(int row, int column, int zombie, char *random, int alife, int aattack, int *zombdata)
{
    // display header
    cout << endl;
    for (int i = 0; i < column / 2 + 1; ++i)
    {
        cout << "_--_";
    }
    cout << endl;
    cout << ".: Alien vs Zombie :." << endl;
    for (int i = 0; i < column / 2 + 1; ++i)
    {
        cout << "_--_";
    }
    cout << endl;
    int r;
    int c;
    int z = 0;
    int n;
    char ran;
    for (r = 0; r < row; r++)
    {
        cout << " ";
        if (row > 9)
        {
            cout << " ";
        }
        for (c = 0; c < column; c++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        if (row > 9 && r < 9)
        {
            cout << " ";
        }
        cout << r + 1;
        for (c = 0; c < column; c++)
        {
            cout << "|";
            cout << *(random + r * column + c);
        }
        cout << "|" << endl;
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (c = 0; c < column; c++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    int tens = (column - 10) / 10;
    int dec = column % 10;
    int t = 1;
    int d;
    if (column > 10)
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (c = 0; c < 9; c++)
        {
            cout << "  ";
        }
        for (t = 0; t < tens; t++)
        {
            for (c = 0; c < 10; c++)
            {
                cout << t + 1 << " ";
            }
        }
        for (d = 0; d <= dec; d++)
        {
            cout << t + 1 << " ";
        }
        cout << endl;
        if (row > 10)
        {
            cout << " ";
        }
        cout << " ";
        int m = 1;
        for (m = 0; m <= tens; m++)
        {
            for (c = 1; c < 10; c++)
            {
                cout << " " << c;
            }
            cout << " 0";
        }
        for (d = 1; d <= dec; d++)
        {
            cout << " " << d;
        }
    }
    else
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (d = 1; d <= dec; d++)
        {
            cout << d << " ";
        }
    }
    cout << endl
         << endl
         << "-> Alien   : Life " << alife << ", Attack " << aattack << endl;
    for (z = 0; z < zombie; z++)
    {
        cout << "   Zombie " << z + 1 << ": Life " << *(zombdata + z * 4) << ", Attack " << *(zombdata + z * 4 + 1) << ", Range " << *(zombdata + z * 4 + 2) << endl;
    }
    cout << endl;
}

void help()
{
    cout << "           Object           " << endl;
    cout << "+--------------------------+" << endl;
    cout << "'a'\t:alien (you)" << endl;
    cout << "'z'\t:zombie (your enemy)" << endl;
    cout << "'h'\t:health (add 20 life to alien) " << endl;
    cout << "'p'\t:pod (instanly inflicts 10 damage to zombie when hit by alien) " << endl;
    cout << "'r'\t:rock (hides a game object, reveals when hit by alien, stop when hit by alien" << endl;
    cout << "' '\t:space (just a empty space)" << endl;
    cout << "'.'\t:trail (left by alien moves, reset to random object after Alien's turn ends) " << endl;
    cout << "           Command           " << endl;
    cout << "+---------------------------+" << endl;
    cout << "up\t:Alien to move up." << endl;
    cout << "down\t:Alien to move down." << endl;
    cout << "left\t:Alien to move left." << endl;
    cout << "right\t:Alien to move right." << endl;
    cout << "arrow\t:Switch the direction of an arrow object in the game board." << endl;
    cout << "skill\t:Special ability that can be selected to play the game." << endl;
    cout << "help\t:List and describe the commands that the player can use in the game." << endl;
    cout << "save\t:Save the current game to a file." << endl;
    cout << "load\t:Load a saved game from a file." << endl;
    cout << "quit\t:Quit the game while still in play." << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << endl;
}

void Game::al(int &alife, int &aattack)
{
    alife = 100;
    aattack = 0;
}

void Game::start(int row, int column, int zombie)
{
    system("cls");
    bool win = false;
    bool zombiedead = false;
    bool playerquit = false;
    char com, ran;
    int r, c, z;
    int w = (column * 2 - 19) / 2;
    int alife = 100;
    int aattack = 0;
    int zombiedeadnum = 0;
    int zlife, zattack, range;
    int skillCount = 1;
    vector<char> object = {'^', 'v', '<', '>', 'h', 'p', 'r', ' '};
    vector<char> norock = {'^', 'v', '<', '>', 'h', 'p', ' '};
    char random[row][column];
    int zombdata[zombie][4];
    srand(time(NULL));
    int o = object.size();
    int nrock = norock.size();
    // set elements inside the gameboard
    for (c = 0; c < w; c++)
    {
        cout << " ";
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            ran = object[rand() % o];
            random[r][c] = ran;
        }
    }

    // place alien at the middle of the gameboard
    random[row / 2][column / 2] = 'A';

    // add zombie into the gameboard
    for (z = 0; z < zombie;)
    {
        r = rand() % (row - 1);
        c = rand() % (column - 1);
        if ((random[r][c] == 'A') || (random[r][c] == 'Z'))
        {
            continue;
        }
        else
        {
            random[r][c] = 'Z';
            z += 1;
        }
    }

    for (int z = 0; z < zombie;)
    {
        for (r = 0; r < row; r++)
        {
            for (c = 0; c < column; c++)
            {
                ran = random[r][c];
                if (ran == 'Z')
                {
                    char ram = char(49 + z);
                    random[r][c] = ram;
                    z += 1;
                }
            }
        }
    }
    al(alife, aattack);
    // zombie data and attributes
    for (z = 0; z < zombie; z++)
    {
        zlife = ((rand() % 4) * 50 + 100);
        zombdata[z][0] = zlife;
        zattack = ((rand() % 3) * 5 + 5);
        zombdata[z][1] = zattack;
        range = ((rand() % 3) + 1);
        zombdata[z][2] = range;
    }

    do
    {
        bool turn = false;
        string command;
        char com;
        do
        {
            int arrowrow, arrowcolumn;
            char direction;
            bool arrowdone = false;
            while (!arrowdone)
            {
                board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                cout << "command> ";
                cin >> command;
                // function to change arrow
                if (command == "arrow")
                {
                    cout << "Enter row, column, and direction: ";
                    cin >> arrowrow >> arrowcolumn >> direction;
                    // cout << arrowrow << arrowcolumn << direction;
                    if (random[arrowrow - 1][arrowcolumn - 1] == '^' || random[arrowrow - 1][arrowcolumn - 1] == 'v' || random[arrowrow - 1][arrowcolumn - 1] == '<' || random[arrowrow - 1][arrowcolumn - 1] == '>')
                    {
                        switch (direction)
                        {
                        case 'u':
                            random[arrowrow - 1][arrowcolumn - 1] = '^';
                            break;
                        case 'd':
                            random[arrowrow - 1][arrowcolumn - 1] = 'v';
                            break;
                        case 'l':
                            random[arrowrow - 1][arrowcolumn - 1] = '<';
                            break;
                        case 'r':;
                            random[arrowrow - 1][arrowcolumn - 1] = '>';
                            break;
                        }
                        cin >> command;
                        cout << "The direction of arrow was changed." << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cin >> command;
                        cout << "That is not an arrow.";
                        system("pause");
                        system("cls");
                    }
                }
                else if (command == "up")
                {
                    com = '^';
                    arrowdone = true;
                }
                else if (command == "down")
                {
                    com = 'v';
                    arrowdone = true;
                }
                else if (command == "left")
                {
                    com = '<';
                    arrowdone = true;
                }
                else if (command == "right")
                {
                    com = '>';
                    arrowdone = true;
                }
                else if (command == "skill")
                {
                    cout << "You have regen skill \nSkill remaining: " << skillCount << endl;
                    system("pause");
                    if (skillCount != 0)
                    {
                        al(alife, aattack);
                        skillCount -= 1;
                    }
                    else
                    {
                        cout << "you run out of skill !";
                    }
                    system("cls");
                }
                else if (command == "save")
                {
                    int m = column, n = row;
                    string name;
                    cout << "Choose a name to save current file: ";
                    cin >> name;
                    string file = ".txt";
                    string fileName = name + file;
                    ofstream MyFile(fileName);
                    MyFile << row << " "
                           << column << " "
                           << zombie << endl;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (random[i][j] == ' ')
                            {
                                MyFile << '_' << endl;
                            }
                            else
                            {
                                MyFile << random[i][j] << endl;
                            }
                        }
                    }
                    MyFile << alife << " " << aattack << endl;
                    for (z = 0; z < zombie; z++)
                    {
                        MyFile << zombdata[z][0] << " "
                               << zombdata[z][1] << " "
                               << zombdata[z][2] << endl;
                    }
                    cout << "File saved successfully" << endl;
                    system("pause");
                    system("cls");
                    cout << endl;
                    MyFile.close();
                }
                else if (command == "quit")
                {
                    playerquit = true;
                    system("cls");
                    break;
                }
                else
                {
                    help();
                }
            }

            if (playerquit == false)
            {
                bool movedone = false;
                int ar, ac, zr, zc;
                char going;
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < column; c++)
                    {
                        char A = random[r][c];
                        if (A == 'A')
                        {
                            ar = r;
                            ac = c;
                        }
                    }
                }
                int gr, gc;
                while (!movedone)
                {
                    switch (com)
                    {
                    // get going place
                    case '^':
                        gr = ar - 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case 'v':
                        gr = ar + 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case '<':
                        gr = ar;
                        gc = ac - 1;
                        going = random[gr][gc];
                        break;
                    case '>':
                        gr = ar;
                        gc = ac + 1;
                        going = random[gr][gc];
                        break;
                    }
                    // done

                    // check going place
                    char nextcom;
                    string alienstatus, zombielifedamage, zombiestatus;

                    switch (going)
                    {
                    case '^':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '^';
                        break;
                    case 'v':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = 'v';
                        break;
                    case '<':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '<';
                        break;
                    case '>':
                        alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                        aattack = aattack + 20;
                        nextcom = '>';
                        break;
                    case 'h':
                        nextcom = com;
                        alife = alife + 20;
                        if (alife > 100)
                        {
                            alife = 100;
                            alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\nAlien's health in limited at 100.\n";
                        }
                        else
                        {
                            alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\n";
                        }
                        break;
                    case 'p':
                    {
                        int check;
                        nextcom = com;
                        bool podatt = false;
                        int ragr = -1;
                        int ragc = -1;
                        int ragrt, ragct;
                        int zombieinrange = 0;
                        cout << "Alien finds a pod.\n";
                        while (podatt == false)
                        {
                            for (ragrt = ragr; ragrt <= -ragr; ragrt++)
                            {
                                int arragrt = gr + ragrt;
                                if (arragrt < 0)
                                {
                                    arragrt = 0;
                                    ragrt = 0;
                                }
                                for (ragct = ragc; ragct <= -ragc; ragct++)
                                {
                                    for (z = 0; z < zombie; z++)
                                    {
                                        char go = (z + 49);
                                        int acragct = gc + ragct;
                                        char alienattacting = random[arragrt][acragct];
                                        if (acragct < 0)
                                        {
                                            acragct = 0;
                                            ragct = 0;
                                            alienattacting = random[arragrt][acragct];
                                        }
                                        else if (acragct > column)
                                        {
                                            alienattacting = ' ';
                                        }

                                        if (alienattacting == go)
                                        {
                                            zombieinrange = zombieinrange + 1;
                                            zombdata[z][3] = 1;
                                        }
                                    }
                                }
                            }
                            if (zombieinrange > 0)
                            {
                                while (podatt == false)
                                {
                                    int rannum = rand() % 5;
                                    char zombpod = (rannum + 49);
                                    if (zombdata[rannum][3] == 1)
                                    {
                                        zombdata[rannum][0] = zombdata[rannum][0] - 10;
                                        // cout << zombdata[rannum][0];
                                        cout << "Zombie " << zombpod << " receive 10 damage" << endl;
                                        if (zombdata[rannum][0] <= 0) // not yet receive damage
                                        {
                                            cout << "Zombie " << zombpod << " is dead\n";
                                            random[gr][gc] = ' ';
                                            zombiedeadnum = zombiedeadnum + 1;
                                        }
                                        else
                                        {
                                            cout << "Zombie " << zombpod << " is still alive\n";
                                        }
                                        podatt = true;
                                    }
                                }
                            }
                            else
                            {
                                ragc = ragc - 1;
                                ragr = ragr - 1;
                            }
                        }
                        break;
                    }
                    case 'r':
                        com = 's';
                        nextcom = 's';
                        ran = norock[rand() % nrock];
                        random[gr][gc] = ran;
                        alienstatus = "Alien hits a rock, the object beneath the rock is revealed.\n";
                        break;
                    case ' ':
                        nextcom = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    case '.':
                        nextcom = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    default:
                        com = 's';
                        alienstatus = "Alien reached the side of the game.\n";
                        break;
                    }
                    // stop at the boundaries
                    if (ar == 0 && com == '^')
                    {
                        break;
                    }
                    else if (ar == row - 1 && com == 'V')
                    {
                        break;
                    }
                    else if (ac == 0 && com == '<')
                    {
                        break;
                    }
                    else if (ac == column - 1 && com == '>')
                    {
                        break;
                    }
                    //
                    for (z = 0; z < zombie; z++)
                    {
                        char go = (z + 49);
                        if (going == go)
                        {
                            zombdata[z][0] = zombdata[z][0] - aattack;
                            cout << "Alien attacks Zombie " << go << "\nZombie " << go << " receives a damage of " << aattack << endl;
                            alienstatus = "Alien hits zombie and stop.\n";
                            if (zombdata[z][0] <= 0)
                            {
                                cout << "Zombie " << go << " is dead\n";
                                random[gr][gc] = ' ';
                                zombiedeadnum = zombiedeadnum + 1;
                            }
                            else
                            {
                                cout << "Zombie " << go << " is still alive\n";
                            }
                        }
                    }

                    cout << alienstatus;
                    system("pause");
                    system("cls");
                    // alien movement
                    switch (com)
                    {
                    case '^':
                        random[ar][ac] = '.';
                        random[ar - 1][ac] = 'A';
                        ar = ar - 1;
                        break;
                    case 'v':
                        random[ar][ac] = '.';
                        random[ar + 1][ac] = 'A';
                        ar = ar + 1;
                        break;
                    case '<':
                        random[ar][ac] = '.';
                        random[ar][ac - 1] = 'A';
                        ac = ac - 1;
                        break;
                    case '>':
                        random[ar][ac] = '.';
                        random[ar][ac + 1] = 'A';
                        ac = ac + 1;
                        break;
                    case 's':
                        alienstatus = "";
                        turn = true;
                        movedone = true;
                        break;
                    }
                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                    com = nextcom;
                }
            }

            if (zombiedeadnum == zombie)
            {
                zombiedead = true;
            }
            if (zombiedead == false && playerquit == false)
            {
                cout << "Alien's turn ended.\n";
                system("pause");
                system("cls");
                aattack = 0;
                string alienturn;
                int alientrail = 0;
                for (r = 0; r < row; r++)
                {
                    for (c = 0; c < column; c++)
                    {
                        if (random[r][c] == '.')
                        {
                            ran = object[rand() % o];
                            random[r][c] = ran;
                            alienturn = "Alien's trail '.' is replaced by random objects.\n";
                            alientrail = alientrail + 1;
                        }
                    }
                }
                if (alientrail > 0)
                {
                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                    cout << alienturn;
                    system("pause");
                    system("cls");
                }

                // zombie movement's after alien finished turn
                for (z = 1; z <= zombie; z++)
                {
                    char moveAlien = (48 + z);
                    for (r = 0; r < row; r++)
                    {
                        for (c = 0; c < column; c++)
                        {
                            if (random[r][c] == moveAlien)
                            {
                                // determine valid moves
                                bool validMoves[4] = {true, true, true, true};
                                if (c == 0 || random[r][c - 1] == 'A')
                                {
                                    validMoves[0] = false; // left is not a valid move
                                }
                                if (c == column - 1 || random[r][c + 1] == 'A')
                                {
                                    validMoves[1] = false; // right is not a valid move
                                }
                                if (r == 0 || random[r - 1][c] == 'A')
                                {
                                    validMoves[2] = false; // up is not a valid move
                                }
                                if (r == row - 1 || random[r + 1][c] == 'A')
                                {
                                    validMoves[3] = false; // down is not a valid move
                                }

                                // choose a random valid move
                                int move;
                                do
                                {
                                    move = rand() % 4;
                                } while (!validMoves[move]);

                                // move in the chosen direction
                                switch (move)
                                {
                                case 0:
                                    random[r][c - 1] = moveAlien;
                                    break;
                                case 1:
                                    random[r][c + 1] = moveAlien;
                                    break;
                                case 2:
                                    random[r - 1][c] = moveAlien;
                                    break;
                                case 3:
                                    random[r + 1][c] = moveAlien;
                                    break;
                                }

                                // clear the old position
                                random[r][c] = ' ';

                                // break out of the loops
                                goto next_zombie;
                            }
                        }
                    }
                next_zombie:; // label for goto statement
                }
                bool zombiemovedone = false;
                while (!zombiemovedone)
                {
                    int zr, zc;
                    bool alieninrange = true;
                    for (z = 0; z < zombie; z++)
                    {
                        int range = zombdata[z][2];
                        char zombienumber = (z + 49);
                        for (int r = 0; r < row; r++)
                        {
                            for (int c = 0; c < column; c++)
                            {
                                if (random[r][c] == zombienumber)
                                {
                                    zr = r;
                                    zc = c;
                                    break;
                                }
                            }
                        }
                        for (int ragr = -range; ragr <= range; ragr++)
                        {
                            for (int ragc = -range; ragc <= range; ragc++)
                            {
                                char zombieattacking = random[zr + ragr][zc + ragc];
                                if (zombieattacking == 'A')
                                {
                                    int zombatt = zombdata[z][1];
                                    alife = alife - zombatt;
                                    board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                                    cout << "Alien is in the range of Zombie " << z + 1 << endl;
                                    cout << "Alien life reduce by " << zombdata[z][1] << endl;
                                    ragc = range + 1;
                                    ragr = range + 1;
                                    alieninrange = true;
                                    if (alife <= 0)
                                    {
                                        cout << "Alien die.\nYou lose the game!" << endl;
                                        turn = true;
                                        win = true;
                                        zombiemovedone = true;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    system("cls");
                                }
                                else
                                {
                                    alieninrange = false;
                                }
                            }
                        }
                        if (alieninrange == false)
                        {
                            board(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                            cout << "Alien is not in range of Zombie " << z + 1 << endl;
                            system("pause");
                        }
                        system("cls");
                    }
                    zombiemovedone = true;
                }
            }
            else if (zombiedead == true)
            {
                turn = true;
                win = true;
                cout << "All zombie is dead.\nYou win!" << endl;
                system("pause");
                system("cls");
            }
            else if (playerquit == true)
            {
                turn = true;
                win = true;
            }
        } while (!turn);
    } while (!win);
}

void Gameboard(int row, int column, int zombie, char *random, int alife, int aattack, int *zombdata)
{
    cout << ".: Alien vs Zombie :." << endl;
    int r;
    int c;
    int z = 0;
    int n;
    char ran;
    for (r = 0; r < row; r++)
    {
        cout << " ";
        if (row > 9)
        {
            cout << " ";
        }
        for (c = 0; c < column; c++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        if (row > 9 && r < 9)
        {
            cout << " ";
        }
        cout << r + 1;
        for (c = 0; c < column; c++)
        {
            cout << "|";
            // cout << random[r][c];
            cout << *(random + r * column + c);
        }
        cout << "|" << endl;
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (c = 0; c < column; c++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    int tens = (column - 10) / 10;
    int dec = column % 10;
    int t = 1;
    int d;
    if (column > 10)
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (c = 0; c < 9; c++)
        {
            cout << "  ";
        }
        for (t = 0; t < tens; t++)
        {
            for (c = 0; c < 10; c++)
            {
                cout << t + 1 << " ";
            }
        }
        for (d = 0; d <= dec; d++)
        {
            cout << t + 1 << " ";
        }
        cout << endl;
        if (row > 10)
        {
            cout << " ";
        }
        cout << " ";
        int m = 1;
        for (m = 0; m <= tens; m++)
        {
            for (c = 1; c < 10; c++)
            {
                cout << " " << c;
            }
            cout << " 0";
        }
        for (d = 1; d <= dec; d++)
        {
            cout << " " << d;
        }
    }
    else
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (d = 1; d <= dec; d++)
        {
            cout << d << " ";
        }
    }
    cout << endl
         << endl
         << "-> Alien   : Life " << alife << ", Attack " << aattack << endl;
    for (z = 0; z < zombie; z++)
    {
        cout << "   Zombie " << z + 1 << ": Life " << *(zombdata + z * 4) << ", Attack " << *(zombdata + z * 4 + 1) << ", Range " << *(zombdata + z * 4 + 2) << endl;
    }
    cout << endl;
}

void startgame(int &rowNumber, int &columnNumber, int &zombieNumber)
{
    int board[] = {5, 9, 1};
    char response, com;
    cout << "\nDefault Game Settings" << endl;
    cout << "------------------------" << endl;
    cout << "Board Rows      : " << board[0] << endl;
    cout << "Board Columns   : " << board[1] << endl;
    cout << "Zombie Count    : " << board[2] << endl;

    cout << "\nDo you want to change the game settings? (y/n)\n=> ";
    cin >> response;

    if (response == 'n')
    {
        // system("Pause");

        Game Game(board[0], board[1], board[2]);
        Game.start(board[0], board[1], board[2]);
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

            else if (rowNumber < 2)
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

            else if (columnNumber < 2)
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

        board[0] = rowNumber;    // y axis
        board[1] = columnNumber; // x axis
        board[2] = zombieNumber;

        cout << "Settings Updated!";

        cout << endl;
        // system("Pause");

        srand(1);
        Game Game(board[0], board[1], board[2]);
        Game.start(board[0], board[1], board[2]);
    }
}
void al(int &alife, int &aattack)
{
    alife = 100;
    aattack = 0;
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
        case 3:
            cout << "Thanks for playing the game!! \n";
            system("pause");
            gameOn = false;
            break;
        case 2:
            bool win = false;
            bool zombiedead = false;
            bool playerquit = false;
            int row = 5;
            int column = 9;
            int zombie = 1;
            char com, ran;
            int r, c, z;
            int w = (column * 2 - 19) / 2;
            int alife = 100;
            int aattack = 0;
            int zombiedeadnum = 0;
            int skillCount = 1;
            int zlife, zattack, range;
            vector<char> object = {'^', 'v', '<', '>', 'h', 'p', 'r', ' '};
            vector<char> norock = {'^', 'v', '<', '>', 'h', 'p', ' '};

            char random[row][column];
            int zombdata[zombie][4];
            srand(time(NULL));
            int o = object.size();
            int nrock = norock.size();
            al(alife, aattack);
            // zombie data
            cout << "Enter the name of your file: ";
            string name;
            cin >> name;
            string file = ".txt";
            string fileName = name + file;
            ifstream MyFile;
            // ifstream infile(fileName);
            MyFile.open(fileName);
            if (MyFile.fail())
            {
                cout << "File does not exist" << endl;
            }
            else
            {
                MyFile >> row;
                MyFile >> column;
                MyFile >> zombie;
                int x, y, z;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        MyFile >> random[i][j];
                    }
                }
                MyFile >> alife >> aattack;
                for (int z = 0; z < zombie; z++)
                {
                    MyFile >> zombdata[z][0] >> zombdata[z][1] >> zombdata[z][2];
                }
                MyFile.close();
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        if (random[i][j] == '_')
                        {
                            random[i][j] = ' ';
                        }
                    }
                }

                system("pause");
                system("cls");
            }

            do
            {
                bool turn = false;
                string command;
                char com;
                do
                {
                    int arrowrow, arrowcolumn;
                    char direction;
                    bool arrowdone = false;
                    while (!arrowdone)
                    {
                        Gameboard(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                        cout << "command> ";
                        cin >> command;
                        if (command == "arrow")
                        {
                            cout << "Enter row, column, and direction: ";
                            cin >> arrowrow >> arrowcolumn >> direction;
                            // cout << arrowrow << arrowcolumn << direction;
                            if (random[arrowrow - 1][arrowcolumn - 1] == '^' || random[arrowrow - 1][arrowcolumn - 1] == 'v' || random[arrowrow - 1][arrowcolumn - 1] == '<' || random[arrowrow - 1][arrowcolumn - 1] == '>')
                            {
                                switch (direction)
                                {
                                case 'u':
                                    random[arrowrow - 1][arrowcolumn - 1] = '^';
                                    break;
                                case 'd':
                                    random[arrowrow - 1][arrowcolumn - 1] = 'v';
                                    break;
                                case 'l':
                                    random[arrowrow - 1][arrowcolumn - 1] = '<';
                                    break;
                                case 'r':;
                                    random[arrowrow - 1][arrowcolumn - 1] = '>';
                                    break;
                                }
                                cin >> command;
                                cout << "The direction of arrow was changed." << endl;
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                cin >> command;
                                cout << "That is not an arrow.";
                                system("pause");
                                system("cls");
                            }
                        }
                        else if (command == "up")
                        {
                            com = '^';
                            arrowdone = true;
                        }
                        else if (command == "down")
                        {
                            com = 'v';
                            arrowdone = true;
                        }
                        else if (command == "left")
                        {
                            com = '<';
                            arrowdone = true;
                        }
                        else if (command == "right")
                        {
                            com = '>';
                            arrowdone = true;
                        }
                        else if (command == "skill")
                        {
                            cout << "You have regen skill \nSkill remaining: " << skillCount << endl;
                            system("pause");
                            if (skillCount != 0)
                            {
                                al(alife, aattack);
                                skillCount -= 1;
                            }
                            else
                            {
                                cout << "you run out of skill !";
                            }
                            system("cls");
                        }
                        else if (command == "save")
                        {
                            const int m = column, n = row;
                            string name;
                            cout << "Choose a name to save current file: ";
                            cin >> name;
                            string file = ".txt";
                            string fileName = name + file;
                            ofstream MyFile(fileName);
                            MyFile << row << endl
                                   << column << endl
                                   << zombie << endl;
                            for (int i = 0; i < m; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    MyFile << random[i][j] << endl;
                                }
                            }
                            cout << "File saved successfully" << endl;
                            system("pause");
                            system("cls");
                            cout << endl;
                            MyFile.close();
                        }
                        else if (command == "load")
                        {
                            const int m = column, n = row;
                            string name;
                            cout << "Enter the name of your file: ";
                            cin >> name;
                            string file = ".txt";
                            string fileName = name + file;
                            ifstream MyFile;
                            MyFile.open(fileName);
                            if (MyFile.fail())
                            {
                                cout << "File does not exist" << endl;
                            }
                            else
                            {
                                MyFile >> row, column, zombie;
                                MyFile.ignore(4);
                                for (int i = 0; i < m; i++)
                                {
                                    for (int j = 0; j < n; j++)
                                    {
                                        MyFile >> random[i][j];
                                        cout << random[i][j] << "|";
                                    }
                                    cout << endl;
                                }
                                MyFile.close();
                                system("pause");
                                system("cls");
                            }
                        }
                        else if (command == "quit")
                        {
                            playerquit = true;
                            system("cls");
                            break;
                        }
                        else
                        {
                            help();
                        }
                    }

                    if (playerquit == false)
                    {
                        bool movedone = false;
                        int ar, ac, zr, zc;
                        char going;
                        for (int r = 0; r < row; r++)
                        {
                            for (int c = 0; c < column; c++)
                            {
                                char A = random[r][c];
                                if (A == 'A')
                                {
                                    ar = r;
                                    ac = c;
                                }
                            }
                        }
                        int gr, gc;
                        while (!movedone)
                        {
                            switch (com)
                            {
                            // get going palce
                            case '^':
                                gr = ar - 1;
                                gc = ac;
                                going = random[gr][gc];
                                break;
                            case 'v':
                                gr = ar + 1;
                                gc = ac;
                                going = random[gr][gc];
                                break;
                            case '<':
                                gr = ar;
                                gc = ac - 1;
                                going = random[gr][gc];
                                break;
                            case '>':
                                gr = ar;
                                gc = ac + 1;
                                going = random[gr][gc];
                                break;
                            }
                            // done

                            // check going place
                            char nextcom;
                            string alienstatus, zombielifedamage, zombiestatus;

                            switch (going)
                            {
                            case '^':
                                alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                                aattack = aattack + 20;
                                nextcom = '^';
                                break;
                            case 'v':
                                alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                                aattack = aattack + 20;
                                nextcom = 'v';
                                break;
                            case '<':
                                alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                                aattack = aattack + 20;
                                nextcom = '<';
                                break;
                            case '>':
                                alienstatus = "Alien finds an arrow.\nAlien's attack is increased by 20.\n";
                                aattack = aattack + 20;
                                nextcom = '>';
                                break;
                            case 'h':
                                nextcom = com;
                                alife = alife + 20;
                                if (alife > 100)
                                {
                                    alife = 100;
                                    alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\nAlien's health in limited at 100.\n";
                                }
                                else
                                {
                                    alienstatus = "Alien finds a health bag, alien's health is increaces by 20.\n";
                                }
                                break;
                            case 'p':
                            {
                                int check;
                                nextcom = com;
                                bool podatt = false;
                                int ragr = -1;
                                int ragc = -1;
                                int ragrt, ragct;
                                int zombieinrange = 0;
                                cout << "Alien finds a pod.\n";
                                while (podatt == false)
                                {
                                    for (ragrt = ragr; ragrt <= -ragr; ragrt++)
                                    {
                                        int arragrt = gr + ragrt;
                                        if (arragrt < 0)
                                        {
                                            arragrt = 0;
                                            ragrt = 0;
                                        }
                                        for (ragct = ragc; ragct <= -ragc; ragct++)
                                        {
                                            for (z = 0; z < zombie; z++)
                                            {
                                                char go = (z + 49);
                                                int acragct = gc + ragct;
                                                char alienattacting = random[arragrt][acragct];
                                                if (acragct < 0)
                                                {
                                                    acragct = 0;
                                                    ragct = 0;
                                                    alienattacting = random[arragrt][acragct];
                                                }
                                                else if (acragct > column)
                                                {
                                                    alienattacting = ' ';
                                                }

                                                if (alienattacting == go)
                                                {
                                                    zombieinrange = zombieinrange + 1;
                                                    zombdata[z][3] = 1;
                                                }
                                            }
                                        }
                                    }
                                    if (zombieinrange > 0)
                                    {
                                        while (podatt == false)
                                        {
                                            int rannum = rand() % 5;
                                            char zombpod = (rannum + 49);
                                            if (zombdata[rannum][3] == 1)
                                            {
                                                zombdata[rannum][0] = zombdata[rannum][0] - 10;
                                                // cout << zombdata[rannum][0];
                                                cout << "Zombie " << zombpod << " receive 10 damage" << endl;
                                                if (zombdata[rannum][0] <= 0) // not yet receive damage
                                                {
                                                    cout << "Zombie " << zombpod << " is dead\n";
                                                    random[gr][gc] = ' ';
                                                    zombiedeadnum = zombiedeadnum + 1;
                                                }
                                                else
                                                {
                                                    cout << "Zombie " << zombpod << " is still alive\n";
                                                }
                                                podatt = true;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        ragc = ragc - 1;
                                        ragr = ragr - 1;
                                    }
                                }
                                break;
                            }
                            case 'r':
                                com = 's';
                                nextcom = 's';
                                ran = norock[rand() % nrock];
                                random[gr][gc] = ran;
                                alienstatus = "Alien hits a rock, the object beneath the rock is revealed.\n";
                                break;
                            case ' ':
                                nextcom = com;
                                alienstatus = "Alien finds an empty space.\n";
                                break;
                            case '.':
                                nextcom = com;
                                alienstatus = "Alien finds an empty space.\n";
                                break;
                            default:
                                com = 's';
                                alienstatus = "Alien reached the side of the game.\n";
                                break;
                            }

                            if (ar == 0 && com == '^')
                            {
                                break;
                            }
                            else if (ar == row - 1 && com == 'V')
                            {
                                break;
                            }
                            else if (ac == 0 && com == '<')
                            {
                                break;
                            }
                            else if (ac == column - 1 && com == '>')
                            {
                                break;
                            }
                            //
                            for (z = 0; z < zombie; z++)
                            {
                                char go = (z + 49);
                                if (going == go)
                                {
                                    zombdata[z][0] = zombdata[z][0] - aattack;
                                    cout << "Alien attacks Zombie " << go << "\nZombie " << go << " receives a damage of " << aattack << endl;
                                    alienstatus = "Alien hits zombie and stop.\n";
                                    if (zombdata[z][0] <= 0)
                                    {
                                        cout << "Zombie " << go << " is dead\n";
                                        random[gr][gc] = ' ';
                                        zombiedeadnum = zombiedeadnum + 1;
                                    }
                                    else
                                    {
                                        cout << "Zombie " << go << " is still alive\n";
                                    }
                                }
                            }

                            cout << alienstatus;
                            system("pause");
                            system("cls");
                            switch (com)
                            {
                            case '^':
                                random[ar][ac] = '.';
                                random[ar - 1][ac] = 'A';
                                ar = ar - 1;
                                break;
                            case 'v':
                                random[ar][ac] = '.';
                                random[ar + 1][ac] = 'A';
                                ar = ar + 1;
                                break;
                            case '<':
                                random[ar][ac] = '.';
                                random[ar][ac - 1] = 'A';
                                ac = ac - 1;
                                break;
                            case '>':
                                random[ar][ac] = '.';
                                random[ar][ac + 1] = 'A';
                                ac = ac + 1;
                                break;
                            case 's':
                                alienstatus = "";
                                turn = true;
                                movedone = true;
                                break;
                            }
                            Gameboard(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                            com = nextcom;
                        }
                    }

                    if (zombiedeadnum == zombie)
                    {
                        zombiedead = true;
                    }
                    if (zombiedead == false && playerquit == false)
                    {
                        cout << "Alien's turn ended.\n";
                        system("pause");
                        system("cls");
                        aattack = 0;
                        string alienturn;
                        int alientrail = 0;
                        for (r = 0; r < row; r++)
                        {
                            for (c = 0; c < column; c++)
                            {
                                if (random[r][c] == '.')
                                {
                                    ran = object[rand() % o];
                                    random[r][c] = ran;
                                    alienturn = "Alien's trail '.' is replaced by random objects.\n";
                                    alientrail = alientrail + 1;
                                }
                            }
                        }
                        if (alientrail > 0)
                        {
                            Gameboard(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                            cout << alienturn;
                            system("pause");
                            system("cls");
                        }
                        // zombie movement's after alien finished turn
                        for (z = 1; z <= zombie; z++)
                        {
                            char moveAlien = (48 + z);
                            for (r = 0; r < row; r++)
                            {
                                for (c = 0; c < column; c++)
                                {
                                    if (random[r][c] == moveAlien)
                                    {
                                        // determine valid moves
                                        bool validMoves[4] = {true, true, true, true};
                                        if (c == 0 || random[r][c - 1] == 'A')
                                        {
                                            validMoves[0] = false; // left is not a valid move
                                        }
                                        if (c == column - 1 || random[r][c + 1] == 'A')
                                        {
                                            validMoves[1] = false; // right is not a valid move
                                        }
                                        if (r == 0 || random[r - 1][c] == 'A')
                                        {
                                            validMoves[2] = false; // up is not a valid move
                                        }
                                        if (r == row - 1 || random[r + 1][c] == 'A')
                                        {
                                            validMoves[3] = false; // down is not a valid move
                                        }

                                        // choose a random valid move
                                        int move;
                                        do
                                        {
                                            move = rand() % 4;
                                        } while (!validMoves[move]);

                                        // move in the chosen direction
                                        switch (move)
                                        {
                                        case 0:
                                            random[r][c - 1] = moveAlien;
                                            break;
                                        case 1:
                                            random[r][c + 1] = moveAlien;
                                            break;
                                        case 2:
                                            random[r - 1][c] = moveAlien;
                                            break;
                                        case 3:
                                            random[r + 1][c] = moveAlien;
                                            break;
                                        }

                                        // clear the old position
                                        random[r][c] = ' ';

                                        // break out of the loops
                                        goto next_zombie;
                                    }
                                }
                            }
                        next_zombie:; // label for goto statement
                        }
                        bool zombiemovedone = false;
                        while (!zombiemovedone)
                        {
                            int zr, zc;
                            bool alieninrange = true;
                            for (z = 0; z < zombie; z++)
                            {
                                int range = zombdata[z][2];
                                char zombienumber = (z + 49);
                                for (int r = 0; r < row; r++)
                                {
                                    for (int c = 0; c < column; c++)
                                    {
                                        if (random[r][c] == zombienumber)
                                        {
                                            zr = r;
                                            zc = c;
                                            break;
                                        }
                                    }
                                }
                                for (int ragr = -range; ragr <= range; ragr++)
                                {
                                    for (int ragc = -range; ragc <= range; ragc++)
                                    {
                                        char zombieattacking = random[zr + ragr][zc + ragc];
                                        if (zombieattacking == 'A')
                                        {
                                            int zombatt = zombdata[z][1];
                                            alife = alife - zombatt;
                                            Gameboard(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                                            cout << "Alien is in the range of Zombie " << z + 1 << endl;
                                            cout << "Alien life reduce by " << zombdata[z][1] << endl;
                                            ragc = range + 1;
                                            ragr = range + 1;
                                            alieninrange = true;
                                            if (alife <= 0)
                                            {
                                                cout << "Alien die.\nYou lose the game!" << endl;
                                                turn = true;
                                                win = true;
                                                zombiemovedone = true;
                                                system("pause");
                                                system("cls");
                                                break;
                                            }
                                            system("cls");
                                        }
                                        else
                                        {
                                            alieninrange = false;
                                        }
                                    }
                                }
                                if (alieninrange == false)
                                {
                                    Gameboard(row, column, zombie, (char *)random, alife, aattack, (int *)zombdata);
                                    cout << "Alien is not in range of Zombie " << z + 1 << endl;
                                    system("pause");
                                }
                                system("cls");
                            }
                            zombiemovedone = true;
                        }
                    }
                    else if (zombiedead == true)
                    {
                        turn = true;
                        win = true;
                        cout << "All zombie is dead.\nYou win!" << endl;
                        system("pause");
                        system("cls");
                    }
                    else if (playerquit == true)
                    {
                        turn = true;
                        win = true;
                    }
                } while (!turn);
            } while (!win);    
        }
    }
}