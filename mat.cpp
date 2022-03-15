#include "mat.hpp"
using namespace ariel;

#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

string ariel::mat(int coloms, int rows, char first, char second)
{
    /* check for incorrect input */
    const int min = 33;
    const int max = 126;
    if(rows <= 0){
        throw runtime_error("rows need to be a positive integer");
    }
    if(coloms <= 0){
        throw runtime_error("coloms  need to be a positive integer");
    }
    if(rows % 2 == 0){
        throw runtime_error("Mat size is always odd");
    }
    if(coloms % 2 == 0){
        throw runtime_error("Mat size is always odd");
    }
    if(first < min || first > max){
        throw runtime_error("first char is not vallid");
    }
    if (second < min || second > max){
        throw runtime_error("second char is not vallid");
    }

    /* everything is okay so declare the needed variables */
    string res;
    vector<string> half_res;
    int half = (rows / 2) + 1;
    string curr_line;
    int what_char = 0;
    bool first_row = true;
    int i = 0;

    /* loop until the middle row because after that the rows are reapeating the previous rows 
       but backwards. for every row we will use the row before and flip from the j'th spot
       to the coloms - i spot the varibales that in those spots. then after we finished the row we
       will append that row to our vector- half_res and continue to the next row */

    while (i < half)
    {
        for (int j = i; j < coloms - i; j++)
        {
            if (what_char % 2 == 0)
            {
                if(first_row){
                    curr_line += first;
                }
                else{
                    curr_line.at(j) = first;
                }
            }
            else
            {
                curr_line.at(j) = second;
            }
        }
        first_row = false;
        i++;
        what_char += 1;
        half_res.push_back(curr_line);
    }

    /* make the final string, just copy all the vector from before and add \n, after that 
       for each line that is beyond the half row copy the correct row (from the middle start
       going back and copy that row and so on) */

    for(i = 0; i < half - 1; i++)
    {
        res += half_res[i];
        res += '\n';
    }
    for(i = half - 1; i >= 0; i--){
        res += half_res[i];
        res += '\n';
    }

    return res;
}