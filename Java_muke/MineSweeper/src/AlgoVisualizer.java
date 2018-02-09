import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

//Control
public class AlgoVisualizer {
    private MineSweeperData data;//数据
    private AlgoFrame frame;//视图
    private static int DELAY = 5;
    private static int blockSide = 32;

    public AlgoVisualizer(int N, int M, int mineNumber) {
        //数据初始化
        data = new MineSweeperData(N, M, mineNumber);
        int sceneWidth = M * blockSide;
        int sceneHeight = N * blockSide;

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Mine Sweeper", sceneWidth, sceneHeight);
            frame.addKeyListener(new AlgoKeyListener());
            frame.addMouseListener(new AlgoMouseListener());
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setData(false, -1, -1);
    }

    private void setData(boolean isLeftClicked, int x, int y) {
        if (data.inArea(x, y)) {
            if (isLeftClicked) {
                if (data.isMine(x, y)) {
                    //Game Over
                    data.open[x][y] = true;
                } else {
                    data.open(x, y);
                }
            } else {
                data.flags[x][y] = !data.flags[x][y];
            }
        }
        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    //鼠标事件
    private class AlgoMouseListener extends MouseAdapter {
        @Override
        public void mouseReleased(MouseEvent event) {
            event.translatePoint(-(int) (frame.getBounds().width - frame.getCanvasWidth()), -(int) (frame.getBounds().height - frame.getCanvasHeight()));

            Point pos = event.getPoint();
            int w = frame.getCanvasWidth() / data.M();
            int h = frame.getCanvasHeight() / data.N();
            int x = pos.y / h;
            int y = pos.x / w;

            if (SwingUtilities.isLeftMouseButton(event)) {
                setData(true, x, y);
            } else {
                setData(false, x, y);
            }
        }
    }

    //键盘事件
    private class AlgoKeyListener extends KeyAdapter {

    }

}
