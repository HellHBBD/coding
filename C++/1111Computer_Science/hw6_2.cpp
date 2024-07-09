#include <bits/stdc++.h>
using namespace std;

int main(){
  char a;
  cout << "Please input an alphabet:";
  cin >> a;
  int ascii = static_cast<int>(a);
  cout << "After converting:";
  if (ascii >= 65 and ascii <= 90) cout << static_cast<char>(ascii+32);
  else if (ascii >= 97 and ascii <= 122) cout << static_cast<char>(ascii-32);
  return 0;
}
