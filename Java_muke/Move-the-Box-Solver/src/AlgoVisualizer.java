import java.awt.*;

//Control
public class AlgoVisualizer {
    private GameData data;//数据
    private AlgoFrame frame;//视图
    private static int blockSide = 80;//格子为80像素
    private static int DELAY = 5;

    private static final int d[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public AlgoVisualizer(String filename) {
        //数据初始化
        data = new GameData(filename);
        int sceneHeight = data.N() * blockSide;
        int sceneWidth = data.M() * blockSide;

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Move the Box Solver Visualization", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setData();
        if (data.solve()) {
            System.out.println("The game has a solution");
        } else {
            System.out.println("The game does not has a solution");
        }
    }

    private void setData() {
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
