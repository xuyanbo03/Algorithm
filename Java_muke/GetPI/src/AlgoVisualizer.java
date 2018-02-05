import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.LinkedList;

//Control
public class AlgoVisualizer {
    //    private Circle circle;
//    private int insideCircle = 0;
//    private LinkedList<Point> points;
    private MonteCarloPiData data;
    private static int DELAY = 40;
    private int N;
    private AlgoFrame frame;//视图

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N) {
        if (sceneWidth != sceneHeight) {
            try {
                throw new IllegalAccessException("This demo must be run in a square window");
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }

        //数据初始化
        this.N = N;
        Circle circle = new Circle(sceneWidth / 2, sceneHeight / 2, sceneWidth / 2);
        data = new MonteCarloPiData(circle);

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Get PI with MonteCarlo", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        for (int i = 0; i < N; i++) {
            if (i % 100 == 0) {
                frame.render(data);
                AlgoVisHelper.pause(DELAY);
                System.out.println(data.estimatePI());
//                if (points.size() != 0) {
//                    int circleArea = insideCircle;
//                    int squareArea = points.size();
//                    double piEstimation = 4 * (double) circleArea / squareArea;
//                    System.out.println(piEstimation);
//                }
            }

            int x = (int) (Math.random() * frame.getCanvasWidth());
            int y = (int) (Math.random() * frame.getCanvasHeight());
            data.addPoint(new Point(x, y));
//            Point p = new Point(x, y);
//            points.add(p);
//            if (circle.contain(p)) {
//                insideCircle++;
//            }
        }
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
