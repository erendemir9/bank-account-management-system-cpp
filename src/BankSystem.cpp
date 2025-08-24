#include <iostream>
#include <vector>
using namespace std;

class Account {
    // Base Class
protected:
    int accountNumber;
    string holderName;
    float balance;

public:
    Account(int acNum, string holNam) : accountNumber(acNum), holderName(holNam), balance(0) {
    }

    Account(int acNum, string holNam, float bal) : accountNumber(acNum), holderName(holNam), balance(bal) {
    }

    virtual ~Account() {
    }

    virtual void deposit(float amount) =0;

    virtual void withdraw(float amount) =0;

    virtual void displayDetails() =0;

    virtual void applyInterest() {
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

    float getBalance() const {
        return balance;
    }
};


class SavingsAccount : public Account {
    // Derived Class

protected:
    float interestRate = 0.05;

public:
    SavingsAccount() : Account(0, " ", 0) {
    }

    SavingsAccount(int acNum, string holNam, float bal) : Account(acNum, holNam, bal) {
    }

    SavingsAccount(int acNum, string holNam) : Account(acNum, holNam) {
    }

    void deposit(float amount) override {
        try {
            if (amount > 0) {
                cout << "You have successfully deposited -->> '" << amount <<
                        "'\n----------------------------------------------" << endl;
                balance += amount;
            } else {
                throw amount;
            }
        } catch (float amount) {
            cout << "You can not deposit of amount less than or equal to zero!!! You tried to deposit -->> '" << amount
                    << "'" << endl;
            cout << "Please enter a valid amount to deposit (Greater than 0 !!!).. \n****************************" <<
                    endl;
        }
    }

    void withdraw(float amount) override {
        try {
            if (amount > 0 && amount <= balance) {
                cout << "You have successfully withdrawn -->> '" << amount <<
                        "'\n----------------------------------------------" << endl;
                balance -= amount;
            } else {
                throw amount;
            }
        } catch (float amount) {
            cout << "You cannot withdraw this amount! -->> " << amount << "\n";
            cout << "You tried to withdraw more than your balance or a negative amount.\n";
            cout <<
                    "Please enter a valid amount to withdraw (Greater than 0 AND Less than or Equal to your balance).\n****************************"
                    << endl;
        }
    }

    void displayDetails() override {
        cout << ">>>>>>>>> Savings Account Details <<<<<<<<<\n----------------------------------------------" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: %" << (interestRate * 100) << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
    }

    void applyInterest() override {
        balance += (balance * interestRate);
    }
};


#pragma region FunctionsPrototypes
void openingMenu(vector<Account *> &accounts);

bool checkIfAccountExists(const vector<Account *> &accounts, int accountNumber);

void mainMenu(vector<Account *> &accounts);

void createNewAccount(vector<Account *> &accounts);

void deposit(vector<Account *> &account);

void withdraw(vector<Account *> &accounts);

void displayById(const vector<Account *> &accounts);

void applyInterest(vector<Account *> &accounts);

bool checkIfAccountsEmpty(const vector<Account *> &accounts);
#pragma endregion

int main() {
    vector<Account *> accounts;

    openingMenu(accounts);

    for (Account *acc: accounts) {
        delete acc;
    }
    accounts.clear();
    return 0;
}

void openingMenu(vector<Account *> &accounts) {
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "Welcome to the Bank Account Management System" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    while (true) {
        cout << " <<<<<<<<>>>>>>>> " << endl;
        cout << "'1' -> Main Menu" << endl;
        cout << "'2' -> Exit" << endl;
        cout << " <<<<<<<<>>>>>>>> " << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            mainMenu(accounts);
        } else if (choice == 2) {
            exit(0);
        } else {
            cout << "-------------------------\nInvalid choice!!!! Please try again.\n-------------------------\n" <<
                    endl;
        }
    }
}

