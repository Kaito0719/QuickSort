#include <iostream>
#include <iomanip>

using namespace std;

//void swap(int* a, int* b)// �|�C���^�n��
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

void swap(int& a, int& b)// �Q�Ɠn��
{
	int tmp = a;
	a = b;
	b = tmp;
}

void QuickSort(int array[], int left, int right)
{
	int i = left + 1;		// ��l���傫���l�̈ʒu
	int k = right;			// ��l��菬�����l�̈ʒu

	// �����𒴂���܂Ł@���� �� �����Ŋ�l������ł��낤�ʒu
	while (i < k)
	{
		// ��l���傫���l�̒T��
		// ������荶�̃O���[�v�Ł@��l��菬�����@���@�E�[�𒴂��Ă��Ȃ��@��
		while (array[i] < array[left] && i < right)
		{
			i += 1;
		}
		// ��l��菬�����l�̒T��
		// �������E�̃O���[�v�Ł@��l���傫���@���@���[�𒴂��Ă��Ȃ��@��
		while (array[k] >= array[left] && k > left)
		{
			k -= 1;
		}

		// �T���������l����������
		if (i < k)
			swap(array[i], array[k]);
	}

	// ��l�ƒ����ŗ]�����������ق�����������@�����Ŋ�l�������ɗ���
	if (array[left] > array[k])
		swap(array[left], array[k]);

	// ��l��菬�����O���[�v�����ёւ��I����Ă��Ȃ�
	if (left < k - 1)
		QuickSort(array, left, k - 1);

	// ��l���傫���O���[�v�����ёւ��I����Ă��Ȃ�
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

	// ���͑҂�
	cin.get();
}