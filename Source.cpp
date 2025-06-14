
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void playGame(int& balance) {
    vector<int> boxes = { 0, 0, 1 }; // одна з них виграшна
    random_shuffle(boxes.begin(), boxes.end());

    int bet;
    cout << "\nВаш баланс: $" << balance << endl;
    cout << "Введіть ставку: $";
    cin >> bet;

    if (bet > balance || bet <= 0) {
        cout << "Недійсна ставка!" << endl;
        return;
    }

    int choice;
    cout << "Обери скриньку (1, 2 або 3): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Недійсний вибір!" << endl;
        return;
    }

    if (boxes[choice - 1] == 1) {
        cout << "🎉 Вітаємо! Ви виграли! +$" << bet * 2 << endl;
        balance += bet;
    }
    else {
        cout << "😢 Нажаль, виграшу немає. Ви втратили $" << bet << endl;
        balance -= bet;
    }
}

int main() {
    system("chcp 65001 > nul");
    srand(time(0));
    int balance = 100;
    char again;

    cout << "=========================" << endl;
    cout << "     Гра \"Скриньки\"     " << endl;
    cout << "=========================" << endl;

    do {
        playGame(balance);
        if (balance <= 0) {
            cout << "\nУ вас закінчилися кошти. Гра завершена!" << endl;
            break;
        }
        cout << "\nГрати ще? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\nВаш остаточний баланс: $" << balance << endl;
    cout << "Дякуємо за гру!" << endl;

    return 0;
}
