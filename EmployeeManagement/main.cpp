//
//  main.cpp
//  EmpolyeeManagement.cpp
//
//  Created by aman pal on 04/12/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>

using namespace std;

struct Employee{
    int emp_id;
    string emp_name;
    double salary;
};


void displayEmployee(const Employee& emp){
    
    cout << "ID: " << emp.emp_id << endl;
    cout << "Name: " << emp.emp_name << endl;
    cout << "Salary: $" << emp.salary << endl;
    
    
}

int main(){
    vector<Employee> employees = {
        {101, "Aryan", 12000},
        {102, "Aman", 3200},
        {103, "Abhijeet", 3456},
        {104, "upanshu", 23456}
    };
    //lamdas: Unnamed function
    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2){
        return e1.salary > e2.salary;
    }); //sorting the employee salary
    
    cout << "employee salary sorted -> Highest Salary first\n";
    
    for_each(employees.begin(), employees.end(), displayEmployee);
    
    vector<Employee> highEarners;
    
    copy_if(employees.begin(),
            employees.end(),
            back_inserter(highEarners),
            [](const Employee& e){
        
            return e.salary > 5000;
    });//copy with if condition
    
    cout << "who are high earners\n";
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);
    
   double  totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e){
        return sum + e.salary;
    });
    
    double averageSalary = totalSalary/employees.size();
    
   auto highest_salary = max_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2){
        return e1.salary < e2.salary;
    });
    
    
    
    return 0;
}
