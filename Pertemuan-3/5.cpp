#include <iostream>
using namespace std;

int main()
{
    int nilai[5];
    int max;

    for(int i = 0; i < 5; i++)
    {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai[i];
    }

    max = nilai[0];

    for(int i = 1; i < 5; i++)
    {
        if(nilai[i] > max)
        {
            max = nilai[i];
        }
    }

    cout << "Nilai tertinggi adalah : " << max << endl;

    return 0;
}
