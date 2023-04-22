#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        cout << (rand() % 3) + 1 << endl;
    }


    float distance;

    int x1, y1, x2, y2;

    x1 = 0;
    y1 = 0;

    x2 = 6;
    y2 = 6;

    int dx, dy;

    dx = x2 - x1;

    dy = y2 - y1;
    
    distance = sqrt((double)dx * dx + dy * dy);

    cout << "distance = " << distance / 2 << endl;

    dx = dx / 2;

    dy = dy / 2;
    distance = sqrt((double)dx * dx + dy * dy);

    cout << "distance = " << distance  << endl;


    return 0;
}