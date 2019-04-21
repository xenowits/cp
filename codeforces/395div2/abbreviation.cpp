#include <bits/stdc++.h>
using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
  stack<char> stka, stkb;
  for (int i = 0; i < a.length(); ++i)
    stka.push(a[i]);
  for (int i = 0; i < b.length(); ++i)
    stkb.push(b[i]);
  if (a.length() < b.length()) {
    return "NO";
  }
  char nice = '\0';
  bool truth1 = true, truth2 = true;
  while (!stka.empty() && !stkb.empty()) {
    char temp1 = stka.top();
    char temp2 = stkb.top();
    if (temp1 == temp2 || char(toupper(temp1)) == temp2) {
      stka.pop();
      nice = stkb.top();
      stkb.pop();
      continue;
    } else if (isupper(temp1) && toupper(temp1) != nice) {
      truth2 = false;
      cout << temp1 << " " << nice << " kal gya yeha" << endl;
      break;
    }
    stka.pop();
  }
  if (!stka.empty()) {
    while (!stka.empty()) {
      if (isupper(stka.top())) {
        truth2 = false;
        cout << "nhi yeha kata"<< endl;
        break;
      }
      stka.pop();
    }
  }
  if (!stkb.empty())
  {
      truth2 = false;
      cout << "kat gya akhir m rama" << endl;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  stack<int> stk1, stk2;
  nice = '\0';
  for (int i = 0; i < a.length(); ++i)
    stk1.push(a[i]);
  for (int i = 0; i < b.length(); ++i)
    stk2.push(b[i]);
  while (!stk1.empty() && !stk2.empty()) {
    char temp1 = stk1.top();
    char temp2 = stk2.top();
    if (temp1 == temp2 || char(toupper(temp1)) == temp2) {
      stk1.pop();
      nice = stk2.top();
      stk2.pop();
      continue;
    } else if (isupper(temp1) && toupper(temp1) != nice) {
      truth1 = false;
      break;
    }
    stk1.pop();
  }
  if (!stk1.empty()) {
    while (!stk1.empty()) {
      if (isupper(stk1.top())) {
        truth1 = false;
        break;
      }
      stk1.pop();
    }
  }
  if (!stk2.empty())
    truth1 = false;
  if (!truth1)
    cout << "pehla" << endl;
  if (!truth2)
    cout << "doosra" << endl;
  if (truth1 || truth2)
    return "YES";
  else
    return "NO";
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string a;
    string b;
    cin >> a >> b;
    string result = abbreviation(a, b);

    cout << result << endl;
  }

  // fout.close();

  return 0;
}
