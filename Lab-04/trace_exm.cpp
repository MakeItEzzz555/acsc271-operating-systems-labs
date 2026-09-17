#include <iostream>
#include <fstream>
#include <cmath>  
using namespace std;

int main() {
    
    int num1, num2;              
    double real1, real2;        

    
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

   
    cout << "Enter two real numbers: ";
    cin >> real1 >> real2;

    
    int int_sum = num1 + num2;

   
    double geo_avg = sqrt(real1 * real2);

    
    ofstream result_file("trace_exm.out.txt");

    // Check if file is open
    if (!result_file) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Writing the results to the file
    result_file << "Sum of integers: " << int_sum << endl;
    result_file << "Geometric average of real numbers: " << geo_avg << endl;

    // Close the file
    result_file.close();

    cout << "Results saved to trace_exm.out" << endl;

    return 0;
}

