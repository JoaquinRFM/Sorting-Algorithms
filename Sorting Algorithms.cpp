#include <iostream>
#include <random>
using namespace std;

void printArray(int nElements, int *numbersArray) {
    for (int i = 0; i < nElements; i++) {
        cout << numbersArray[i] << " ";
    }
    cout << endl;
}

void createArray(int &nElements, int *&numbersArray, int &fillOption, int rMin, int rMax) {
    do {
        cout << "Enter the number of elements: ";
        cin >> nElements;
        if (nElements <= 0) {
            cout << "Enter a value higher than 0" << endl;
        }
    } while (nElements == 0);
    numbersArray = new int[nElements];
    do {
        cout << "Fill by hand (0)\tFill randomly (1)\n";
        cin >> fillOption;
        if (fillOption < 0 || fillOption > 1) {
            cout << "Enter a number between 0 and 1" << endl;
        }
    } while (fillOption < 0 || fillOption > 1);
    switch (fillOption) {
    case 0:
        for (int i = 0; i < nElements; i++) {
            cout << "Enter value for position number " << i + 1 << ": ";
            cin >> numbersArray[i];
        }
        break;
    case 1:
        for (int i = 0; i < nElements; i++) {
            numbersArray[i] = rMin + (rand() % (rMax - rMin + 1));
        }
        break;
    }
}

void sortAndMergeArrays(int *&numberArray, int ini, int mid, int fin) {
    int size1 = mid - ini + 1;
    int size2 = fin - mid;
    int* arraytemp1 = new int[size1];
    int* arraytemp2 = new int[size2]; 
    for (int i = 0; i < size1; i++) {
        arraytemp1[i] = numberArray[ini + i];
    }
    for (int i = 0; i < size2; i++) {
        arraytemp2[i] = numberArray[mid + 1 + i];
    }
    int i = ini, j = 0, k = 0;
    while (j < size1 && k < size2) {
        if (arraytemp1[j] <= arraytemp2[k]) {
            numberArray[i] = arraytemp1[j];
            j++;
        }
        else {
            numberArray[i] = arraytemp2[k];
            k++;
        }
        i++;
    }
    while (j < size1) {
        numberArray[i] = arraytemp1[j];
        j++;
        i++;
    }
    while (k < size2) {
        numberArray[i] = arraytemp2[k];
        k++;
        i++;
    }
    delete arraytemp1;
    delete arraytemp2;
        
}

void mergeSort(int *&numbersArray, int ini, int fin) {
    if (ini < fin) {
        int mid = ((fin - ini) / 2) + ini;
        mergeSort(numbersArray, ini, mid);
        mergeSort(numbersArray, mid + 1, fin);
        sortAndMergeArrays(numbersArray, ini, mid, fin);
    }
};

int main() {
    srand(time(0));
    int nElements, fillOption, currentNumber, rMin = -100, rMax = 100;
	int* numbersArray;
    createArray(nElements, numbersArray, fillOption, rMin, rMax);
    cout << "Original Array:" << endl;
    printArray(nElements, numbersArray);
    mergeSort(numbersArray, 0, nElements - 1);
    cout << "MergeSort Method:" << endl;
    printArray(nElements, numbersArray);

    delete[] numbersArray;
}