#include <iostream>
#include <vector>
using namespace std;

class MaxPQ {
public:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }

    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;

        // Bubble up
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int maximum() {
        return heap[0];
    }

    void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    int extractMax() {
        if (heap.size() < 1) return -1;

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);

        return maxVal;
    }

    void increaseKey(int i, int newKey) {
        if (newKey < heap[i]) return; // invalid

        heap[i] = newKey;

        // Bubble up
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};
