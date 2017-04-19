//
//  main.cpp
//  
//
//  Created by GordonTJ on 2017/4/13.
//  Copyright © 2017年 bupt. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    
    //多项式系数，不存在的项系数为0，从0次幂开始输入
    double *coe = new double[n + 1];
    for(int i = 0; i <= n; ++i){
        cin >> coe[i];
    }
    cout << "Input the X value you want to compute-->";
    double x = 0;
    cin >> x;
    double fx = coe[n];
    
    //秦九韶算法，原理很简单，提取公因式求积
    //但能很高效的减少CPU运算时间，为O(2N)时间，N是多项式的阶，N次加法N次乘法
    for(int i = n - 1; i >= 0; --i){
        fx = x * fx + coe[i];
    }
    
    cout.setf(ios::fixed);
    cout << "answer for " << x << " is : " << setprecision(20) << fx << endl;
    return 0;
}
