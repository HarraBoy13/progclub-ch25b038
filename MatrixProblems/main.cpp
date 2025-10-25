#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

// For printing doubles till 5 digits after decimal
void print_truncated(double num) {
    double shifted = num * 100000.0;
    double truncated_shifted = floor(shifted);
    double final_num = truncated_shifted / 100000.0;

    cout << fixed << setprecision(5) << final_num;
}

// Direct comparison of doubles/floats using `==` is unreliable due to precision errors inherent in 
// floating-point arithmetic. This function checks if the absolute difference between
// two numbers is within a small tolerance (epsilon).
bool nearlyEqual(double x, double y, double eps = EPS) {
    return fabs(x - y) <= eps * max(1.0, max(fabs(x), fabs(y)));
}

/* ----------------- DON'T CHANGE ANYTHING ABOVE THIS LINE ----------------- */
/* ------------------- IF YOU DO. I KNOW WHERE YOU LIVE -------------------- */
class Matrix {
    private:
        vector<vector<double>> mat_vector {};
        size_t size {};
        
    public:
        Matrix(int n) {
            size = n;
            mat_vector.resize(n, vector<double>(n, 0.0));
        }

        Matrix(vector<vector<double>> elements) {
            size = elements.size();
            mat_vector = elements;
        }

        void input() {
            for (size_t i = 0; i < size; i++) {
                for (size_t j = 0; j < size; j++) {
                    cin >> mat_vector[i][j];
                }
            }
        }

        void print() {
            if (size == 0) {
                cout << "[ empty matrix ]";
            }          
            else { 
                for (size_t i = 0; i < size; i++) {
                    for (size_t j = 0; j < size; j++) {
                        print_truncated(mat_vector[i][j]);
                        if (j+1<size) cout << " ";
                    }
                    if (i+1<size) cout << endl;
                }
            }
        }

        Matrix operator+(Matrix other) {
            vector<vector<double>> el(size, vector<double>(size));
            if (size == other.size) {
                for (size_t i = 0; i < size; i++) {
                    for (size_t j = 0; j < size; j++) {
                        el[i][j] = mat_vector[i][j] + other.mat_vector[i][j];
                    }
                }
                return Matrix(el);
            }
            else {
                return Matrix(0);
            }
        }

        Matrix operator-(Matrix other) {
            vector<vector<double>> el(size, vector<double>(size));
            if (size == other.size) {
                for (size_t i = 0; i < size; i++) {
                    for (size_t j = 0; j < size; j++) {
                        el[i][j] = mat_vector[i][j] - other.mat_vector[i][j];
                    }
                }
                return Matrix(el);
            }
            else {
                return Matrix(0);
            }
        }

        Matrix operator*(Matrix other) {
            vector<vector<double>> el(size, vector<double>(size));
            if (size == other.size) {
                for (size_t i = 0; i < size; i++) {
                    for (size_t j = 0; j < size; j++) {
                        double sum {};
                        for (size_t k = 0; k < size; k++) {
                            sum += mat_vector[i][k] * other.mat_vector[k][j];
                        }
                        el[i][j] = sum;
                    }
                }
                return Matrix(el);
            }
            else {
                return Matrix(0);
            }
        }

        Matrix operator*(double it) {
            vector<vector<double>> el(size, vector<double>(size));
            for (size_t i = 0; i < size; i++) {
                for (size_t j = 0; j < size; j++) {
                    el[i][j] = mat_vector[i][j] * it;
                }
            }
            return Matrix(el);
        }

        bool operator==(Matrix other) {
            if (size == other.size) {
                for (size_t i = 0; i < size; i++) {
                    for (size_t j = 0; j < size; j++) {
                        if (!(nearlyEqual(mat_vector[i][j], other.mat_vector[i][j]))) return false;
                    }
                }
                return true;
            }
            else {
                return false;
            }
        }

        Matrix transpose() {
            vector<vector<double>> el(size, vector<double>(size));
            for (size_t i = 0; i < size; i++) {
                for (size_t j = 0; j < size; j++) {
                    el[j][i] = mat_vector[i][j];
                }
            }
            return Matrix(el);
        }

        double trace() {
            double result {};
            for (size_t i = 0; i < size; i++) {
                result += mat_vector[i][i];
            }
            return result;
        }
        double cofactor(int i, int j) {
            vector<vector<double>>cpy = mat_vector;
            cpy.erase(cpy.begin() + i);
            for(auto &sub: cpy) {
                sub.erase(sub.begin() + j);
            }
            int sign {((i+j) % 2 == 0) ? 1 : -1};
            return static_cast<double>(sign) * Matrix(cpy).determinant();
        }

