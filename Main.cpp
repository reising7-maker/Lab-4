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




//Allows the use of cout and cin
#include <iostream>
//Allows the reading of other files
#include <fstream>

using namespace std;

int main()
{
    

    ifstream infile;
    infile.open("C:/Users/reising7/Downloads/Computer Science/Lab 4/Temp.dat");
    
    cout << "Must be in the range of -30 to 120 degrees" << endl;
    cout << "Each * represents 3 degrees (rounds up)" << endl;

    //Heading of graph
    cout << "                Hourly Temparature" << endl;
    cout << "Temparature: -30  -15   0    15  30   45   60   75   90   105  120" << endl;
    cout << "--------------|----|----|----|----|----|----|----|----|----|----|---" << endl;
    int temparature;
    int stars;
    int spaces;

    stars = 0;
    //Spaces are 20 to give enough room for all the number indicators
    spaces = 20;

    //Reads out the temparatures in the file
    while (infile >> temparature)
    {

        if (0 < temparature && temparature <= 120)
            //Gived the needed stars for temparatures between 0 and 120
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
        else if (temparature == 0)
        {
            cout << temparature;
            //Gives space to aline with 0
            cout << "                       |" << endl;



        }
        else if (temparature < 0 && temparature >= -30)
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
        else 
        {
            //Doesn't show the temparature
        }

        

    }


    return 0;
}