//
//  highAcPlus.cpp
//  findMin_P5718
//
//  Created by 姚晨 on 2025/10/21.
//

//ds老师改的第二版
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string hp_Add(string s1, string s2) {
    // 高精度加法
    if (s1.length() < s2.length()) {
        swap(s1, s2);
    }
    
    // 数组长度（为进位预留空间）
    unsigned long arrLen = s1.length() + 1;
    vector<int> a1(arrLen, 0), a2(arrLen, 0), result(arrLen, 0);
    
    // 逆序字符串
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    // 将string转换为int类型并存进数组
    for (unsigned long i = 0; i < s1.length(); i++) {
        a1[i] = s1[i] - '0';
    }
    
    for (unsigned long i = 0; i < s2.length(); i++) {
        a2[i] = s2[i] - '0';
    }
    
    // 修复：使用进位变量代替temp数组
    int carry = 0;
    for (unsigned long i = 0; i < arrLen; i++) {
        int sum = a1[i] + a2[i] + carry;
        result[i] = sum % 10;  // 当前位
        carry = sum / 10;      // 进位
    }
    
    // 将数组正序
    reverse(result.begin(), result.end());
    
    // 修复：正确处理前导零
    string str_result = "";
    bool found_non_zero = false;
    
    for (unsigned long i = 0; i < arrLen; i++) {
        if (result[i] != 0) {
            found_non_zero = true;
        }
        if (found_non_zero) {
            str_result += to_string(result[i]);
        }
    }
    
    // 如果全是零，返回"0"
    if (str_result == "") {
        return "0";
    }
    
    return str_result;
}


//高精度减法
string hp_Min(string s1, string s2){
        char mark = '+';     //初始化符号为+
        string  result;

        if(s1.size() < s2.size() ||
           (s1.size() == s2.size() && (s1<s2))){
            swap(s1,s2);
            mark = '-';
        }
    
        unsigned long a1_len = s1.length(),a2_len = s2.length();
        vector <int> a1(a1_len + 1, 0),
                     a2(a2_len + 1, 0),
                     temp(a1_len + 1, 0);//初始化数组
        // 逆序字符串
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
    
        // 将string转换为int类型并存进数组
        for (unsigned long i = 0; i < a1_len; i++) {
            a1[i] = s1[i] - '0';
        }
        
        for (unsigned long i = 0; i < a2_len; i++) {
            a2[i] = s2[i] - '0';
        }
        
        
        //高精度减法部分
        for (unsigned long i = 0; i < a1_len; i++) {
            if(a1[i] < a2[i]){
                temp[i] = (a1[i]+10) - a2[i];
                a1[i+1] = a1[i+1]-1;
            }else{
                temp[i] = a1[i] - a2[i];
            }
        }
        
        
        //将数组正序
        reverse(temp.begin(), temp.begin() + a1_len);
    
        //转换为string并输出
        for (unsigned long i=0;i<temp.size();i++){
            result += to_string(temp[i]);
        }
    
    //处理前导零
    bool found_non_zero = false;
    
    for (unsigned long i = 0; i < a1_len; i++) {
        //遍历检查temp
        if (temp[i] != 0) {
            found_non_zero = true;  //找到第一个非零的数字
        }
        if (found_non_zero) {       //从第一个非零的位置开始输出
            result += to_string(temp[i]);
        }
    }
        //添加符号
        if (mark == '-') {
        result = mark + result;
    }
    
        return result;       //以string输出结果
}


//高精度乘法
string hp_Muit(string s1, string s2){
    
    //判断s1，s2的大小并进行交换
    if(s1.size() < s2.size() ||
       (s1.size() == s2.size() && (s1<s2))){
        swap(s1,s2);
    }
    
    //分别判断s1，s2的符号（+，-）
    unsigned short s1_Mark, s2_Mark;
    if(s1[1] == '-') s1_Mark = 1;
        else s1_Mark = 0;
    if(s2[1] == '-') s2_Mark = 1;
        else s2_Mark = 0;
    
    //初始化数组
    vector <int> a1(s1.size() + 1,0),
                 a2(s2.size() + 1,0),
                 temp((s1.size() - s1_Mark)+(s2.size() - s2_Mark),0);
    char Mark = '-';
    string result;
    int carry = 0;//用于承载进位
    
    //判断结果的符号
    if((s1[1] == '-' && s2[1] == '-')
       or  (s1[1] != '-' && s2[1] != '-')){
        char Mark = '+';
    }
    
    //逆序并将string转换并输入数组
    // 逆序字符串（s1,s2mark是为了防止录入符号！）
    reverse(s1.begin()+s1_Mark, s1.end());
    reverse(s2.begin()+s2_Mark, s2.end());
    
    // 将string转换为int类型并存进数组
    if(s1_Mark == 1){
        unsigned long long i = 1;
        for (unsigned long long j=0; i < s1.size(); i++,j++) {
            a1[j] = s1[i] - '0';
        }
    }
    else {
        for (unsigned long long i = 0; i < s1.size(); i++) {
            a1[i] = s1[i] - '0';
        }
    }
    if(s1_Mark == 1){
        unsigned long long i = 1;
        for (unsigned long long j=0; i < s2.size(); i++,j++) {
            a2[j] = s1[i] - '0';
        }
    }
    else{
        for (unsigned long long i = 0; i < s2.size(); i++) {
            a2[i] = s1[i] - '0';
        }
    }
    
    //计算的主体部分
    
    for (unsigned long long j=0; j < a2.size(); j++){
        carry = 0;
        for (unsigned long long i=0; i < a1.size()+1; i++){
            temp[i+j] += ((a2[j] * a1[i]) % 10) + carry;
            carry = (int)((a2[j] * a1[i])/10);
        }
    }
    
    //逆序，消零，输出
    
    
    //
    return result;
}
