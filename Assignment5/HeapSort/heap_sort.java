import java.util.*;

public class heap_sort {

    static void heapify(int[] arr, int n, int i) {

        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

     
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

   
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

       
        if (largest != i) {

            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

           
            heapify(arr, n, largest);
        }
    }

    static void heapSort(int[] arr) {

        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    static int[] randomArray(int n) {

        Random random = new Random();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = random.nextInt(100000);
        }

        return arr;
    }

    static int[] ascendingArray(int n) {

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        return arr;
    }

    static int[] descendingArray(int n) {

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }

        return arr;
    }

    static boolean isSorted(int[] arr) {

        for (int i = 1; i < arr.length; i++) {

            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }

        return true;
    }

    static long measureTime(int[] arr) {

        long start = System.nanoTime();

        heapSort(arr);

        long end = System.nanoTime();

        return end - start;
    }

    public static void main(String[] args) {

        int[] arr = {4, 10, 3, 5, 1};

        System.out.println("Before sorting:");
        System.out.println(Arrays.toString(arr));

        heapSort(arr);

        System.out.println("After sorting:");
        System.out.println(Arrays.toString(arr));

        System.out.println("Sorted correctly: " + isSorted(arr));

        System.out.println("\nRuntime Analysis:");

        int[] sizes = {1000, 5000, 10000, 50000, 100000};

        System.out.println(
                "Size\tRandom(ns)\tAscending(ns)\tDescending(ns)"
        );

        for (int size : sizes) {

            int[] random = randomArray(size);
            int[] ascending = ascendingArray(size);
            int[] descending = descendingArray(size);

            long randomTime = measureTime(random);
            long ascendingTime = measureTime(ascending);
            long descendingTime = measureTime(descending);

            System.out.println(
                    size + "\t" +
                    randomTime + "\t\t" +
                    ascendingTime + "\t\t" +
                    descendingTime
            );
        }
    }
}
