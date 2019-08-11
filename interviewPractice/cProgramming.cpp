#include <iostream>
#include <string>

using namespace std;

struct Result
{
  char *output1[100];
};

int main()
{
  char *input1 = "Hari Harshit Hardik Harkamp Hamjit Harshiva";
  char *input2 = "Har";
  char ch, indx = 0;
  string luck;
  Result obj;
  //vector<string> v;
  while (*input1 != '\0')
  {
    ch = *input1;
    bool ok = 1;
    if (ch == ' ')
    {
      int i = 0;
      while (input2[i] != '\0')
      {
      //  cout << "ja " << endl;
        if (input2[i] != luck[i])
        {
          ok = 0;
          break;
        }
        i += 1;
      }
      if (ok)
      {
        char *temp = new char[120];
        cout << luck << " " << luck.size() << endl;
        for (int i = 0 ; i < luck.size();++i)
        {
          temp[i] = luck[i];
        }

        obj.output1[indx] = temp;
        indx += 1;
      }
      luck.clear();
      input1+=1;
      continue;
    }
    luck.push_back(ch);
    input1 += 1;
    //cout << "chal raha h" << endl;
  }
  cout << "outside " << endl;
  //return 0;
  for (int i = 0 ; i < 3; ++i)
  {
    //cout << "ghusa" << endl;
    char *show = obj.output1[i];
    int j = 0;
    while (show[j] != '\0')
    {
      cout << show[j];
      j += 1;
    }
    cout << endl;
  }
  return 0;
}
