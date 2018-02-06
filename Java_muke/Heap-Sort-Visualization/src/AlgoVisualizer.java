import java.awt.*;

//Control
public class AlgoVisualizer {

    private static int DELAY = 10;
    private HeapSortData data;//数据
    private AlgoFrame frame;//视图

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N) {
        //数据初始化
        data = new HeapSortData(N, sceneHeight);

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Selection Sort Visualization", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        //堆排序可视化
        setData(data.N());

        //建堆
        for (int i = (data.N() - 1 - 1) / 2; i >= 0; i--) {
            shiftDown(data.N(), i);
        }

        //堆排序
        for (int i = data.N() - 1; i > 0; i--) {
            data.swap(0, i);
            shiftDown(i, 0);
            setData(i);
        }

        setData(0);
    }

    private void shiftDown(int n, int k) {
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && data.get(j + 1) > data.get(j)) {
                j += 1;
            }
            if (data.get(k) >= data.get(j)) {
                break;
            }
            data.swap(k, j);
            setData(data.heapIndex);
            k = j;
        }
    }

    private void setData(int heapIndex) {
        data.heapIndex = heapIndex;

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
