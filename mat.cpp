#include "mat.hpp"
#include <string>
#include <map>
#include <stdexcept>
#include <iostream>

using namespace std; 
using namespace ariel;




string  ariel::mat(int column, int row, char flag_a, char flag_b)  {
    
// check if the input o.k :  size of column and row only positive ,odd and greater than zero,  flags no empty .
    
    if (flag_a < min_flag || flag_a > max_flag || flag_b < min_flag || flag_b > max_flag ){
        throw std::out_of_range("illegal flag ");
    } 
    
    if (column < 0 || row < 0 || column%2==0 || row%2==0 ){
        throw std::out_of_range("row and column must be positive and odd ");
    } 

// create D.B to the mat

    map<pair<int, int>, char> mat;
    int size_row = row;
    int size_col = column; 

//  insert flag's (char) to the mat (map), even frame = flag_a , odd frame =flag_b  

    for( int i=0;i<size_row;i++){

        if(i%2==0){
            for( int j=i;j<size_col;j++){                                    
                    mat[{i,j}]=flag_a;
                    mat[{size_row-1,j}]=flag_a;
            }                                   
            for( int j=i;(j<size_row)&&(i<size_col);j++){
                    mat[{j,i}]=flag_a;
                    mat[{j,size_col-1}]=flag_a;
                }
        }

        else if(i%2!=0){
            for( int j=i;j<size_col;j++){                                    
                    mat[{i,j}]=flag_b;
                    mat[{size_row-1,j}]=flag_b;
                }                                   
            for( int j=i;(j<size_row)&&(i<size_col);j++){
                    mat[{j,i}]=flag_b;
                    mat[{j,size_col-1}]=flag_b;
                }
        }

        size_row--;
        size_col--;
    }


//  create mat (string) 

    string str_mat;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            str_mat.push_back(mat[{i,j}]);
        }  
        str_mat.push_back('\n');
    }
    // cout << str_mat << endl;
    return str_mat;

}