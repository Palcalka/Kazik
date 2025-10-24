#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void showMenu();
void playGame();

int main()
{
    showMenu(); 
    return 0;
}

void showMenu()
{
     int choice;

    while (true) {
        cout << "\n=========================\n";
        cout << "       CASINO MENU       \n";
        cout << "=========================\n";
        cout << "1. Start game\n";
        cout << "2. Rules\n";
        cout << "3. Exit\n";
        cout << "=========================\n";

        if (!(cin >> choice)) {  // проверяем, ввели ли число
            cout << "Invalid input! Please enter a number.\n";
            cin.clear(); // сбрасываем состояние ошибки
            cin.ignore(10000, '\n');
            continue; // возвращаемся к началу цикла
        }

        if (choice == 1)
            playGame(); 
        else if (choice == 2)
            cout << "\nRule: Bet on red, green, or black and win if color matches!\n";
        else if (choice == 3)
        {
            cout << "Goodbye!\n";
            break;
        }
        else
            cout << "Invalid choice!\n";
    }
}
void playGame()
{
    srand(time(NULL));

    int balance = 1000;
    string pl, menu;
    int price;
    string winColor;

    cout << "--------------------------------------\n";
    cout << "Welcome to the Casino Roulette!\n";
    cout << "Colors: red, green, black\n";
    cout << "Your starting balance: " << balance << "$\n";
    cout << "Enter menu if you want to go menu"<< "\n";

    while (true)
    {
        cout << "\n--------------------------------------\n";
        cout << "Enter price for 1 roll (0 to menu ): "<< "\n";
        cout << "Your  balance: " << balance << "$\n";

        while (!(cin >> price) || price < 0) {
        cin.clear();              // сбрасывает ошибку потока
        cin.ignore(10000, '\n');  // пропускает "мусор" во вводе
        cout << "Invalid input! Enter a valid number: ";
    }

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
                balance -= price;
            }
            else
            {
                cout << "You WIN! +" << price * 2 << "$\n";
                balance += price * 2;
                balance -= price;
            }
        }
        else
        {
            cout << "You lose! -" << price << "$\n";
            balance -= price;
        }

      
    }

    cout << "\n--------------------------------------\n";
    cout << "Game Over. Final balance: " << balance << "$\n";
}

