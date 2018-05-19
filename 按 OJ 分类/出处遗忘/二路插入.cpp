#include<iostream>
using namespace std;
#define MAX 20
void PrintArray(int a[], int len){
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}
void BinInsertSort(int a[], int len){
	int *d = (int *)malloc(len*sizeof(len));
	for (int i = 0; i < len; i++)
		d[i] = 0;
	int first = 0, final = 0;
	d[0] = a[0];
	for (int i = 1; i < len; i++){
		if (a[i] <= d[first]){
			first = (first - 1 + len) % len;
			d[first] = a[i];
		}
		else if (a[i] >= d[final]){
			final = final + 1;
			d[final] = a[i];
		}
		else{
			int j = final++;
			while (a[i] < d[j]){
				d[(j + 1) % len] = d[j];
				j = (j - 1 + len) % len;
			}
			d[j + 1] = a[i];
		}
	}
	cout << "辅助数组中排序结果为：";
	PrintArray(d, len);
}
int main10(){
	int a[MAX], len;
	cout << "请输入待排序的元素个数：";
	cin >> len;
	cout << "请输入待排序的元素：";
	for (int i = 0; i < len; i++)
		cin >> a[i];
	BinInsertSort(a, len);
	system("pause");
	return 0;
}