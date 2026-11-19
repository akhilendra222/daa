
#include <iostream>
using namespace std;

#define INF 99999

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int a[10][10];

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Floyd Warshall Algorithm
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][k] != INF && a[k][j] != INF)
                {
                    if(a[i][k] + a[k][j] < a[i][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
