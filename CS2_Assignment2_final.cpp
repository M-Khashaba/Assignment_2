#include <iostream>
#include "arbitrary.h"

using namespace std;

int main()
{
    // initialize sizes of sets
    int s1 = 200, s2 = 200;
    
    // create two arrays of points
    point* S1 = new point[s1];
    point* S2 = new point[s2];

    // fill S1 with random points between (69,69) and (89,89)
    for (int i = 0; i < s1; i++)
    {
        float x = 69 + (rand() % 21);
        float y = 69 + (rand() % 21);
        S1[i].setcoord_x(x);
        S1[i].setcoord_y(y);
    }

    // fill S2 with random points between (19,19) and (39,39)
    for (int i = 0; i < s2; i++)
    {
        float x = 19 + (rand() % 21);
        float y = 19 + (rand() % 21);
        S2[i].setcoord_x(x);
        S2[i].setcoord_y(y);
    }

    // calculate centers of S1 and S2
    point centerA = Center(S1, s1);
    point centerB = Center(S2, s2);

    // find closest point in S1 and S2 to 20 randomly generated points
    for (int i = 0; i < 20; i++)
    {
        float x = 4 + (rand() % 96);
        float y = 4 + (rand() % 96);
        point l(x, y);
        cout << "Point " << i + 1;
        closest_to(S1, s1, S2, s2, l);
        cout << endl;
    }

    // free memory allocated for S1 and S2
    delete[] S1;
    delete[] S2;

    return 0;
}