        double determinant() {
            switch(size) {
                case 0:
                    return 0;
                case 1:
                    return mat_vector[0][0];
                case 2:
                     return mat_vector[0][0] * mat_vector[1][1] - mat_vector[0][1] * mat_vector[1][0];
                default:
                    double sum {};
                    for (size_t num = 0; num < size; num++) {
                        sum += mat_vector[0][num] * this->cofactor(0, num);
                    }
                    return sum;
            }
        }

        Matrix cofactorMatrix() {
            vector<vector<double>> el(size, vector<double>(size));
            for (size_t i = 0; i < size; i++) {
                for (size_t j = 0; j < size; j++) {
                    el[i][j] = this->cofactor(i, j);
                }
            }
            return Matrix(el);
        }

        Matrix inverse() {
            Matrix adj {this->cofactorMatrix().transpose()};
            double det = this->determinant();
            if (nearlyEqual(det, 0.0)) {
                return Matrix(0);
            }
            else {
                return adj * (1/det);
            }
        }
};

// Define your Functions here 

/* ----------------- DEFINE TO SWITCH ON THE QUERY ----------------- */

#define QUERY_1
#define QUERY_2
#define QUERY_3
#define QUERY_4
#define QUERY_5
#define QUERY_6
#define QUERY_7
#define QUERY_8
#define QUERY_9
#define QUERY_10
#define QUERY_11
#define QUERY_12
#define QUERY_14

/* ----------------- DON'T CHANGE ANYTHING BELOW THIS LINE ----------------- */
/* ------------------- IF YOU DO. I KNOW WHERE YOU LIVE -------------------- */
int main(){
    vector<Matrix> matrices;
    int num_of_queries;
    cin >> num_of_queries;

    while (num_of_queries--) {
        string query;
        cin >> query;

        try {
            if (query == "create_sized") {
                #ifdef QUERY_1
                int n;
                cin >> n;
                matrices.emplace_back(n);
                #endif
            } else if (query == "input") {
                #ifdef QUERY_2
                int n;
                cin >> n;
                Matrix temp(n);
                temp.input();
                matrices.push_back(move(temp));
                #endif
            } else if (query == "print") {
                #ifdef QUERY_3
                int i;
                cin >> i;
                matrices[i].print();
                cout<<endl;
                #endif
            } else if (query == "add") {
                #ifdef QUERY_4
                int i, j;
                cin >> i >> j;
                matrices.push_back(matrices[i] + matrices[j]);
                #endif
            } else if (query == "subtract") {
                #ifdef QUERY_5
                int i, j;
                cin >> i >> j;
                matrices.push_back(matrices[i] - matrices[j]);
                #endif
            } else if (query == "multiply") {
                #ifdef QUERY_6
                int i, j;
                cin >> i >> j;
                matrices.push_back(matrices[i] * matrices[j]);
                #endif
            } else if (query == "equal") {
                #ifdef QUERY_7
                int i, j;
                cin >> i >> j;
                cout << ((matrices[i] == matrices[j]) ? "YES" : "NO") << endl;
                #endif
            } else if (query == "determinant") {
                #ifdef QUERY_8
                int i;
                cin >> i;
                print_truncated(matrices[i].determinant());
                cout<<endl;
                #endif
            } else if (query == "transpose") {
                #ifdef QUERY_9
                int i;
                cin >> i;
                matrices.push_back(matrices[i].transpose());
                #endif
            } else if (query == "trace") {
                #ifdef QUERY_10
                int i;
                cin >> i;
                print_truncated(matrices[i].trace());
                cout<<endl;
                #endif
            } else if (query == "cofactor") {
                #ifdef QUERY_11
                int i;
                cin >> i;
                matrices.push_back(matrices[i].cofactorMatrix());
                #endif
            } else if (query == "inverse") {
                #ifdef QUERY_12
                int i;
                cin >> i;
                matrices.push_back(matrices[i].inverse());
                #endif
            } else if (query == "row_echelon") {
                #ifdef QUERY_13
                int i;
                cin >> i;
                matrices.push_back(matrices[i].rowEchelon());
                #endif
            } else if (query == "create_from_vector") {
                #ifdef QUERY_14
                vector<vector<double>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
                matrices.emplace_back(data);
                #endif
            }
        } 
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
