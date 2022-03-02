// #include <bits/stdc++.h>
// #include <vector>
// #define HEAP_SIZE 100
// class Heap
// {
// private:
//     int data[HEAP_SIZE];
//     int n; // current number of
// public:
//     Heap()
//     {
//         n = 0;
//     }
//     Heap(int num[],int length)
//     {
//         heapify(num,length,i);
//     }
// void swap(int *a, int *b)
// {
//   int temp = *b;
//   *b = *a;
//   *a = temp;
// }
// void heapify(int data[], int size, int i)
// {
//   int largest = i;
//   int l = 2 * i + 1;
//   int r = 2 * i + 2;
//   if (l < size && data[l] > data[largest])
//     largest = l;
//   if (r < size && data[r] > data[largest])
//     largest = r;

//   if (largest != i)
//   {
//     swap(&data[i], &data[largest]);
//     heapify(data,n, largest);
//   }
// }
//     // void HeapInsert(int item)
//     // {
//     //     n = n + 1;
//     //     int ptr = n;
//     //     while (ptr < 1)
//     //     {
//     //         int par = ptr / 2;
//     //         if (item <= data[par])
//     //         {
//     //             data[ptr] = item;
//     //             return;
//     //         }
//     //         data[ptr] = data[par];
//     //         ptr = par;
//     //     }
//     //     data[0] = item;
//     //     return;
//     // }

// };
// using namespace std;
// int main()
// {
//     Heap h1;
//     h1.HeapInsert(23);
//     return 0;
// }