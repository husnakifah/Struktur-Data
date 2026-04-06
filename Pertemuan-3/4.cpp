#include <iostream>
using namespace std;

int main()
{
    int nilai[5];
    int total = 0;
    float rata;

    for(int i = 0; i < 5; i++)
    {
        cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
        cin >> nilai[i];
        total += nilai[i];
    }

    rata = total / 5.0;

    cout << "\nTotal nilai : " << total << endl;
    cout << "Rata-rata : " << rata << endl;

    return 0;
}
