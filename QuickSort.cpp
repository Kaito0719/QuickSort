#include <iostream>
#include <iomanip>

using namespace std;

//void swap(int* a, int* b)// ポインタ渡し
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

void swap(int& a, int& b)// 参照渡し
{
	int tmp = a;
	a = b;
	b = tmp;
}

void QuickSort(int array[], int left, int right)
{
	int i = left + 1;		// 基準値より大きい値の位置
	int k = right;			// 基準値より小さい値の位置

	// 中央を超えるまで　中央 ＝ 悪魔で基準値が来るであろう位置
	while (i < k)
	{
		// 基準値より大きい値の探索
		// 中央より左のグループで　基準値より小さい　かつ　右端を超えていない　間
		while (array[i] < array[left] && i < right)
		{
			i += 1;
		}
		// 基準値より小さい値の探索
		// 中央より右のグループで　基準値より大きい　かつ　左端を超えていない　間
		while (array[k] >= array[left] && k > left)
		{
			k -= 1;
		}

		// 探索した数値を交換する
		if (i < k)
			swap(array[i], array[k]);
	}

	// 基準値と中央で余った小さいほうを交換する　ここで基準値が中央に来る
	if (array[left] > array[k])
		swap(array[left], array[k]);

	// 基準値より小さいグループが並び替え終わっていない
	if (left < k - 1)
		QuickSort(array, left, k - 1);

	// 基準値より大きいグループが並び替え終わっていない
	if (k + 1 < right)
		QuickSort(array, k + 1, right);
}

int main()
{
	static const int n = 5;
	int array[n] = { 3, 5, 19, 1, 2 };
	int left = 0;
	int right = n - 1;

	QuickSort(array, left, right);

	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << array[i];
	}
	cout << endl;

	// 入力待ち
	cin.get();
}