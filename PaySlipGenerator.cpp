
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee {
private:
    string empID, name, designation, month;
    float basicSalary, hra, da, pf, tax;

public:
    void inputDetails() {
        cout << "Enter Employee ID: ";
        getline(cin, empID);
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Month of Pay Slip: ";
        getline(cin, month);

        cout << "Enter Basic Salary: BDT";
        cin >> basicSalary;
        cout << "Enter HRA: BDT";
        cin >> hra;
        cout << "Enter DA: BDT";
        cin >> da;
        cout << "Enter Provident Fund (PF): BDT";
        cin >> pf;
        cout << "Enter Professional Tax: BDT";
        cin >> tax;

        cin.ignore();
    }

    float calculateEarnings() {
        return basicSalary + hra + da;
    }

    float calculateDeductions() {
        return pf + tax;
    }

    float calculateNetSalary() {
        return calculateEarnings() - calculateDeductions();
    }

    void displayPaySlip() {
        cout << "\n--------------------------------------------------------\n";
        cout << "                 XYZ PRIVATE LIMITED\n";
        cout << "--------------------------------------------------------\n";
        cout << "                 EMPLOYEE PAY SLIP - " << month << "\n";
        cout << "--------------------------------------------------------\n";
        cout << "Employee ID     : " << empID << "\n";
        cout << "Employee Name   : " << name << "\n";
        cout << "Designation     : " << designation << "\n\n";

        cout << "------------------- EARNINGS ---------------------------\n";
        cout << fixed << setprecision(2);
        cout << "Basic Salary     : BDT" << basicSalary << "\n";
        cout << "HRA              : BDT" << hra << "\n";
        cout << "DA               : BDT" << da << "\n";
        cout << "--------------------------------------------------------\n";
        cout << "Total Earnings   : BDT" << calculateEarnings() << "\n\n";

        cout << "------------------- DEDUCTIONS -------------------------\n";
        cout << "Provident Fund   : BDT" << pf << "\n";
        cout << "Professional Tax : BDT" << tax << "\n";
        cout << "--------------------------------------------------------\n";
        cout << "Total Deductions : BDR" << calculateDeductions() << "\n\n";

        cout << "-------------------- SUMMARY ---------------------------\n";
        cout << "Net Salary       : BDT" << calculateNetSalary() << "\n";
        cout << "--------------------------------------------------------\n";
        cout << "This is a system-generated payslip\n";
    }

    void saveToFile() {
        ofstream file("PaySlip_" + empID + ".txt");
        if (file.is_open()) {
            file << "--------------------------------------------------------\n";
            file << "                 XYZ PRIVATE LIMITED\n";
            file << "--------------------------------------------------------\n";
            file << "                 EMPLOYEE PAY SLIP - " << month << "\n";
            file << "--------------------------------------------------------\n";
            file << "Employee ID     : " << empID << "\n";
            file << "Employee Name   : " << name << "\n";
            file << "Designation     : " << designation << "\n\n";

            file << "------------------- EARNINGS ---------------------------\n";
            file << fixed << setprecision(2);
            file << "Basic Salary     : BDT" << basicSalary << "\n";
            file << "HRA              : BDT" << hra << "\n";
            file << "DA               : BDT" << da << "\n";
            file << "--------------------------------------------------------\n";
            file << "Total Earnings   : BDT" << calculateEarnings() << "\n\n";

            file << "------------------- DEDUCTIONS -------------------------\n";
            file << "Provident Fund   : BDT" << pf << "\n";
            file << "Professional Tax : BDT" << tax << "\n";
            file << "--------------------------------------------------------\n";
            file << "Total Deductions : BDT" << calculateDeductions() << "\n\n";

            file << "-------------------- SUMMARY ---------------------------\n";
            file << "Net Salary       : BDT" << calculateNetSalary() << "\n";
            file << "--------------------------------------------------------\n";
            file << "This is a system-generated payslip\n";
            file.close();

            cout << "\nPayslip successfully saved as 'PaySlip_" << empID << ".txt'\n";
        } else {
            cout << "\nError: Could not save file.\n";
        }
    }
};

int main() {
    Employee emp;
    emp.inputDetails();

    cout << "\nDo you want to generate payslip? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        emp.displayPaySlip();

        cout << "\nDo you want to save this payslip to file? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            emp.saveToFile();
        }
    }

    cout << "\nThank you for using the Pay Slip Generator!\n";
    return 0;
}
