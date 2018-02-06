import java.awt.*;
import java.util.Arrays;

//Control
public class AlgoVisualizer {
    private MergeSortData data;//数据
    private AlgoFrame frame;//视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N, MergeSortData.Type dataType) {
        //数据初始化
        data = new MergeSortData(N, sceneHeight, dataType);

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Welcome", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N) {
        this(sceneWidth, sceneHeight, N, MergeSortData.Type.Default);
    }

    private void run() {
        //动画逻辑
        //归并排序的可视化
        setData(-1, -1, -1);
        //mergeSort1(0, data.N() - 1);
        mergeSort2();
        setData(0, data.N() - 1, data.N() - 1);
    }

    private void mergeSort1(int l, int r) {
        if (l >= r) {
            return;
        }
        setData(l, r, -1);
        int mid = (l + r) / 2;
        mergeSort1(l, mid);
        mergeSort1(mid + 1, r);
        merge(l, mid, r);
    }

    private void mergeSort2() {
        for (int sz = 1; sz < data.N(); sz *= 2) {
            for (int i = 0; i < data.N() - sz; i += sz + sz) {
                //对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
                merge(i, i + sz - 1, Math.min(i + sz + sz - 1, data.N() - 1));
            }
        }
    }

    private void merge(int l, int mid, int r) {
        int[] aux = Arrays.copyOfRange(data.numbers, l, r + 1);

        //初始化，i指向左半部分的起始索引位置l，j指向右半部分的起始索引位置mid+1
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                data.numbers[k] = aux[j - l];
                j++;
            } else if (j > r) {
                data.numbers[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                data.numbers[k] = aux[i - l];
                i++;
            } else {
                data.numbers[k] = aux[j - l];
                j++;
            }

            setData(l, r, k);
        }
    }

    private void setData(int l, int r, int mergeIndex) {
        data.l = l;
        data.r = r;
        data.mergeIndex = mergeIndex;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

//    //TODO:根据情况决定是否实现键盘鼠标等交互事件监听器
//    //键盘事件
//    private class AlgoKeyListener extends KeyAdapter {
//
//    }
//
//    //鼠标事件
//    private class AlgoMouseListener extends MouseAdapter {
//
//    }
}
