import java.util.*;

public class Sort {

    /* Disponibile in libreria java */
    public void quickSortDefault(int[] array) {
        Arrays.sort(array);
    }

    /* Merge sort */

    private void merge(int[] array, int p, int q, int r) {
        int n_l = q - p + 1;
        int n_r = r - q;

        int[] left = new int[n_l];
        int[] right = new int[n_r];

        for (int i = 0; i < left.length; i++) {
            left[i] = array[p + i];
        }

        for (int i = 0; i < right.length; i++) {
            right[i] = array[q + i + 1];
        }
        int i, j, k;
        for (i = 0, j = 0, k = p; j < right.length && i < left.length; k++) {
            if (left[i] <= right[j])
                array[k] = left[i++];
            else
                array[k] = right[j++];
        }

        while (i < left.length)
            array[k++] = left[i++];
        while (j < right.length)
            array[k++] = right[j++];
    }

    private void mergeSort_h(int[] array, int p, int r) {
        if (p >= r)
            return;
        int q = (p + r) / 2;
        mergeSort_h(array, p, q);
        mergeSort_h(array, q + 1, r);

        merge(array, p, q, r);
    }

    public void mergeSort(int[] array) {
        if (array.length > 1)
            mergeSort_h(array, 0, array.length - 1);
    }

    /* Head Sort */

    private int heap_left(int i) {
        return (2 * i);
    }

    private int heap_right(int i) {
        return (2 * i + 1);
    }

    private void heapify(int[] array, int i, int n) {
        if (i >= n)
            return;

        int left = heap_left(i);
        int right = heap_right(i);

        int max = i;
        if (left < n && array[left] > array[max])
            max = left;
        if (right < n && array[right] > array[max])
            max = right;

        if (max != i) {
            int tmp = array[i];
            array[i] = array[max];
            array[max] = tmp;
            heapify(array, max, n);
        }
    }

    private void buildHeap(int[] array) {
        for (int i = (array.length - 1) / 2; i >= 0; i--) {
            heapify(array, i, array.length);
        }
    }

    private void swap_arr(int[] array, int i, int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public void heapSort(int[] array) {
        buildHeap(array);
        int n = array.length;

        for (int i = n - 1; i >= 1; i--) {
            swap_arr(array, 0, i);
            heapify(array, 0, --n);
        }
    }

    /* insertionSort */

    public void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int j, key = array[i];
            for (j = i - 1; j >= 0 && array[j] > key; j--)
                array[j + 1] = array[j];
            array[j + 1] = key;
        }
    }

    /* selectionSort */

    public void selectionSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int min = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[min])
                    min = j;
            }
            swap_arr(array, i, min);
        }
    }

    /* quickSort */

    private int partition(int[] array, int p, int r) {
        int key = array[r];

        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (array[j] <= key) {
                i++;
                swap_arr(array, i, j);
            }
        }
        swap_arr(array, i + 1, r);
        return (i + 1);
    }

    public void quickSort_h(int[] array, int p, int r) {
        if (p < r) {
            int pivot = partition(array, p, r);
            quickSort_h(array, p, pivot - 1);
            quickSort_h(array, pivot + 1, r);
        }
    }

    public void quickSort(int[] array) {
        quickSort_h(array, 0, array.length - 1);
        return;
    }

    /* radixSort */

    public void countingSort(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max)
                max = array[i];
        }

        int b[] = new int[array.length];
        int c[] = new int[max + 1];

        for (int i = 0; i <= max; i++)
            c[i] = 0;

        for (int i = 0; i < array.length; i++)
            c[array[i]]++;

        for (int i = 1; i <= max; i++) {
            c[i] += c[i - 1];
        }

        for (int i = array.length - 1; i >= 0; i--) {
            b[c[array[i]] - 1] = array[i];
            c[array[i]]--;
        }

        for (int i = 0; i < array.length; i++)
            array[i] = b[i];
    }

    public void radixSort(int[] array) {
        
    }

    public void bucketSort(int[] array) {}
}
