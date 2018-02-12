import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

//Control
public class AlgoVisualizer {
    private FractalData data;//数据
    private AlgoFrame frame;//视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int maxDepth, double splitAngle) {
        //数据初始化
        data = new FractalData(maxDepth, splitAngle);
        //Fractal
        //int sceneWidth = (int) (Math.pow(3, maxDepth));
        //int sceneHeight = (int) (Math.pow(3, maxDepth));

        //Triangle
        //int sceneWidth = (int) (Math.pow(2, maxDepth));
        //int sceneHeight = (int) (Math.pow(2, maxDepth));

        //Koch Snowflake雪花分形
        //int sceneWidth = side;
        //int sceneHeight = side / 3;

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Fractal Visualizer", sceneWidth, sceneHeight);
            frame.addKeyListener(new AlgoKeyListener());
//            frame.addMouseListener(new AlgoMouseListener());
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setData(data.depth);
    }

    private void setData(int depth) {
        if (depth >= 0) {
            data.depth = depth;
        }
        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    //键盘事件
    private class AlgoKeyListener extends KeyAdapter {
        @Override
        public void keyReleased(KeyEvent event) {
            if (event.getKeyChar() >= '0' && event.getKeyChar() <= '9') {
                int depth = event.getKeyChar() - '0';
                setData(depth);
            }
        }
    }
//
//    //鼠标事件
//    private class AlgoMouseListener extends MouseAdapter {
//
//    }
}
