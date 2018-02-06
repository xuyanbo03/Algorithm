public class HeapSortData {
    private int[] numbers;
    public int heapIndex;//[heapIndex...N)是有序的

    public HeapSortData(int N, int randomBound) {
        numbers = new int[N];
        heapIndex=N;

        for (int i = 0; i < N; i++) {
            numbers[i] = (int) (Math.random() * randomBound) + 1;
        }
    }

    public int N() {
        return numbers.length;
    }

    public int get(int index) {
        if (index < 0 || index >= numbers.length) {
            throw new IllegalArgumentException("Error");
        }
        return numbers[index];
    }

    public void swap(int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
