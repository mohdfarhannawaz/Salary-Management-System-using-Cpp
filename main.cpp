#include <iostream>
#include <string>
#include <vector> // this is used for dynamic memory allocation and is more flexible for managing and storing data as compared to arrays. 
#include <cstdlib> //This header defines a collection of functions and macros to facilitate efficient, high-performing, 
                    // standardized C++ code across teams and platforms.
#include <ctime> //This header file contains definitions of functions to get and manipulate date and time information.

struct Employee {
    std::string name;
    int id;
    int workingDays;
    int leaves;
    double netSalary;
};

// Function to generate random employee data
void generateRandomData(std::vector<Employee>& employees) {
    std::string names[30] = { "John", "Alice", "Michael", "Emily", "David", "Sarah", "Daniel", "Olivia", "Matthew", "Sophia",
                              "Andrew", "Emma", "James", "Ava", "Joseph", "Isacc", "Ben", "Mia", "Daniel", "Charli",
                              "Samuel", "Amelia", "Alexa", "Liam", "Willy", "Abin", "Henry", "Ella", "Jacob", "Grace" };

    std::srand(static_cast<unsigned int>(std::time(0))); //rand() function is an inbuilt function in C++ STL, which is defined in <cstdlib> 
    //header file. 
    // rand() is used to generate a series of random numbers. We use this function when we want to generate a random number in our code

    for (int i = 0; i < 30; i++) {
        Employee employee;
        employee.name = names[i];
        employee.id = i + 1;
        employee.workingDays = std::rand() % 26 + 5;
        employee.leaves = std::rand() % 6;
        employee.netSalary = (employee.workingDays - employee.leaves) * 1000;

        employees.push_back(employee);
    }
}

// Function to display the salary report
void displaySalaryReport(const std::vector<Employee>& employees) {
    std::cout << "\nSalary Report:\n" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "ID\tName\tWorking Days\tLeaves\tNet Salary" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

    for (const auto& employee : employees) {
        std::cout << employee.id << "\t" << employee.name << "\t" << employee.workingDays << "\t\t" << employee.leaves << "\t" << employee.netSalary << std::endl;
    }

    std::cout << "-------------------------------------------------------------" << std::endl;
}

// Function to edit the salary report
void editSalaryReport(std::vector<Employee>& employees) {
    int id;
    bool found = false;

    std::cout << "\nEnter the ID of the employee to edit the salary report: ";
    std::cin >> id;

    for (auto& employee : employees) {
        if (employee.id == id) {
            std::cout << "Enter the new working days: ";
            std::cin >> employee.workingDays;
            std::cout << "Enter the new number of leaves: ";
            std::cin >> employee.leaves;
            employee.netSalary = (employee.workingDays - employee.leaves) * 1000;
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Salary report updated successfully." << std::endl;
    } else {
        std::cout << "Employee not found. Salary report not updated." << std::endl;
    }
}

int main() {
    std::string username, password;
    int loginAttempts = 0;
    bool loggedIn = false;

    // Loop until the user successfully logs in or exceeds the maximum login attempts
    while (!loggedIn && loginAttempts < 5) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        // Check if the username and password are correct
        if (username == "admin" && password == "password") {
            loggedIn = true;
        } else {
            std::cout << "Invalid username or password. Please try again." << std::endl;
            loginAttempts++;
        }
    }

    // Check if the user successfully logged in
    if (loggedIn) {
        int choice = 0;
        std::vector<Employee> employees;
        generateRandomData(employees);

        // Loop until the user chooses to exit
        while (choice != 3) {
            std::cout << "\nOptions:\n1. Employee Salary Report\n2. Change Password\n3. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == 1) {
                int reportChoice = 0;

                while (reportChoice != 3) {
                    std::cout << "\nSalary Report Options:\n1. Display Salary Report\n2. Edit Salary Report\n3. Go Back" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> reportChoice;

                    if (reportChoice == 1) {
                        displaySalaryReport(employees);
                    } else if (reportChoice == 2) {
                        editSalaryReport(employees);
                    } else if (reportChoice == 3) {
                        std::cout << "Going back to the main menu..." << std::endl;
                    } else {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                }
            } else if (choice == 2) {
                std::string newPassword, confirmNewPassword;
                std::cout << "Change Password:" << std::endl;
                std::cout << "Enter the new password: ";
                std::cin >> newPassword;
                std::cout << "Confirm the new password: ";
                std::cin >> confirmNewPassword;

                if (newPassword == confirmNewPassword) {
                    password = newPassword;
                    std::cout << "Password changed successfully." << std::endl;
                } else {
                    std::cout << "Passwords do not match. Password change unsuccessful." << std::endl;
                }
            } else if (choice == 3) {
                std::cout << "Exiting the program..." << std::endl;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    } else {
        std::cout << "The system is locked." << std::endl;
    }

    return 0;
}
