#include <iostream>
#include <string>
using namespace std;

//SEND CHARACTER ARRAYS AS (char *arr)
//JUST CREATE A NEW STRING
//AND ASSIGN IT TO ARR

//BETTER NOT TO RETURN char*
//REASON : IF U CREATE A CHARACTER ARRAY INSIDE A FUNCTION
//IT WOULD BE LOCAL. AND WHEN WE PASS IT STARTING ADDRESS
//AS POINTER, WE WOULD NOT BE ABLE TO REFERENCE IT.
//SINCE AFTER FUNCTION ENDS, ALL MEMORY IS RELEASED!

string func1(char *a) {
	string s = a;
	return s;
}

int main() {
	char *a = "pokemon";
	char b[] = "golang";

	cout << func1(a) << endl << func1(b) << endl;
}
