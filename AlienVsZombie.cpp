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


int main()
{
    int choice;
    bool gameOn = true;

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
            cout << "This will be directed to the information needed to start the gameboard" << endl;
            cout << "The player can choose to select the initial setting or they can set the game as they want..."<< endl;
            //startgame(rowNumber, columnNumber, zombieNumber);
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
        break;
    }
}