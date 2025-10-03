#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));

    int balance = 100;
    string pl;
    string num[3] = { "red", "green", "black" };

    cout << "Colors in ruletka: ";
    for (int i = 0; i < 3; i++)
        cout << num[i] << " ";
    cout << "\nBalance: " << balance << "$\nPrice for 1 game: 10$\n";

    do
    {
        if (balance < 10) {
            cout << "Not enough money to play!\n";
            break;
        }

        cout << "\nBalance: " << balance << "$" << endl;
        cout << "Enter your color (type 'stop' to exit): ";
        cin >> pl;

        if (pl == "stop") break;

        balance -= 10; 

        int r = rand() % 3; 
        cout << "Roulette: " << num[r] << endl;

        if (pl == num[r]) {
            cout << "You win x2!\n";
            balance += 20;
        }
        else {
            cout << "You Lose!!\n";
        }

        cout << "Balance: " << balance << "$\n";

    } while (true);

    cout << "\nGame Over. Final balance: " << balance << "$\n";
    return 0;
    
}
