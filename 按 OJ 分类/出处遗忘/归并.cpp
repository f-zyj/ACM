#include <iostream>

using namespace std;

const int N = 10;
int anthor[N];
void MergeSort(int *array, int begin, int end)
{
	if (end - begin > 1)
	{
		//
		MergeSort(array, begin, (begin + end) / 2);
		MergeSort(array, (begin + end) / 2 + 1, end);

		int i = begin;
		int j = (begin + end) / 2 + 1;
		int k = begin;

		while (i <= (begin + end) / 2 && j <= end)//合并时，把一个串全部并入另一个串放在一个新串，剩下的直接放在尾部
		{
			if (array[i] > array[j])        //小的值进入，并将索引后移
				anthor[k++] = array[j++];
			if (array[i] < array[j])
				anthor[k++] = array[i++];

		}
		while (i <= (begin + end) / 2)
		{
			anthor[k++] = array[i++];
		}
		while (j <= end)
		{
			anthor[k++] = array[j++];
		}

		for (k = begin; k <= end; k++)    //排序好重新拷贝回数组
			array[k] = anthor[k];

	}
	else      //相邻则直接交换
	{
		if (array[end] < array[begin])
		{
			int temp = array[end];
			array[end] = array[begin];
			array[begin] = temp;
		}
	}
}


int main6()
{


	int array[N];
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}

	MergeSort(array, 0, N - 1);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{

		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}

