// DataStructuresAndAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
int arr[] = { 100, 2, 6, 5, 3, 8, 7, 10, 95, 9, 5 };
const int arrSize = sizeof(arr) / sizeof(arr[0]);

void copyArray(int arr1[], int arr2[], int sizeArr);
void displaySortedArray(int arr[], int size, std::string typeOfArray);

void BubbleSort(int arr[], int size);

void SelectionSort(int arr[], int size);

void InsertionSort(int arr[], int size);

void showBubbleSort(int arr[], int bubbSort[], const int arrSize);
void showSelectionSort(int arr[], int selSort[], const int arrSize);
void showInsertionSort(int arr[], int selSort[], const int arrSize);
void showQuickSort(int arr[], int quickSort[], const int arrSize);

template <size_t N>
void showCountingSort(int(&arr)[N]);

template <size_t N>
void showRadixSort(int(&arr)[N]);

template <size_t N>
void showMergeSort(int(&arr)[N]);

template <size_t N>
void showBinarySearch(int(&arr)[N]);

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr){}
    Node<T>* getHead() { return head; }
    Node<T>* getTail() {return tail;}

    void addFirst(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            tail->prev = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void addLast(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            tail->prev = newNode;
            return;
        }

        Node<T>* currentNode = tail;
        currentNode->prev = newNode;
        newNode->next = tail;

    }

};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr){ }
    Node<T>* getHead() { return head; }
    void addFirst(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) 
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

    }
    void addLast(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T>* currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;

    }

    void removeFirst()
    {
        Node<T>* currentNode = head;
        head = head->next;
        delete currentNode;
    }

    void removeLast()
    {
        if (head == nullptr) return;

        Node<T>* currentNode = head;

        while (currentNode->next->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = nullptr;
        delete currentNode->next;
        
    }

    void insert(T value, int index)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        if (index == 0) 
        {
            addFirst(value);
            return;
        }

        Node<T>* currentNode = head;
        int i = 0;
        while (currentNode->next != nullptr)
        {
            if (i == index - 1) 
            {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                break;
            }

            ++i;
            currentNode = currentNode->next;
        }
    }

    void removeAt(int index)
    {
        if (head == nullptr) return;

        if (head->next == nullptr)
        {
            head->next;
            head = nullptr;
            //delete head->next;
            return;
        }

        Node<T>* currentNode = head;
        int i = 0;
        while (currentNode->next != nullptr)
        {
            if (i == index - 1)
            {
                currentNode->next = currentNode->next->next;
                break;
            }

            ++i;
            currentNode = currentNode->next;
        }

    }

    void displayLinkedList()

    {
        using namespace std;
        Node<T>* currentNode = head;
        if (currentNode != nullptr) {
            cout << "{";
            while (currentNode->next != nullptr)
            {

                cout << currentNode->data << ", ";
                currentNode = currentNode->next;
            }
            cout << currentNode->data << "}" << endl;
        }
        else
            cout << "Empty list" << endl;

    }
};

template<typename T>
class StackL
{
private:
    struct Node
    {
        Node* next;
        T data;

        Node(const T& value) : data(value), next(nullptr) {};
    };
    
    Node* topNode;
    size_t size;
public:
    
    StackL() : topNode(nullptr), size(0) {}
    ~StackL()
    {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        ++size;
    }

    void pop()
    {
        topNode = topNode->next;
        --size;
    }

    bool isEmpty()
    {
        if (size != 0)
            return true;
        return false;
    }

    void displayStack()
    {
        using namespace std;
        Node* currentNode = topNode;
        if (currentNode != nullptr) {
            cout << "{";
            while (currentNode->next != nullptr)
            {

                cout << currentNode->data << ", ";
                currentNode = currentNode->next;
            }
            cout << currentNode->data << "}" << endl;
        }
        else
            cout << "Empty list" << endl;
    }
};

template<typename T>
class Queue
{
private:
    struct Node
    {
        Node* next;
        T data;

