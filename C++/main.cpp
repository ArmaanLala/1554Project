#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{

    int sum{0};
    int length{0};
    int *rowSums = new int[9];

    //Initializes A to be a (9x9) Matrix
    Matrix A(9, 9);
    A.at(0, 4) = 1;
    A.at(0, 5) = 1;
    A.at(1, 5) = 1;
    A.at(1, 7) = 1;
    A.at(2, 6) = 1;
    A.at(2, 8) = 1;
    A.at(3, 4) = 1;
    A.at(3, 7) = 1;
    A.at(4, 8) = 1;
    A.at(5, 6) = 1;

    A.at(5, 0) = 1;
    A.at(4, 0) = 1;
    A.at(5, 1) = 1;
    A.at(7, 1) = 1;
    A.at(6, 2) = 1;
    A.at(8, 2) = 1;
    A.at(4, 3) = 1;
    A.at(7, 3) = 1;
    A.at(8, 4) = 1;
    A.at(6, 5) = 1;

    //Prints out the fancy sign
    cout << "  __  __       _   _       __ _____ _____ _  _      _____                                       _____           _           _    " << endl;
    cout << " |  \\/  |     | | | |     /_ | ____| ____| || |    / ____|                                     |  __ \\         (_)         | |   " << endl;
    cout << " | \\  / | __ _| |_| |__    | | |__ | |__ | || |_  | (___  _   _ _ __ ___  _ __ ___   ___ _ __  | |__) | __ ___  _  ___  ___| |_  " << endl;
    cout << " | |\\/| |/ _` | __| '_ \\   | |___ \\|___ \\|__   _|  \\___ \\| | | | '_ ` _ \\| '_ ` _ \\ / _ \\ '__| |  ___/ '__/ _ \\| |/ _ \\/ __| __| " << endl;
    cout << " | |  | | (_| | |_| | | |  | |___) |___) |  | |    ____) | |_| | | | | | | | | | | |  __/ |    | |   | | | (_) | |  __/ (__| |_  " << endl;
    cout << " |_|  |_|\\__,_|\\__|_| |_|  |_|____/|____/   |_|   |_____/ \\__,_|_| |_| |_|_| |_| |_|\\___|_|    |_|   |_|  \\___/| |\\___|\\___|\\__| " << endl;
    cout << "                                                                                                              _/ |               " << endl;
    cout << "                                                                                                             |__/                " << endl;

    //Prints A out to standard output
    cout << A << endl
         << endl;
    ;

    cout << "What is the length of the phone number you are trying to find?: ";

    //Reads in the input for how long of a length they want
    cin >> length;

    cout << endl;

    while (length > 20 || length < 1)
    {
        cout << "Please input a number between 2 and 20" << endl;
        cin >> length;

        cout << endl;
    }

    Matrix B{A};

    // Raises A to the power of the length
    for (int i = 2; i < length; i++)
    {
        B = B * A;
    }

    // Sums up all values and the value of each row.
    for (int i = 0; i < B.numRows(); i++)
    {
        for (int j = 0; j < B.numCols(); j++)
        {
            sum += B.at(i, j);
            *(rowSums + i) += B.at(i, j);
        }
    }

    cout << "The Resulting adjacency matrix for a length of " << length << " is: " << endl
         << B << endl
         << endl
         << "and the total number of possibilites is " << sum << endl;

    // Prints out the sums of each row
    cout << "There are " << *(rowSums + 0) << " possibilites that start with " << 0 << endl;
    cout << "There are " << *(rowSums + 1) << " possibilites that start with " << 1 << endl;
    cout << "There are " << *(rowSums + 2) << " possibilites that start with " << 2 << endl;
    cout << "There are " << *(rowSums + 3) << " possibilites that start with " << 3 << endl;
    cout << "There are " << *(rowSums + 4) << " possibilites that start with " << 4 << endl;
    cout << "There are " << *(rowSums + 5) << " possibilites that start with " << 6 << endl;
    cout << "There are " << *(rowSums + 6) << " possibilites that start with " << 7 << endl;
    cout << "There are " << *(rowSums + 7) << " possibilites that start with " << 8 << endl;
    cout << "There are " << *(rowSums + 8) << " possibilites that start with " << 9 << endl;
}
