#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubble_sort_vector(vector<int> arr) {
    int n = arr.size();

    for (int times = 1; times <= n-1; times++) {
        for (int j = 0; j <= (n - times - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    return arr;
}

vector<int> insertion_sort_vector(vector<int> vec) {
    int n = vec.size();

    for(int i = 1; i < n; i++) {
        int current = vec[i];
        int prev = i - 1;

        // Loop to find the right index where the element current should be.
        while(prev >= 0 && vec[prev] > current) {
            vec[prev + 1] = vec[prev];
            prev--;
        }

        vec[prev + 1] = current;
    }

    return vec;
}

vector<int> selection_sort_vector(vector<int> vec) {
    int n = vec.size();

    for (int i = 0; i <= n - 2; i++) {
        // int current = vec[i];
        int min_position = i;

        // Find the minimum element.
        for (int j = i; j < n; j++) {
            if (vec[j] < vec[min_position]) {
                min_position = j;
            }
        }

        swap(vec[min_position], vec[i]);
    }

    return vec;
}

vector<int> selection_sort_vector_flag(vector<int> vec, bool flag) {
    int n = vec.size();

    for (int i = 0; i <= n - 2; i++) {
        int min_position = i;

        // Find the minimum element.
        for (int j = i; j < n; j++) {
            if (vec[j] < vec[min_position]) {
                min_position = j;
            }
        }

        swap(vec[min_position], vec[i]);
    }

    if (!flag) {
        reverse(vec.begin(), vec.end());
    }

    return vec;
}

vector<int> counting_sort_vector(vector<int> vec) {
    int n = vec.size();
    int largest = INT_MIN;

    // Largest element
    for (int i = 0; i < n; i++) {
        largest = max(largest, vec[i]);
    }

    // Create a frequency vector.
    // Size is value of largest + 1, all elements initialised to 0.
    vector<int> freq(largest + 1, 0);

    // Update the frequency vector.
    for (int x : vec) {
        freq[x]++;
    }

    // Put back the elements from freq vector into original vector.
    int j = 0;
    for (int i = 0; i <= largest; i++) {
        while (freq[i] > 0) {
            vec[j] = i;
            freq[i]--;
            j++;
        }
    }

    return vec;
}

int main() {
    vector<int> my_vector = {5, 1, 4, 1, 3, 5, 2, 1};
    vector<int> sorted_vector = selection_sort_vector_flag(my_vector, false);

    for (auto x : sorted_vector) {
        cout << x << " ";
    }
}