        Node(const T& value): data(value), next(nullptr){}
    };
    Node* front;
    Node* rear;
    size_t size;
    void display(Node* currentNode)
    {
        
        if (currentNode->next == nullptr)
            return;
        std::cout << currentNode->data << ", ";
        display(currentNode->next);   
    }
public:
    Queue(): front(nullptr), rear(nullptr), size(0) {}
    ~Queue()
    {
        Node* currentNode = rear;
        Node* previousNode = nullptr;
        while (currentNode->next != nullptr)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            delete previousNode;
        }
        
    }

    void enqueue(const T& value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            // newNode->next = front;
            front = newNode;
            rear = newNode;
            ++size;
            return;
        }
        Node* currentNode = rear;
        currentNode->next = newNode;
        rear = newNode;
        ++size;
    }

    void dequeue()
    {
        if (isEmpty()) return;
        if (size == 1)
        {
            front = nullptr;
            rear = nullptr;
            return;
        }
        Node* currentNode = front;
        front = currentNode->next;
        delete currentNode;
        --size;

    }

    bool isEmpty()
    {
        return size == 0;
    }

    void displayQueue()
    {
        // { 100, 2, 6, 5, 3, 8, 7, 10, 95, 9, 5 };
        
        using namespace std;

        cout << "{";
        display(front);
        cout << rear->data;
        cout << "} " << endl;;


       /* if (currentNode != nullptr) {
            cout << "{";
            while (currentNode->next != nullptr)
            {

                cout << currentNode->data << ", ";
                currentNode = currentNode->next;
            }
            cout << currentNode->data << "}" << endl;
        }
        else
            cout << "Empty list" << endl;*/
    }

};

template <typename T>
class AVLTree
{
private:
    struct TreeNode
    {
        TreeNode* left;
        TreeNode* right;
        T data;
        int height;
        TreeNode(const T& value) : left(nullptr), right(nullptr), data(value), height(1){}
    };
    TreeNode* root;
    int treeSize;
    int getHeight(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    int getBalance(TreeNode* node)
    {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode* rotateRight(TreeNode* node)
    {
        TreeNode* x = node->left;
        TreeNode* z = x->right;

        node->left = z;
        x->right = node;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        return x;

    }

    TreeNode* rotateLeft(TreeNode* node)
    {
        TreeNode* y = node->right;
        TreeNode* z = y->left;

        y->left = node;
        node->right = z;
        

        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        return y;
    }

    TreeNode* insertRecursive(TreeNode* root, T value)
    {
        if (root == nullptr) return new TreeNode(value);

        if (root->data > value)
            root->left = insertRecursive(root->left, value);
        else if (root->data < value)
            root->right = insertRecursive(root->right, value);
        else
            return root;

        // update the height of the tree
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && value < root->left->data) {
            return rotateRight(root);
        }
        if (balance < -1 && value > root->right->data) {
            return rotateLeft(root);
        }
        if (balance > 1 && value > root->left->data) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && value < root->right->data) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
public:
    AVLTree() : root(nullptr), treeSize(0) {}
    ~AVLTree(){}
    // Method to insert a value into the AVL tree
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }

    // Method to print the AVL tree using inorder traversal
    void print() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

};

int main()
{
    /* std::cout << "Hello World!\n";

     std::cout << "The unsorted list of numbers: ";
     for (auto i : arr) {
         std::cout << i << ", ";
     }
     std::cout << std::endl;

     int bubbSort[arrSize];
     showBubbleSort(arr, bubbSort, arrSize);


     int selSort[arrSize];
     showSelectionSort(arr, selSort, arrSize);

     int insertSort[arrSize];
     showInsertionSort(arr, insertSort, arrSize);

     int quickSort[arrSize];
     showQuickSort(arr, quickSort, arrSize);

     int countArr[] = { 4, 3, 1, 2, 0 ,5 , 0,5 };
     showCountingSort(arr);

     int radArr[] = { 1024, 304, 304,215, 532 ,5, 65};
     showRadixSort(arr);

     showMergeSort(arr);

     showBinarySearch(quickSort);*/

     // Create Singly Linked List
    LinkedList<int> intLinkedList;

    //// Populate Linked List
    //for (int i = 0; i < 0; ++i)
    //{
    //    intLinkedList.addLast(arr[i]);
    //}

    ////show Linked List
    //intLinkedList.displayLinkedList();

    //// addFirst value;
    //intLinkedList.addFirst(11);

    ////show Linked List
    //intLinkedList.displayLinkedList();

    //// addLast value;
    //intLinkedList.addLast(13);

    ////show Linked List
    //intLinkedList.displayLinkedList();

    //// insert value;
    //intLinkedList.insert(12, 1);

    ////show Linked List
    //intLinkedList.displayLinkedList();

    //intLinkedList.removeFirst();

    //intLinkedList.displayLinkedList();

    //intLinkedList.removeLast();

    //intLinkedList.displayLinkedList();

    //// remove value;
    //intLinkedList.removeAt(0);

    ////show Linked List
    //intLinkedList.displayLinkedList();

    //// Create Doubly Linked List
    //LinkedList<int> intDoublyLinkedList;

    //// Populate Doubly Linked List
    //for (int i = 0; i < arrSize; ++i)
    //{
    //    intDoublyLinkedList.addLast(arr[i]);
    //}

    //std::cout << "Showing Doubly Linked list: " << std::endl;

    ////show Doubly Linked List
    //intDoublyLinkedList.displayLinkedList();

    //// addFirst value;
    //intDoublyLinkedList.addFirst(11);

    ////show Linked List
    //intDoublyLinkedList.displayLinkedList();

    //// addLast value;
    //intDoublyLinkedList.addLast(13);

    ////show Linked List
    //intDoublyLinkedList.displayLinkedList();


    //StackL<int> stack;
    //// Copy values into stack
    //for (int i = 0; i < arrSize; ++i)
    //{
    //    stack.push(arr[i]);
    //}

    //stack.displayStack();

    //stack.pop();

    //stack.displayStack();

    //Queue<int> queue;
    //// Copy values into stack
    //for (int i = 0; i < arrSize; ++i)
    //{
    //    queue.enqueue(arr[i]);
    //}

    //queue.displayQueue();

    //queue.dequeue();

    //queue.displayQueue();

    /*stack.pop();

    stack.displayStack();*/

    AVLTree<int> avlTree;
    for (int i = 0; i < arrSize; ++i)
    {
        avlTree.insert(arr[i]);
    }
    avlTree.print();
}

