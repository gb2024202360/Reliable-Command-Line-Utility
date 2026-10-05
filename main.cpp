#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Expense {
    string category;
    double amount;
};

vector<Expense> expenses;

// Add a new expense
void addExpense() {
    Expense e;

    cout << "\nEnter category: ";
    cin >> e.category;

    cout << "Enter amount: ";

    while (!(cin >> e.amount) || e.amount <= 0) {
        cout << "Invalid amount! Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    expenses.push_back(e);

    cout << "Expense added successfully!\n";
}

// Display all expenses
void listExpenses() {
    if (expenses.empty()) {
        cout << "\nNo expenses recorded.\n";
        return;
    }

    cout << "\n--- All Expenses ---\n";

    for (int i = 0; i < expenses.size(); i++) {
        cout << i + 1 << ". "
             << expenses[i].category
             << " - Rs. "
             << fixed << setprecision(2)
             << expenses[i].amount << endl;
    }
}

// Show total for a category
void categoryTotal() {
    string category;
    double total = 0;

    cout << "\nEnter category: ";
    cin >> category;

    for (const auto &e : expenses) {
        if (e.category == category) {
            total += e.amount;
        }
    }

    cout << "Total for " << category
         << ": Rs. " << fixed << setprecision(2)
         << total << endl;
}

// Show overall total
void overallTotal() {
    double total = 0;

    for (const auto &e : expenses) {
        total += e.amount;
    }

    cout << "\nOverall Expense: Rs. "
         << fixed << setprecision(2)
         << total << endl;
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n==============================\n";
        cout << "   EXPENSE TRACKER\n";
        cout << "==============================\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                listExpenses();
                break;

            case 3:
                categoryTotal();
                break;

            case 4:
                overallTotal();
                break;

            case 5:
                cout << "\nThank you for using Expense Tracker!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select 1 to 5.\n";
        }
    }

    return 0;
}
