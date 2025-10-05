#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));

    int balance = 1000;
    string pl;
    int price;
    string winColor;

    cout << "--------------------------------------\n";
    cout << "Welcome to the Casino Roulette!\n";
    cout << "Colors: red, green, black\n";
    cout << "Your starting balance: " << balance << "$\n";

    while (true)
    {
        cout << "\n--------------------------------------\n";
        cout << "Enter price for 1 roll (0 to stop): ";
        cin >> price;

        if (price == 0 || balance <= 0)
            break;

        if (price > balance)
        {
            cout << "Not enough balance!\n";
            continue;
        }

        cout << "Choose color (red / green / black): ";
        cin >> pl;

        int r = rand() % 37;

        if (r == 0)
            winColor = "green";
        else if (r % 2 == 0)
            winColor = "red";
        else
            winColor = "black";

        cout << "Roulette rolled: " << winColor << "\n";

        if (pl == winColor)
        {
            if (winColor == "green")
            {
                cout << "You WIN! +" << price * 16 << "$\n";
                balance += price * 16;
            }
            else
            {
                cout << "You WIN! +" << price * 2 << "$\n";
                balance += price * 2;
            }
        }
        else
        {
            cout << "You lose! -" << price << "$\n";
            balance -= price;
        }

        cout << "Current balance: " << balance << "$\n";
    }

    cout << "\n--------------------------------------\n";
    cout << "Game Over. Final balance: " << balance << "$\n";
    return 0;
}
