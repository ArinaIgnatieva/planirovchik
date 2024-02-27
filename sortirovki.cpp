#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


void swap(int &a, int &b) { //функция для смены элементов местами (используется в Quick и Bubble Sort)
    int tmp = a;
    a  = b;
    b = tmp;
}

void printArray(int arr[], int size) { //функция для вывода массива на экран поэлементно (используется в Bubble и Insertion Sort)
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



/*Quick Sort*/

int partition(std::vector<int> &arr, int first, int last) { //разделение массива и возврат индекса pivot элемента, на вход принимается вектор по ссылке и его первый и последний элементы
    int pivot = arr[last]; //выбираем pivot элементом последний элемент массива
    int i = first-1; //создаем переменную, хранящую индекс элемента (будет использоваться как счетчик)
    for (int j = first; j < last; j++) { //пока счетчик j меньше индекс последнего элемента
        if (arr[j] < pivot) { //и выполняется условие
            i++; //увеличиваем i на 1
            swap(arr[i], arr[j]); //меняем местами элементы, расставляя в правильном порядке
        }
    }
    swap(arr[i+1], arr[last]); //после выхода из цикла перемещаем pivot элемент с последнего места на правильное с индексом i+1
    return i+1; //функция возвращает индекс pivot элемента
}

int randPivot(std::vector<int> &arr, int first, int last) { //выбор рандомного pivot элемента
    srand(time(NULL)); //используем генератор случайных чисел
    int random = first + rand() % (last-first); //присваиваем переменной random индекс рандомного элемента из массива
    swap(arr[random], arr[last]); //меняем выбранный рандомный элемент местами с последним элементом массива
    return partition(arr, first, last); //вызываем функцию, где рандомно выбранный pivot стоит на последнем месте, возвращаем значение этой функции
}

void quickSort(std::vector<int> &arr, int first, int last) {//реализация QuickSort
    if (first < last) { //если выполняется условие, переменной pivot присваиваем результат выполнения randPivot
        int pivotInd = randPivot(arr, first, last);
        quickSort(arr, first, pivotInd-1); //расставляем элементы слева и справа от pivot элемента
        quickSort(arr, pivotInd+1, last);
    }
}

void printVector(std::vector <int> &arr, int size){ //вывод вектора на экран поэлементно
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



/*Bubble Sort*/

void bubbleSort(int arr[], int n) { //реализация BubbleSort. на вход принимается копия массива и его размер
    for (int i = 0; i < n-1; i++) { // количество итераций - до предпоследнего элемента
        for (int j = 0; j < n-i-1; j++) { //в каждой итерации будет еще n-i-1 итераций
            if (arr[j] > arr[j+1]) { //сравниваем попарно соседние элементы массива, если условие выполняется,
                swap(arr[j], arr[j+1]); //то вызываем функцию swap2, которая меняет их местами
            }
        }
    }
}



/*Insertion Sort*/

void insertionSort(int arr[], int n) { //реализация InsertionSort, на взод принимается копия массива и его размер
    for (int i = 1; i < n; i++) { //итерации начинаются со второго элемента с индексом 1, т. к. первый элемент считается отсортированным и расставляем остальные относительно него
        int tmp = arr[i]; //создаем временную переменную, хранящую значение элемента массива
        int j = i - 1; //создаем еще одну переменную, хранящую индекс предыдущего элемента
        
        while (j >= 0 && arr[j] > tmp) { //пока индекс предыдущего элемента больше либо равен нулю и его значение больше следующего эл-та
            arr[j+1] = arr[j]; //последующему элементу присваивается значение предыдущего
            j--; //номер индекса уменьшается на 1
        }
        arr[j+1] = tmp; //предыдущему элемнту присваивается значение последующего
    }
}



int main() {
    
    /*Quick Sort*/
    
    //принимаем размер массива с консоли
    std::cout << "введите размер массива: " << std::endl;
    int size = 0;
    std::cin >> size;
    
    //принимаем элементы массива с консоли
    std::vector<int> arr(size);
    std::cout << "введите элементы: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    
    //применяем сортировку QuickSort с помощью функции
    quickSort(arr, 0, size-1);
    
    //выводим на экран отсортированный массив
    std::cout << "отсортированный массив: " << std::endl;
    printVector(arr, size);
    
    
    
    /*Bubble Sort*/
    
    //принимаем размер массива с консоли
    std::cout << "введите размер массива: " << std::endl;
    int size2 = 0;
    std::cin >> size2;
    
    //принимаем элементы массива с консоли
    int arr2[size2];
    std::cout << "введите элементы массива: " << std::endl;
    for (int i = 0; i < size2; i++) {
        std::cin >> arr2[i];
    }
    
    //применяем сортировку BubbleSort
    bubbleSort(arr2, size2);
    
    //выводим на экран отсортированный массив
    std::cout << "отсортированный массив: " << std::endl;
    printArray(arr2, size2);
    
    
    
    /*Insertion Sort*/
    
    //принимаем размер массива с консоли
    std::cout << "введите размер массива: " << std::endl;
    int size3 = 0;
    std::cin >> size3;
    
    //принимаем элементы массива с консоли
    int arr3[size3];
    std::cout << "введите элементы массива: " << std::endl;
    for (int i = 0; i < size3; i++) {
        std::cin >> arr3[i];
    }
    
    //применяем сортировку InsertionSort
    insertionSort(arr3, size3);
    
    //выводим на экранотсортированный массив
    std::cout << "отсортированный массив: " << std::endl;
    printArray(arr3, size3);
    
    return 0;
}
