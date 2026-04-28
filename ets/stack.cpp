#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

void prosesPostfix(string postfix) {
    stack<string> s;
    cout << "Langkah\t| Simbol\t| Isi Stack (Bawah -> Atas)" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (c == ' ') continue;

        string simbol(1, c);
        if (isalnum(c)) {
            s.push(simbol);
        } else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string gabung = "(" + op1 + c + op2 + ")";
            s.push(gabung);
        }

        cout << i + 1 << "\t| " << c << "\t\t| ";
        stack<string> temp = s;
        stack<string> urutan;
        while (!temp.empty()) { urutan.push(temp.top()); temp.pop(); }
        while (!urutan.empty()) { cout << "[" << urutan.top() << "] "; urutan.pop(); }
        cout << endl;
    }
}

int main() {
    string postfix = "a2b3^ * fg-/+dh*+";
    prosesPostfix(postfix);
    return 0;
}

