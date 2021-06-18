#include <NTL/ZZ.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace NTL;

ZZ mod(ZZ a, ZZ n) {
  ZZ r = a - (a / n) * n;
  if (r < 0)
    return r + n;
  else
    return r;
}

ZZ Pow(ZZ a, ZZ b) {
  ZZ a1 = a;
  while (b > 0) {
    a = a * a1;
    b--;
  }
  return a;
}


void linearCongruentialMethod(ZZ Xo, ZZ m, ZZ a, ZZ c, vector<ZZ> &randomNums,
                              int noOfRandomNums) {

  
  randomNums[0] = Xo;


  for (int i = 1; i < noOfRandomNums; i++) {
    
    randomNums[i] = mod(((randomNums[i - 1] * a) + c), m);
  }
}


int main() {
  ZZ Xo(time(NULL)); 
  ZZ n = conv<ZZ>("2046");
  ZZ m(Pow(ZZ(2), n)); 
  ZZ a = conv<ZZ>("143512312312343546433214546768679878976546347568678677658678"
                  "568658"); 
  ZZ c = conv<ZZ>("143512312312343546433214546768679878976546347568678677658678"
                  "568658");
  cout << m << endl;

  
  int noOfRandomNums = 20;

 
  vector<ZZ> randomNums(noOfRandomNums);

  
  linearCongruentialMethod(Xo, m, a, c, randomNums, noOfRandomNums);

  \
  for (int i = 0; i < noOfRandomNums; i++) {
    cout << randomNums[i] << " ";
  }

  return 0;
}