void mainMenu(vector<Account *> &accounts) {
    bool lopMnu = true;
    cout << "Please select an option: " << endl;
    do {
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "'1' -> Create New Account" << endl;
        cout << "'2' -> Deposit" << endl;
        cout << "'3' -> Withdraw" << endl;
        cout << "'4' -> Display Details By Account Number" << endl;
        cout << "'5' -> Display All Accounts Details" << endl;
        cout << "'6' -> Apply interest (for savings)" << endl;
        cout << "'0' -> Opening Menu" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                createNewAccount(accounts);
                break;
            case 2:
                if (!checkIfAccountsEmpty(accounts)) {
                    deposit(accounts);
                }
                break;
            case 3:
                if (!checkIfAccountsEmpty(accounts)) {
                    withdraw(accounts);
                }
                break;
            case 4:
                if (!checkIfAccountsEmpty(accounts)) {
                    displayById(accounts);
                }
                break;
            case 5:
                if (!checkIfAccountsEmpty(accounts)) {
                    for (Account *acc: accounts) {
                        acc->displayDetails();
                    }
                }
                break;
            case 6:
                if (!checkIfAccountsEmpty(accounts)) {
                    applyInterest(accounts);
                }
                break;
            case 0:
                return;
            default:
                cout << "-------------------------\nInvalid choice!!!! Please try again.\n-------------------------\n"
                        << endl;
                break;
        }
    } while (lopMnu);
}

void createNewAccount(vector<Account *> &accounts) {
    Account *acc;

    int accountNumber;
    string holderName;
    float balance;
    cout << "Please enter the account number: ";
    cin >> accountNumber;

    if (checkIfAccountExists(accounts, accountNumber)) {
        cout << "-----------------------------------------------" << endl;
        cout << "Account already exists!!!" << endl;
        cout << "-----------------------------------------------" << endl;
        return;
    }


    cout << "Please enter the holder name: ";
    cin.ignore();
    getline(cin, holderName);
    cout << "Do you want to enter a balance? (Yes or No)" << endl;
    string st;
    cin >> st;

    bool lp = true;
    do {
        if (st == "Yes" || st == "yes" || st == "YES") {
            cout << "Please enter the balance: ";
            cin >> balance;
            acc = new SavingsAccount(accountNumber, holderName, balance);
            lp = false;
        } else if (st == "No" || st == "no" || st == "NO") {
            acc = new SavingsAccount(accountNumber, holderName);
            lp = false;
        } else {
            cout << "-------------------------\nInvalid choice!!!! Please try again.\n-------------------------\n" <<
                    endl;
            cin >> st;
        }
    } while (lp);

    accounts.push_back(acc);
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << "Account created successfully!!!" << endl;
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
}

bool checkIfAccountExists(const vector<Account *> &accounts, int accountNumber) {
    for (Account *acc: accounts) {
        if (acc->getAccountNumber() == accountNumber) {
            return true;
        }
    }
    return false;
}

void deposit(vector<Account *> &accounts) {
    int accountNumber;
    float amount;
    cout << "Please enter the account number you want to deposit:" << endl;
    cin >> accountNumber;
    if (checkIfAccountExists(accounts, accountNumber)) {
        cout << "Please enter the amount you want to deposit:" << endl;
        cin >> amount;
        for (Account *acc: accounts) {
            if (acc->getAccountNumber() == accountNumber) {
                acc->deposit(amount);
            }
        }
    } else {
        cout << "-----------------------------------------------" << endl;
        cout << "No account to deposit !!!" << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void withdraw(vector<Account *> &accounts) {
    int accountNumber;
    float amount;
    cout << "Please enter the account number you want to withdraw:" << endl;
    cin >> accountNumber;
    if (checkIfAccountExists(accounts, accountNumber)) {
        cout << "Please enter the amount you want to withdraw:" << endl;
        cin >> amount;
        for (Account *acc: accounts) {
            if (acc->getAccountNumber() == accountNumber) {
                acc->withdraw(amount);
            }
        }
    } else {
        cout << "-----------------------------------------------" << endl;
        cout << "No account to withdraw !!!" << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void displayById(const vector<Account *> &accounts) {
    int accountNumber;
    cout << "Please enter the account number you want to display: ";
    cin >> accountNumber;
    bool found = false;
    for (Account *acc: accounts) {
        if (acc->getAccountNumber() == accountNumber) {
            acc->displayDetails();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "-----------------------------------------------" << endl;
        cout << "No account to display with this account number !!!!!!! \n";
        cout << "-----------------------------------------------" << endl;
    }
}

void applyInterest(vector<Account *> &accounts) {
    for (Account *acc: accounts) {
        acc->applyInterest();
    }
    cout << "-----------------------------------------------" << endl;
    cout << "Interest applied successfully for all accounts !!!" << endl;
    cout << "-----------------------------------------------" << endl;
}

bool checkIfAccountsEmpty(const vector<Account *> &accounts) {
    if (accounts.empty()) {
        cout << "-----------------------------------------------" << endl;
        cout << "No accounts to display !!!!!!! \n";
        cout << "-----------------------------------------------\n" << endl;
        return true;
    }
    return false;
}