void displaySortedArray(int arr[], int size, std::string typeOfArray)
{
    std::cout << "The sorted list of numbers using " << typeOfArray << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void copyArray(int arr1[], int arr2[], int sizeArr)
{
    for (int i = 0;i < sizeArr; ++i) {
        arr2[i] = arr1[i];
    }
}

void BubbleSort(int arr[], int size) {
    // { 2, 6, 5, 3, 8, 7, 10, 95, 9, 5};

    // Outer loop that controls innerloop
    bool swapped = false;
    for (int i = 0; i < size; ++i) {
        // Inner loop
        for (int j = 0; j < size - 1 - i; ++j) {
            // Swap if adjacent value is smaller
            if (arr[j] > arr[j + 1])
            {
                //Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void showBubbleSort(int arr[], int bubbSort[], const int arrSize)
{

    // Copy values
    copyArray(arr, bubbSort, arrSize);

    BubbleSort(bubbSort, arrSize);
    displaySortedArray(bubbSort, arrSize, "Bubble Sort");
}

void SelectionSort(int arr[], int size)
{
    // { 2, 6, 5, 3, 8, 7, 10, 95, 9, 5};


    int index = 0;      // Index for the swapped value
    for (int i = 0; i < size; ++i)
    {
        int min = arr[i];
        // Searches for the lowest value
        for (int j = i + 1; j < size; ++j)
        {
            // compares the remaining values to find the smallest value
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        // Swap values when an unsorted value is going to be excluded
        // in the array that still need to be evaluated.
        if (index != i)
        {
            arr[index] = arr[i];
            arr[i] = min;
        }
    }

}
void showSelectionSort(int arr[], int selSort[], const int arrSize)
{
    // Copy values
    copyArray(arr, selSort, arrSize);

    SelectionSort(selSort, arrSize);
    displaySortedArray(selSort, arrSize, "Selection Sort");
}

void InsertionSort(int arr[], int size)
{
    // {100, 2, 6, 5, 3, 8, 7, 10, 95, 9, 5};

    // Outer loop that picks the value to be sorted.
    // In this case the first value of the unsorted array is picked.
    int j;
    for (int i = 1; i < size; ++i)
    {
        j = i;
        // Inner loop
        while (j > 0 && arr[j - 1] > arr[j])
        {
            // Swap
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            // unsorted sub-array size
            --j;
        }

    }
}

void showInsertionSort(int arr[], int insertSort[], const int arrSize)
{
    // Copy values
    copyArray(arr, insertSort, arrSize);

    InsertionSort(insertSort, arrSize);
    displaySortedArray(insertSort, arrSize, "Insertion Sort");
}

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];

    // Temporary pivot
    int i = lo - 1;

    for (int j = lo; j < hi; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;

            // Swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i = i + 1;

    // Swap the pivot with the last value
    int temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;


    return i;
}

void QuickSort(int arr[], int lo, int hi)
{
    if (lo >= hi || lo < 0)
        return;
    int p = partition(arr, lo, hi);

    QuickSort(arr, lo, p - 1);
    QuickSort(arr, p + 1, hi);
}



void showQuickSort(int arr[], int quickSort[], const int arrSize)
{
    copyArray(arr, quickSort, arrSize);
    QuickSort(quickSort, 0, arrSize - 1);
    displaySortedArray(quickSort, arrSize, "Quick Sort");
}

template <size_t N>
int* CountingSort(int(&arr)[N], int maxValue)
{
    int arrSize = N;
    // Initialize count array
    int* counter = new int[maxValue];
    int* output = new int[arrSize];

    // Initialize with zeros
    for (int i = 0; i < maxValue; ++i)
    {
        counter[i] = 0;
    }


    for (int j = 0; j < arrSize; ++j)
        ++counter[arr[j]];


    // Get running sum
    for (int i = 1; i < maxValue; ++i)
    {
        counter[i] += counter[i - 1];
    }

    // Build output array
    for (int j = arrSize - 1; j >= 0; --j)
    {
        output[counter[arr[j]] - 1] = arr[j];
        --counter[arr[j]];
    }
    delete[] counter;

    return output;

}

template <size_t N>
void showCountingSort(int(&arr)[N])
{
    int max = 0;
    int arrSize = N;
    for (int i = 0; i < arrSize; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    displaySortedArray(CountingSort(arr, max + 1), arrSize, "Counting Sort");
}

void CountingSortR(int arr[], int size, int exp)
{  
    // {100, 2, 6, 5, 3, 8, 7, 10, 95, 9, 5};
    int counter[10] = { 0 };
    int* output = new int[size];
    // Count frequency
    for (int i = 0; i < size; ++i)
        ++counter[(arr[i] / exp) % 10];

    // Cumulative counter
    for (int j = 1; j < 10; ++j)
        counter[j] += counter[j - 1];

    // Build array
    for (int i = size - 1; i >= 0; --i)
    {
        int index = counter[(arr[i] / exp) % 10] - 1;
        output[index] = arr[i];
        --counter[(arr[i] / exp) % 10];
    }
    

    for (int i = 0; i < size; ++i)
    {
        arr[i] = output[i];
    }

    delete[] output;

}

int* RadixSort(int arr[], int size, int maxVal)
{
    int* output = new int[size];
    copyArray(arr, output, size);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        CountingSortR(output,size,exp);
    return output;
}

template <size_t N>
void showRadixSort(int(&arr)[N])
{
    int max = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    
    
    displaySortedArray(RadixSort(arr, N, max), N, "Radix Sort");
}

void Merge(int leftArr[], int lSize, int rightArr[], int rSize, int arr[], int size)
{
    int i = 0, r = 0, l = 0;
    for (; (l < lSize) && (r < rSize); ++i)
    {
        if (leftArr[l] < rightArr[r])
        {
            arr[i] = leftArr[l];
            ++l;
        }
        else if (rightArr[r] < leftArr[l])
        {
            arr[i] = rightArr[r];
            ++r;
        }
        else
        {
            arr[i] = leftArr[l];
            ++l;
            ++i;
            arr[i] = rightArr[r];
            ++r;
        }
    }

    if (l < lSize)
    {
        for (;l < lSize; ++l)
        {
            arr[i] = leftArr[l];
            ++i;
        }
    }
    if (r < rSize)
    {
        for (;r < rSize; ++r)
        {
            arr[i] = rightArr[r];
            ++i;
        }
    }
}

void MergeSort(int arr[], int size)
{
    if (size <= 1)
        return;
    
    int middle = size / 2;
    int* leftArr = new int[middle];
    int* rightArr = new int[size - middle];

    int i = 0, j = 0;

    for (; i < size; ++i)
    {
        if (i < middle)
            leftArr[i] = arr[i];
        else
        {
            rightArr[j] = arr[i];
            ++j;
        }
    }
    MergeSort(leftArr, middle);
    MergeSort(rightArr, size - middle);
    Merge(leftArr, middle, rightArr, size - middle, arr, size);

    delete[] leftArr;
    delete[] rightArr;
}

template <size_t N>
void showMergeSort(int(&arr)[N])
{
    int mergeSort[N];
    copyArray(arr, mergeSort, N);
    MergeSort(mergeSort, N);
    displaySortedArray(mergeSort, N, "Merge Sort");
}

void displayValue(int arr[], int size, int index, int value)
{
    using namespace std;
    if (index != -1) 
    {
        cout << "In the array list ";
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << ", ";
        }

        cout << " we found the value " << value << " at index " << index;
    }
    else
    {
        cout << "In the array list ";
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << ", ";
        }

        cout << "the value " << value << " was not found.";
    }
}

int BinarySearch(int arr[], int size, int value)
{
    int middle = size / 2;
    int left = 0, right = size;
    
    while (arr[middle] != value)
    {
        if (left == middle && middle == right - 1)
            return -1;
        else if (value < arr[middle])
        {
            right = middle;
            middle = (left + right) / 2;
        }
        else if (value > arr[middle])
        {
            left = middle + 1;
            middle = (left + right) / 2;
        }
        
    }
    return middle;
     
}

template <size_t N>
void showBinarySearch(int(&arr)[N])
{
    int value = 11;
    int index = BinarySearch(arr, N, value);
    displayValue(arr, N , index, value);
}
