#include <vector>
using namespace std;
class QuickSort {
private:
	int PARTITION(vector<int> & vec, int p, int r);
	void exchange(int &a, int &b);
	void QSort(vector<int> & vec, int p, int r);
public:
	void QSort(vector<int> & vec);
	void ISort(vector<int> & vec);
};
