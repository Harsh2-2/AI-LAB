#include <iostream>
#include <algorithm>
using namespace std;

void solve(int x, int y, int z)
{

    int a = 0, b = 0;

    int step = 1;

    while (a != z && b != z)
    {

        if (a == 0)
        {
            a = x;

            cout << "Step " << step++ << " Fill A :" << a << " litres in A " << b << "litres in B \n";
        }

        else if (b == y)
        {
            b = 0;
            cout << "Step " << step++ << " Empty B " << a << " litres in A " << b << " litres in B \n";
        }

        else
        {

            int pour = min(a, y - b);

            a = a - pour;
            b = b + pour;

            cout << "Step " << step++ << " Pour A->B " << a << " litres in A " << b << " litres in B \n";
        }
    }
}

int main()
{

    int x, y, z;

    cout << "Enter capacity of Jug A: ";
    cin >> x;

    cout << "Enter capacity of Jug B: ";
    cin >> y;

    cout << "Enter target amount: ";
    cin >> z;

    if (z > max(x, y) || z % __gcd(x, y) != 0)
    {

        cout << "Not possible\n";

        return 0;
    }

    solve(x, y, z);
    return 0;
} 
