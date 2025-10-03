#include "include/right_triangle.h"

using namespace std;

int main()
{
    int triangleCount = 0;
    for (int a = 1; a < 201; a++)
    {
        for (int b = 1; b < 201; b++)
        {
            for (int c = 1; c < 201; c++)
            {
                try
                {
                    // Create a valid right triangle
                    RightTriangle t1(a, b, c);
                    t1.printSides();
                    triangleCount++;
                }
                catch (const std::invalid_argument &e)
                {
                    continue;
                }
            }
        }
    }

    cout << "\n\nTotal right triangles found: " << triangleCount << endl;

    return 0;
}