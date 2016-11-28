#include "QuickSort.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
const int Size = 2000000;
int main() {
	clock_t start, end;
	srand(time(0));
	int a[Size];
	for (int i = 0; i < Size; i++)
		a[i] = rand() % Size;
	vector<int> vec(a, a + Size);
	QuickSort quicksort;
	start = clock();
	quicksort.QSort(vec);
	end = clock();
	cout << "Time of QuickSort:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	//for (auto x:vec)
		//cout << x << " ";
	cout << endl;
	return 0;
}
