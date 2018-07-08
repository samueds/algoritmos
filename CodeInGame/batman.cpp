#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int l = 0;
    int r = W;
    int t = 0;
    int b = H;
    // game loop
     cerr <<H << "  "<< W<< endl;
    swap(X0,Y0);
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if(bombDir == "U")
        {
            b = X0;
            X0 =(X0 + t)/2.0; 
        }
        else if(bombDir == "UR")
        {
            b = X0;
            l = Y0;
            X0 = (X0 + t)/2.0; 
            Y0 =(Y0 + r)/2.0;
        }
        else if(bombDir == "R")
        {
            l = Y0;
            Y0 = (Y0 + r)/2.0;
        }
        else if(bombDir == "DR")
        {
           t = X0;
           l = Y0;
           X0 =(X0 + b)/2.0;  
           Y0 = (Y0 + r)/2.0;
        }
        else if(bombDir == "D")
        {
            t = X0;
            X0 =(X0 + b)/2.0;  
        }
        else if(bombDir == "DL")
        {
            t = X0;
            r = Y0;
            X0 =(X0 + b)/2.0;   
            Y0 =(Y0 + l)/2.0;
        }
        else if(bombDir == "L")
        {
            r = Y0;
            Y0 = (Y0 + l)/2.0;
        }
        else if(bombDir == "UL")
        {
            b = X0;
            r = Y0;
            X0 =(X0 + t)/2.0;  
            Y0 = (Y0 + l)/2.0;
        }
        cerr << bombDir << endl;
       cerr << Y0<< " " << X0 << endl;
        // the location of the next window Batman should jump to.
        cout << Y0 << " " << X0 << endl;
    }
}