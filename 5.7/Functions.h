#pragma once
#include <iostream>
#include <math.h>

void out_mass(int*a, int size){
	for (int i = 0; i < size; i++) {
		std::cout << *(a + i) << " ";

	}
	std::cout << std::endl;
}

void sort_by_vstavka(int* a, int size) {
	int change;
	for (int i = 0; i < size; i++) {

		int k;

		for (k = 1; i - k >= 0; k++) {

			if (*(a + i) < *(a + i - k)) {
				continue;
			}
			break;
		}
		k--;
		for (int l = 0; l < (k); l++) {
			int change = *(a + i - l);
			*(a + i - l) = *(a + i - l - 1);
			*(a + i - l - 1) = change;

		}

	}

}

void quick_sort(int* a, int size) {
	int middle = size - 1;
	if (size < 2);
	else {
		middle = size - 1;
		for (int i = 0; i < middle; i++) {
			if (i == middle - 1) {
				if (*(a + i) > * (a + middle)) {
					int ch = *(a + i);
					*(a + i) = *(a + middle);
					*(a + middle) = ch;
					middle--;
					break;
				}
			}
			else {
				if (*(a + i) >= *(a + middle)) {
					int ch = *(a + middle - 1);
					*(a + middle - 1) = *(a + middle);
					*(a + middle) = ch;
					middle--;
					ch = *(a + i);
					*(a + i) = *(a + middle + 1);
					*(a + middle + 1) = ch;
					i--;
				}
			}

		}

		quick_sort(a, middle);
		quick_sort(a + middle + 1, size - middle - 1);


	}


}