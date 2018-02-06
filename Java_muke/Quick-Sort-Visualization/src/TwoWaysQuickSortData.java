import java.util.Arrays;

public class TwoWaysQuickSortData {
    public enum Type {
        Default,
        NearlyOrdered,
        Identical
    }

    public int[] numbers;
    public int l, r;
    public int curPivot;
    public int curL,curR;
    public boolean[] fixedPivots;

    public TwoWaysQuickSortData(int N, int randomBound, TwoWaysQuickSortData.Type dataType) {
        numbers = new int[N];
        fixedPivots = new boolean[N];

        int lBound = 1;
        int rBound = randomBound;
        if (dataType == TwoWaysQuickSortData.Type.Identical) {
            int avgNumber = (lBound + rBound) / 2;
            lBound = avgNumber;
            rBound = avgNumber;
        }

        for (int i = 0; i < N; i++) {
            numbers[i] = (int) (Math.random() * (rBound - lBound + 1)) + lBound;
            fixedPivots[i] = false;
        }

        if (dataType == TwoWaysQuickSortData.Type.NearlyOrdered) {
            Arrays.sort(numbers);
            int swapTime = (int) (0.01 * N);
            for (int i = 0; i < swapTime; i++) {
                int a = (int) (Math.random() * N);
                int b = (int) (Math.random() * N);
                swap(a, b);
            }
        }
    }

    public TwoWaysQuickSortData(int N, int randomBound) {
        this(N, randomBound, TwoWaysQuickSortData.Type.Default);
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
        if (i < 0 || i >= numbers.length || j < 0 || j >= numbers.length) {
            throw new IllegalArgumentException("Error");
        }
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
