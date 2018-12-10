#include "sorting.h"

template<class LE>
Sorting<LE>::Sorting(LE *original) {
	list = original;

	num_compare = 0;
}

template<class LE>
Sorting<LE>::~Sorting() {

}

template<class LE>
int Sorting<LE>::insertion_sort(int n) {
	//in-lab, pre-lab
	//�ε��� 1,2 ��
	//�ε��� 3 ��
	//�ε��� 4 ��
	//�ε��� 5 ��..
	//�ε��� max_size ��

	int tmp; //change position
	/*for (int i = 1; i < n; i++){
	for (int j = 0; j < i; j++){
	if (list[j] >= list[i]) {
	tmp = list[i];

	for (int k = i; k > j; k--) {
	list[k] = list[k - 1];
	}
	list[j] = tmp;
	}
	break;
	}

	}*/


	/*for (int i = 0; i < n - 1; i++) {
		if(i>=1)
		print_list(0, MAX_SIZE - 1);

		for (int j = i + 1; j >= 0; j--) {
		
			if (list[j - 1] > list[j]) {

				swap(list[j - 1], list[j]);
				break;
			}
			else {
				
				continue;
			}
			
		}
		
	}*/
	int j = 0;
	for (int i = 0; i < n-1; i++) { //q���� list[i]��
	tmp = list[i+1]; //tmp�� list[i] ����

	if(i>=1)
	print_list(0, MAX_SIZE - 1);

	for ( j = i; j > -1; j--) { //0���� i-1���� �� ��

	if (list[j] > tmp) { //ũ�� ��
		num_compare++;
	list[j + 1] = list[j]; //�ϳ��� �о���
	}
	else 
	break; //��
	
	}

	list[j + 1] = tmp; //j�ڿ� tmp�־��ش�!
	}
	
	return num_compare;
}


template<class LE>
int Sorting<LE>::quick_sort(int left, int right) {
	if (left < right) {
		int q = quickPartition(list, left, right);
		quick_sort(left, q - 1);
		quick_sort(q + 1, right);
	}

	return num_compare;
}


template<class LE>
int Sorting<LE>::merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(list, left, mid, right);
	}
	return num_compare;
}

template<class LE>
void Sorting<LE>::copy_list(LE newList[], int n, int compare) {
	num_compare = compare;

	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = newList[i];

}

template<class LE>
void Sorting<LE>::print_list(int left, int right) {
	for (int i = left; i < right + 1; i++)
		cout << "|" << list[i] << "|";
	cout << endl;
}

template<class LE>
void Sorting<LE>::merge(LE keyList[], int left, int mid, int right) {
	int i, j, k = left, l;

	static LE sorted[MAX_SIZE];
	//���� ���ĵ� A�� �պ�
	for (i = left, j = mid + 1; i <= mid && j <= right; ) {
		sorted[k++] = (keyList[i] <= keyList[j]) ? keyList[i++] : keyList[j++];
		num_compare++;
	}
	//���ʿ� ���� �ִ� ���ڵ��� �ϰ� ����
	if (i > mid)
		for (l = j; l <= right; l++, k++) {
			sorted[k] = keyList[l];
		}
	else
		for (l = i; l <= mid; l++, k++) {
			sorted[k] = keyList[l];
		}
	//�迭 sorted[] �� ����Ʈ�� �迭 keyList�� �纹��
	for (l = left; l <= right; l++) {
		keyList[l] = sorted[l];
	}
	print_list(0, MAX_SIZE - 1);
}

template<class LE>
int Sorting<LE>::quickPartition(LE keyList[], int left, int right) {
	int low = left;
	int high = right + 1;
	int pivot = keyList[left];
	do {
		num_compare++;
		do {
			low++;
		} while (low <= right && keyList[low] < pivot);
		do {
			high--;
		} while (high >= left && keyList[high] > pivot);
		if (low < high) {
			LE tmp = keyList[low];
			keyList[low] = keyList[high];
			keyList[high] = tmp;
		}
	} while (low < high);

	LE tmp = keyList[left];
	keyList[left] = keyList[high];
	keyList[high] = tmp;
	print_list(0, MAX_SIZE - 1);
	return high;
}