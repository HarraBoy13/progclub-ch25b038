#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std; //It's kinda annoying without this :)

// For printing doubles till 5 digits after decimal
void print_truncated(double num) {
    double shifted = num * 100000.0;
    double truncated_shifted = floor(shifted);
    double final_num = truncated_shifted / 100000.0;

    std::cout << std::fixed << std::setprecision(5) << final_num;
}

/* ----------------- DON'T CHANGE ANYTHING ABOVE THIS LINE ----------------- */
/* ------------------- IF YOU DO. I KNOW WHERE YOU LIVE -------------------- */

// Declare and define your TASK functions and helper functions here
double converted(double cur1, string cry1, string cryFinal) {
    double value {cur1};
    if (cry1 == "INR") {
        value /= 83.00;
        cout << value << endl;
    }
    else if (cry1 == "EUR") {
        value /= 0.92;
        cout << value << endl;
    }
    else if (cry1 == "JPY") {
        value /= 148.00;
        cout << value << endl;
    }
    if (cryFinal == "INR") {
        value *= 83.00;
        cout << value << endl;
    }
    else if (cryFinal == "EUR") {
        value *= 0.92;
        cout << value << endl;
    }
    else if (cryFinal == "JPY") {
        value *= 148.00;
        cout << value << endl;
    }
    return value;
}


int main() {
    int n, task {};
    double cur1, cur2 {};
    string cry1, cry2, cryFinal {};
    vector<double> out_vector {};

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> task;
        if (task == 1) {
            cin >> cur1 >> cry1 >> cryFinal;
            out_vector.push_back(converted(cur1, cry1, cryFinal));
        }
        else if (task == 2) {
            cin >> cur1 >> cry1 >> cur2 >> cry2 >> cryFinal;
            out_vector.push_back(converted(cur1, cry1, cryFinal) + converted(cur2, cry2, cryFinal));
        }
    }

    for (double i: out_vector) {
        print_truncated(i);
        cout << endl;
    }
    // Handle test cases/input and output your solutions here.
    // You have to use the function 'print_truncated' to output your solution.
    // print_truncated(15.0) will output 15.00000

    return 0;
}