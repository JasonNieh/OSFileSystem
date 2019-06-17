//
//  main.cpp
//  FileSimu
//
//  Created by Jason Nie on 6/17/19.
//  Copyright © 2019 Jason Nie. All rights reserved.
//

#include<iostream>
#include<string>
#include <windows.h>
#include"FileSimu.h"

using namespace std;

void help() {
    cout << " --------------------------------------------------------------------------------------" << endl;
    cout << "| 1.create  + <string>                    Create a file with the name of <string>    " << endl;
    cout << "| 2.destory + <string>                    Delete the file named <string>        " << endl;
    cout << "| 3.rename  + <string> + <string>         Rename the file with a new name   " << endl;
    cout << "| 4.open    + <string>                    Open the file named <string>         " << endl;
    cout << "| 5.close   + <string>                    Close the file named <string>         " << endl;
    cout << "| 6.write   + <index>                     Write a file with the index of <index>    " << endl;
    cout << "| 7.read    + <index>                     Read a file with the index of <index>       " << endl;
    cout << "| 8.lseek   + <index>  + <pos>            Locate file pointer, with the index of<index>   " << endl;
    cout << "| 9.ls                                    See all files in a list                     " << endl;
    cout << "| 10.exit                                 Exit                            " << endl;
    cout << " --------------------------------------------------------------------------------------" << endl
    << endl;
}

int Operate() {
    while (1) {
        help();
        while (1) {
            cout << endl;
            string choice;
            char name1[20],name2[20];
            int index, memarea, count;
            show_path();
            cin >> choice;
            if (choice == "create")
            {
                cin >> name1;
                create(name1);
            }
            else if (choice == "destory")
            {
                cin >> name1;
                destroy(name1);
            }
            else if (choice == "open")
            {
                cin >> name1;
                open(name1);
            }
            else if (choice == "close")
            {
                cin >> index;
                close(index);
            }
            else if (choice == "rename")
            {
                cin >> name1 >> name2;
                rename(name1,name2);
            }
            else if (choice == "write")
            {
                cin >> index;
                cin >> memarea;
                cin >> choice;
                count = choice.size();
                write(index, choice, count);
                
            }
            else if (choice == "read")
            {
                cin >> index;
                cin >> memarea;
                cin >> count;
                read(index, choice, count);
            }
            else if (choice == "lseek")
            {
                cin >> index;
                cin >> memarea;
                lseek(index,memarea);
            }
            else if (choice == "ls")
            {
                dir();
            }
            else if (choice == "clear") {
                system("CLS");
                help();
            } else if (choice == "exit") {
                system("CLS");
                return 0;
            }
        }
    }
    
}

int main() {
    int choice = 0;
    system("CLS");
    //cout << "\t\t*****************************************\t" << endl;
    cout << "\t\t\t\t\t----------------------------------------------------\t" << endl;
    cout << "\t\t\t\t\t                File Simulation            \t" << endl;
    Operate();
    return 0;
}
