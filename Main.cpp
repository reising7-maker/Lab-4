/*
Levi Reising
Computer Science


Description:
Displays temperatures from -30 to 120 as a horizontal bar chart. Each * represents 3 degrees.
Negative temperatures extend left from zero, and positive temperatures extend right.


Pre conditions: The input file will have different integers to represent temparatures.


Post conditions: The program should contain a bar chart with temparatures on the top for a referance.
There should be temparature values on the left side of the graph with stars that represent 1-3 degrees.
There will be a 0 marker in the middle of the graph.
Negative temparatures will be on the left side of that 0 marker and positive on the right.
The values for all temparatures should be between -30 to 120 degrees, all other temparatures will be discarted.
*/

//Shows what the graph does and the top section of the graph
void graph();

//The stars that are displayed when the temparature is positive
void positiveN(int temparature);

//The stars that are displayed when the temparature is 0 (so none)
void zeroN(int temparature);

//The stars that are displayed when the temparature is negaive
void negativeN(int temparature, int stars, int spaces);


//Allows the use of cout and cin
#include <iostream>
//Allows the reading of other files
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("C:/Users/reising7/Downloads/Computer Science/Lab 4/Temp.dat");

    graph();

    int temparature;
    int stars = 0;
    int spaces = 20;

    //Reads out the temparatures in the file
    while (infile >> temparature)
    {
        if (0 < temparature && temparature <= 120)
            //Gived the needed stars for temparatures between 0 and 120
        {
            positiveN(temparature);
        }
        else if (temparature == 0)
        {
            zeroN(temparature);
        }
        else if (temparature < 0 && temparature >= -30)
        {
            negativeN(temparature, stars, spaces);
        }

    }

    return 0;
}

void graph()//---------------------------------------------------------------------------------------------------------------------------
{
    cout << "Must be in the range of -30 to 120 degrees" << endl;
    cout << "Each * represents 3 degrees (rounds up)" << endl;

    //Heading of graph
    cout << "                Hourly Temparature" << endl;
    cout << "Temparature: -30  -15   0    15  30   45   60   75   90   105  120" << endl;
    cout << "--------------|----|----|----|----|----|----|----|----|----|----|---" << endl;
}

void positiveN(int temparature)
{
    //Has to be here so it doesn't display numbers out of range. Extra spaces make it look better
    cout << temparature;
    cout << "                     ";

    //Alines the 0 marker for different digits:
    if (temparature < 10)
    {
        cout << "  |";
    }
    else if (temparature < 100)
    {
        cout << " |";
    }
    else
    {
        cout << "|";
    }

    //Displays how many stars should be added to temp (rounds up)
    while (temparature >= 1)
    {
        cout << "*";

        temparature = temparature - 3;
        //subtracting 3 each time rather than deviding by 3 then subtracting one so it will round up instead of down
    }
    cout << "" << endl;
}

void zeroN(int temparature)//--------------------------------------------------------------------------------------------------------------------
{
    cout << temparature;
    //Gives space to aline with 0
    cout << "                       |" << endl;
}

void negativeN(int temparature, int stars, int spaces)//-----------------------------------------------------------------------------------------
{
    cout << temparature;
    cout << "        ";

    //Gives one extra space for single digits to aline with double digits
    if (temparature > -10)
    {
        cout << " ";
    }

    while (temparature <= -1)
    {
        temparature = temparature + 3;
        //makes an indicator for how many stars will be needed so spaces can go before it
        stars = stars + 1;
    }

    //Allows negaive numbers to aline with 0 marker using spaces
    spaces = 13 - stars;
    while (spaces > 0)
    {
        cout << " ";
        spaces = spaces - 1;
    }

    //Puts stars after spaces
    while (stars > 0)
    {
        cout << "*";
        stars = stars - 1;
    }
    cout << "|" << endl;
}