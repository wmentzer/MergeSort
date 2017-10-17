#include <iostream>
#include <cassert>

using namespace std;

void copy_array(int dst[], int src[], int count) {
	for(int i = 0; i < count; i++) {
		dst[i] = src[i];
	}
}

// s = start of range to sort
// e = end of range to sort
void msort(int  a[], int x[], int s, int e) {
	if ((e - s) < 1) {
		return;
	}

	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	msort(a,x,s,mid);
	msort(a,x,mid + 1, e);

	copy_array(&x[s],&a[s],e-s+1);

	while (i <= mid && j <= e) {
		if(x[i] <= x[j] && k <= e) {

			a[k] = x[i];
			i++;
			k++;
		} else if (x[j] < x[i] && k <= e) {
//			cout << a[j] << " " << endl;

			a[k] = x[j];
			j++;
			k++;
		}
	}

	if(i <= mid) {
		while (i <= mid) {
			a[k] = x[i];
			i++;
			k++;
		}
	}

	if(j <= e) {
		while (j <= e) {
			a[k] = x[j];
			j++;
			k++;
		}
	}
}

void mergesort( int a[], int size) {

	int *x = new int[size];

	msort(a,x,0,size-1);

	delete [] x;
}


bool sorted(int a[], int size) {
	for(int i = 0; i < size - 1; i++) {
		if(a[i] > a[i+1]) { return false;}
	} return true;
}

int main(int argc, char * args[]) {
	/* int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));
	*/

	int a[10];
	for (int i = 0; i < 10; ++i) a[i] = -50 + rand() % 100;

	for(int i = 0; i < 10; i++) cout << a[i] << endl;
	cout << endl;

	mergesort(a,10);

	cout << endl;

	for(int i = 0; i < 10; i++) cout << a[i] << endl;
	cout << endl;
}
