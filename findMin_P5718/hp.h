//
//  hp_plus.h
//  findMin_P5718
//
//  Created by 姚晨 on 2025/10/23.
//
#ifndef HP_H
#define HP_H
#include <string>
#include <vector>
using namespace std;
//string hp_Add_Optimized(string s1, string s2); //更加简洁高效的高精度加法计算
string hp_Add(string s1,string s2);  //高精度加法计算，需要传入的数据为两个string类型的数据
string hp_Min(string s1, string s2);
    //高精度减法计算，需要传入的数据为两个string类型的数据
#endif // !HP_H
