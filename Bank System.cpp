#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Account {
public:
    string username;
    string password;
    double balance;
    double loanAmount;

    Account(string user, string pass) : username(user), password(pass), balance(0.0), loanAmount(0.0) {}
};

class BankSystem {
private:
    unordered_map<string, Account*> accounts;
    double interestRate;

public:
    BankSystem() : interestRate(0.05) {}  // Default interest rate: 5%

    void createAccount() {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (accounts.find(username) == accounts.end()) {
            accounts[username] = new Account(username, password);
            cout << "Account created successfully.\n";
        } else {
            cout << "Username already exists.\n";
        }
    }

    Account* login() {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (accounts.find(username) != accounts.end() && accounts[username]->password == password) {
            cout << "Login successful.\n";
            return accounts[username];
        } else {
            cout << "Invalid username or password.\n";
            return nullptr;
        }
    }

    void deposit(Account* account, double amount) {
        account->balance += amount;
        cout << "Deposit successful. Current balance: " << account->balance << "\n";
    }

    void withdraw(Account* account, double amount) {
        if (account->balance >= amount) {
            account->balance -= amount;
            cout << "Withdrawal successful. Current balance: " << account->balance << "\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    void applyLoan(Account* account, double amount, int years) {
        account->loanAmount += amount;
        double totalPayment = amount * pow(1 + interestRate, years);
        cout << "Loan applied successfully. Total amount to be paid: " << totalPayment << "\n";
    }

    void setInterestRate(double rate) {
        interestRate = rate;
        cout << "Interest rate updated: " << interestRate * 100 << "%\n";
    }
};

void adminMenu(BankSystem& bank) {
    int choice;
    do {
        cout << "1. Update Interest Rate\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double newRate;
                cout << "Enter new interest rate (e.g., 0.05 for 5%): ";
                cin >> newRate;
                bank.setInterestRate(newRate);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

void userMenu(BankSystem& bank, Account* account) {
    int choice;
    do {
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Apply for Loan\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(account, amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(account, amount);
                break;
            }
            case 3: {
                double amount;
                int years;
                cout << "Enter loan amount: ";
                cin >> amount;
                cout << "Enter loan term in years: ";
                cin >> years;
                bank.applyLoan(account, amount, years);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    BankSystem bank;
    int choice;

    do {
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2: {
                Account* account = bank.login();
                if (account) {
                    userMenu(bank, account);
                }
                break;
            }
            case 3:
                adminMenu(bank);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
