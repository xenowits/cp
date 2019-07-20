#include <iostream>
      #include <string>
      #include <map>

      using namespace std;

      int main()
      {
              typedef map<string, long, less<string> > MAP;
              typedef MAP::value_type VAL;

              MAP counter;

              char buf[40];

              while (cin >> buf)
                      counter[buf]++;

              MAP::iterator it = counter.begin();

              while (it != counter.end()) {
                      cout << (*it).first << " " << (*it).second << endl;
                      it++;
              }

              return 0;
      }
