#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

// کلاس مشتری
class Customer {
public:
    string name;
    string lastName;
    string phoneNumber;
    int stayDuration;
    string companionName;
    string checkInDate;
    bool hasCar;

    // محاسبه هزینه کل بر اساس مدت اقامت و موارد دیگر
    int calculateTotalCost() {
        int totalCost = stayDuration * 75000; // هزینه برای مدت اقامت
        if (hasCar) {
            totalCost += stayDuration * 10000; // هزینه پارکینگ
        }
        return totalCost;
    }
};

// تابع برای نمایش اطلاعات یک مشتری
void displayCustomerInfo(const Customer& customer) {
    cout << "Name: " << customer.name << " " << customer.lastName << endl;
    cout << "Phone Number: " << customer.phoneNumber << endl;
    cout << "Stay Duration: " << customer.stayDuration << " days" << endl;
    cout << "Companion Name: " << customer.companionName << endl;
    cout << "Check-in Date: " << customer.checkInDate << endl;
    cout << "Has Car: " << (customer.hasCar ? "Yes" : "No") << endl;
}

int main() {
    vector<Customer> customers;

    char choice;
    do {
        cout << "Hotel Management System" << endl;
        cout << "1. Register a Customer" << endl;
        cout << "2. Calculate Total Cost for a Customer" << endl;
        cout << "3. Display Customer Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                Customer customer;
                cout << "Enter customer details:" << endl;
                cout << "Name: ";
                cin >> customer.name;
                cout << "Last Name: ";
                cin >> customer.lastName;
                cout << "Phone Number: ";
                cin >> customer.phoneNumber;
                cout << "Stay Duration (days): ";
                cin >> customer.stayDuration;
                cout << "Companion Name: ";
                cin >> customer.companionName;
                cout << "Check-in Date: ";
                cin >> customer.checkInDate;
                cout << "Does the customer have a car? (Y/N): ";
                char hasCarChoice;
                cin >> hasCarChoice;
                customer.hasCar = (hasCarChoice == 'Y' || hasCarChoice == 'y');
                customers.push_back(customer);
                break;
            }
            case '2': {
                int customerIndex;
                cout << "Enter the index of the customer: ";
                cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < customers.size()) {
                    cout << "Total cost for customer " << customerIndex << ": "
                         << customers[customerIndex].calculateTotalCost() << " Toman" << endl;
                } else {
                    cout << "Invalid customer index." << endl;
                }
                break;
            }
            case '3': {
                for (size_t i = 0; i < customers.size(); ++i) {
                    cout << "Customer " << i << ":" << endl;
                    displayCustomerInfo(customers[i]);
                    cout << "Total Cost: " << customers[i].calculateTotalCost() << " Toman" << endl;
                    cout << "--------------------------------------" << endl;
                }
                break;
            }
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
