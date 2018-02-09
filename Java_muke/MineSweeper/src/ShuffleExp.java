public class ShuffleExp {
    private int N;
    private int n, m;

    public ShuffleExp(int N, int n, int m) {
        if (N <= 0) {
            throw new IllegalArgumentException("N > 0");
        }
        if (n < m) {
            throw new IllegalArgumentException("n > m");
        }
        this.N = N;
        this.n = n;
        this.m = m;
    }

    public void run() {
        int arr[] = new int[n];
        int freq[] = new int[n];
        for (int i = 0; i < N; i++) {
            reset(arr);
            shuffle(arr);
            for (int j = 0; j < n; j++) {
                freq[j] += arr[j];
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(i + ":" + (double) freq[i] / N);
        }
    }

    private void reset(int[] arr) {
        for (int i = 0; i < m; i++) {
            arr[i] = 1;
        }
        for (int i = m; i < n; i++) {
            arr[i] = 0;
        }
    }

    private void shuffle(int[] arr) {
        //方法一
//        for (int i = 0; i < n; i++) {
//            int x = (int) (Math.random() * n);
//            swap(arr, i, x);
//        }
        //方法二
//        for (int i = 0; i < m; i++) {
//            int x = (int) (Math.random() * n);
//            swap(arr, i, x);
//        }
        //方法三:knuth算法
//        for (int i = 0; i < n; i++) {
//            //从[i,n)区间里随机选择元素
//            int x = (int) (Math.random() * (n - i)) + i;
//            swap(arr, i, x);
//        }
        //方法四
        for (int i = n - 1; i >= 0; i--) {
            //从[0,i+1)区间里随机选择元素
            int x = (int) (Math.random() * (i + 1));
            swap(arr, i, x);
        }
    }

    private void swap(int[] arr, int x, int y) {
        int t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }

    public static void main(String[] args) {
        int N = 10000000;
        int n = 10;
        int m = 5;
        ShuffleExp exp = new ShuffleExp(N, n, m);
        exp.run();
    }
}
