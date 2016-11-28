#include "QuickSort.h"
void QuickSort::exchange(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int QuickSort::PARTITION(vector<int> & vec, int p, int r) {
	int x = vec[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (vec[j] <= x) {
			i++;
			exchange(vec[i], vec[j]);
		}
	}
	exchange(vec[i + 1], vec[r]);
	return i+1;
}
void QuickSort::QSort(vector<int> & vec, int p, int r) {
	 if(p<r){
		int q = PARTITION(vec, p, r);
		QSort(vec, p, q - 1);
		QSort(vec, q + 1, r);
	}
}
void QuickSort::QSort(vector<int> & vec) {
	QSort(vec, 0, vec.size() - 1);
}
void QuickSort::ISort(vector<int> & vec) {
	for (int j = 1; j < vec.size(); j++) {
		int key = vec[j];
		int i = j - 1;
		while (i >=0 && vec[i] > key) {
			vec[i + 1] = vec[i];
			i--;
		}
		vec[i + 1] = key;
	}
}

