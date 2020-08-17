#include <bits/stdc++.h>
using namespace std;

void f(int *x) {
	cout << *x << endl;
	x -= 1;
}

int main() {
	int arr[5] = {1,2,3,4,5};
	int x = 4;
	// for (int i = 0; i < 3; i++) {
	// 	f(arr,);
	// }
	int *y = &x;
	cout << arr[*y] << endl;
	// (*y)--;
	*y -= 1;
	cout << arr[*y] << endl;
	// int *ptr = arr+2;
	// cout << *(ptr+1) << endl;
}

// Kya aapko pata h?? Sukhdeo Lal dwara kiya gya naamkaran:
// Babita - Muswa
// Sabita - Chamgadariya
// Rakesh - Patnaiha
// Mukesh - ? (Nhi pata Kripya batae)
