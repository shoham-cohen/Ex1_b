#include <iostream>
#include "mat.hpp"
#include "mat.cpp"
#include <string>
using namespace std;
using namespace ariel;

int main(){
    char first;
    char second;
    int coloms;
    int rows;
    cout << "insert number of coloms ";
    cin >> coloms;
    cout << "insert number of rows ";
    cin >> rows;
    cout << "insert first char ";
    cin >> first;
    cout << "insert second char ";
    cin >> second;
    string res;
    res = mat(coloms, rows, first, second);
    cout << res;  
    return 0;

}