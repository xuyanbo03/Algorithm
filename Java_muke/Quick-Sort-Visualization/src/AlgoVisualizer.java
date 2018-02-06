import java.awt.*;
import java.util.Arrays;

//Control
public class AlgoVisualizer {
    //private QuickSortData data;//数据
    //private TwoWaysQuickSortData data;//数据
    private ThreeWaysQuickSortData data;//数据

    private AlgoFrame frame;//视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N, ThreeWaysQuickSortData.Type dataType) {
        //数据初始化
        //data = new QuickSortData(N, sceneHeight, dataType);
        //data = new TwoWaysQuickSortData(N, sceneHeight, dataType);
        data = new ThreeWaysQuickSortData(N, sceneHeight, dataType);

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
        this(sceneWidth, sceneHeight, N, ThreeWaysQuickSortData.Type.Default);
    }

    private void run() {
        //动画逻辑
        //单路快排的可视化
        //setData1(-1, -1, -1, -1, -1);
        //quickSort1(0, data.N() - 1);
        //setData1(-1, -1, -1, -1, -1);

        //双路快排可视化
        //setData2(-1, -1, -1, -1, -1, -1);
        //quickSort2(0, data.N() - 1);
        //setData2(-1, -1, -1, -1, -1, -1);

        //三路快排可视化
        setData3(-1, -1, -1, -1, -1, -1);
        quickSort3(0, data.N() - 1);
        setData3(-1, -1, -1, -1, -1, -1);
    }

//    private void quickSort1(int l, int r) {
//        if (l > r) {
//            return;
//        }
//        if (l == r) {
//            setData1(l, r, l, -1, -1);
//            return;
//        }
//        setData1(l, r, -1, -1, -1);
//        int p = partition1(l, r);
//        quickSort1(l, p - 1);
//        quickSort1(p + 1, r);
//    }
//
//    private int partition1(int l, int r) {
//        int p = (int) (Math.random() * (r - l + 1)) + l;
//        setData1(l, r, -1, p, -1);
//        data.swap(l, p);
//
//        int v = data.get(l);
//        setData1(l, r, -1, l, -1);
//        int j = l;
//        for (int i = l + 1; i <= r; i++) {
//            setData1(l, r, -1, l, i);
//            if (data.get(i) < v) {
//                j++;
//                data.swap(j, i);
//                setData1(l, r, -1, l, -1);
//            }
//        }
//        data.swap(l, j);
//        setData1(l, r, j, -1, -1);
//        return j;
//    }


//    private void quickSort2(int l, int r) {
//        if (l > r) {
//            return;
//        }
//        if (l == r) {
//            setData2(l, r, l, -1, -1, -1);
//            return;
//        }
//        setData2(l, r, -1, -1, -1, -1);
//        int p = partition2(l, r);
//        quickSort2(l, p - 1);
//        quickSort2(p + 1, r);
//    }
//
//    private int partition2(int l, int r) {
//        int p = (int) (Math.random() * (r - l + 1)) + l;
//        setData2(l, r, -1, p, -1, -1);
//        data.swap(l, p);
//
//        int v = data.get(l);
//        setData2(l, r, -1, l, -1, -1);
//
//        int i = l + 1, j = r;
//        setData2(l, r, -1, l, i, j);
//        while (true) {
//            while (i <= r && data.get(i) < v) {
//                i++;
//                setData2(l, r, -1, l, i, j);
//            }
//            while (j >= l + 1 && data.get(j) > v) {
//                j--;
//                setData2(l, r, -1, l, i, j);
//            }
//            if (i > j) {
//                break;
//            }
//            data.swap(i, j);
//            i++;
//            j--;
//            setData2(l, r, -1, l, i, j);
//        }
//        data.swap(l, j);
//        setData2(l, r, j, -1, -1, -1);
//        return j;
//    }


    private void quickSort3(int l, int r) {
        if (l > r) {
            return;
        }
        if (l == r) {
            setData3(l, r, l, -1, -1, -1);
            return;
        }

        int p = (int) (Math.random() * (r - l + 1)) + l;
        setData3(l, r, -1, p, -1, -1);
        data.swap(l, p);
        int v = data.get(l);
        setData3(l, r, -1, l, -1, -1);

        //三路快排的partition
        int lt = l;//arr[l+1...lt]<v
        int gt = r + 1;//arr[gt...r]>v
        int i = l + 1;//arr[lt+1...i]==v
        setData3(l, r, -1, l, lt, gt);
        while (i < gt) {
            if (data.get(i) < v) {
                data.swap(i, lt + 1);
                i++;
                lt++;
            } else if (data.get(i) > v) {
                data.swap(i, gt - 1);
                gt--;
            } else {
                i++;
            }
            setData3(l, r, -1, l, i, gt);
        }
        data.swap(l, lt);
        setData3(l, r, lt, -1, -1, -1);

        quickSort3(l, lt - 1);
        quickSort3(gt, r);
    }


//    private void setData1(int l, int r, int fixedPivot, int curPivot, int curElement) {
//        data.l = l;
//        data.r = r;
//        if (fixedPivot != -1) {
//            data.fixedPivots[fixedPivot] = true;
//        }
//        data.curPivot = curPivot;
//        data.curElement = curElement;
//
//        frame.render(data);
//        AlgoVisHelper.pause(DELAY);
//    }

//    private void setData2(int l, int r, int fixedPivot, int curPivot, int curL, int curR) {
//        data.l = l;
//        data.r = r;
//        if (fixedPivot != -1) {
//            data.fixedPivots[fixedPivot] = true;
//        }
//        data.curPivot = curPivot;
//        data.curL = curL;
//        data.curR = curR;
//
//        frame.render(data);
//        AlgoVisHelper.pause(DELAY);
//    }

    private void setData3(int l, int r, int fixedPivot, int curPivot, int curL, int curR) {
        data.l = l;
        data.r = r;
        if (fixedPivot != -1) {
            data.fixedPivots[fixedPivot] = true;
            int i = fixedPivot;
            while (i < data.N() && data.get(i) == data.get(fixedPivot)) {
                data.fixedPivots[i] = true;
                i++;
            }
        }
        data.curPivot = curPivot;
        data.curL = curL;
        data.curR = curR;

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
