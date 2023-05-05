#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Create a class to represent a single bill
class Bill {
public:
    Bill(string n, double a, string d) : name(n), amount(a), date(d) {}
    string getName() { return name; }
    double getAmount() { return amount; }
    string getDate() { return date; }
    void displayBill() {
        cout << "Name: " << name << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << date << endl;
    }
private:
    string name;
    double amount;
    string date;
};

// Add a new bill to the collection
void addBill(vector<Bill>& bills) {
    string name, date;
    double amount;

    // Prompt user for bill information
    cout << "Enter bill name: ";
    getline(cin, name);
    cout << "Enter bill amount: ";
    cin >> amount;
    cin.ignore();
    cout << "Enter bill date (MM/DD/YYYY): ";
    getline(cin, date);

    // Create new Bill object and add to collection
    Bill newBill(name, amount, date);
    bills.push_back(newBill);
}

// Save the collection of bills to a file
void saveBills(vector<Bill>& bills) {
    ofstream outFile("bills.txt");

    // Loop over bills in collection and write to file
    for (Bill& bill : bills) {
        outFile << bill.getName() << "," << bill.getAmount() << "," << bill.getDate() << endl;
    }

    outFile.close();
    cout << "Bills saved to file." << endl;
}

// Load a collection of bills from a file
void loadBills(vector<Bill>& bills) {
    ifstream inFile("bills.txt");

    // Loop over lines in file and create new Bill objects
    string line;
    while (getline(inFile, line)) {
        string name, date;
        double amount;
        size_t pos = 0;
        string token;

        // Split line into fields
        pos = line.find(",");
        name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(",");
        amount = stod(line.substr(0, pos));
        line.erase(0, pos + 1);
        date = line;

        // Create new Bill object and add to collection
        Bill newBill(name, amount, date);
        bills.push_back(newBill);
    }

    inFile.close();
    cout << "Bills loaded from file." << endl;
}

int main() {
    vector<Bill> bills;

    // Prompt user for action
    cout << "What would you like to do?" << endl;
    cout << "1. Add a new bill" << endl;
    cout << "2. Save bills to file" << endl;
    cout << "3. Load bills from file" << endl;
    int choice;
    cin >> choice;
    cin.ignore();

    // Perform selected action
    if (choice == 1) {
        addBill(bills);
    }
    else if (choice == 2) {
        saveBills(bills);
    }
    else if (choice == 3) {
        loadBills(bills);
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
