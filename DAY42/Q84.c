/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* maxHeap;
    int* minHeap;
    int maxSize, minSize;
    int capacity;
} MedianFinder;

// Create object
MedianFinder* create() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->capacity = 2;

    obj->maxHeap = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minHeap = (int*)malloc(sizeof(int) * obj->capacity);

    obj->maxSize = 0;
    obj->minSize = 0;

    return obj;
}

// Resize
void resize(MedianFinder* obj) {
    obj->capacity *= 2;
    obj->maxHeap = realloc(obj->maxHeap, obj->capacity * sizeof(int));
    obj->minHeap = realloc(obj->minHeap, obj->capacity * sizeof(int));
}

// Max Heap Insert
void maxInsert(MedianFinder* obj, int val) {
    if(obj->maxSize == obj->capacity) resize(obj);

    int i = obj->maxSize++;
    while(i > 0 && obj->maxHeap[(i-1)/2] < val) {
        obj->maxHeap[i] = obj->maxHeap[(i-1)/2];
        i = (i-1)/2;
    }
    obj->maxHeap[i] = val;
}

// Min Heap Insert
void minInsert(MedianFinder* obj, int val) {
    if(obj->minSize == obj->capacity) resize(obj);

    int i = obj->minSize++;
    while(i > 0 && obj->minHeap[(i-1)/2] > val) {
        obj->minHeap[i] = obj->minHeap[(i-1)/2];
        i = (i-1)/2;
    }
    obj->minHeap[i] = val;
}

// Remove from Max Heap
int maxPop(MedianFinder* obj) {
    int top = obj->maxHeap[0];
    int last = obj->maxHeap[--obj->maxSize];

    int i = 0;
    while(i*2+1 < obj->maxSize) {
        int child = i*2+1;
        if(child+1 < obj->maxSize && obj->maxHeap[child+1] > obj->maxHeap[child])
            child++;

        if(last >= obj->maxHeap[child]) break;

        obj->maxHeap[i] = obj->maxHeap[child];
        i = child;
    }
    obj->maxHeap[i] = last;
    return top;
}

// Remove from Min Heap
int minPop(MedianFinder* obj) {
    int top = obj->minHeap[0];
    int last = obj->minHeap[--obj->minSize];

    int i = 0;
    while(i*2+1 < obj->minSize) {
        int child = i*2+1;
        if(child+1 < obj->minSize && obj->minHeap[child+1] < obj->minHeap[child])
            child++;

        if(last <= obj->minHeap[child]) break;

        obj->minHeap[i] = obj->minHeap[child];
        i = child;
    }
    obj->minHeap[i] = last;
    return top;
}

// Add number
void addNum(MedianFinder* obj, int num) {
    if(obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        maxInsert(obj, num);
    } else {
        minInsert(obj, num);
    }

    // Balance
    if(obj->maxSize > obj->minSize + 1) {
        minInsert(obj, maxPop(obj));
    } else if(obj->minSize > obj->maxSize) {
        maxInsert(obj, minPop(obj));
    }
}

// Find median
double findMedian(MedianFinder* obj) {
    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

int main() {
    int n, x;

    MedianFinder* mf = create();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &x);

        addNum(mf, x);

        printf("Current Median: %.2lf\n", findMedian(mf));
    }

    return 0;
}