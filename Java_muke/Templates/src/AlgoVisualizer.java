import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

//Control
public class AlgoVisualizer {
    //TODO：创建自己的数据
    private Object data;//数据
    private AlgoFrame frame;//视图
	private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight) {
        //数据初始化
        //TODO:初始化数据

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Welcome", sceneWidth, sceneHeight);
            //TODO:根据情况是否添加鼠标和键盘事件监听器
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
        //TODO:编写逻辑
    }
	
	private void setData(int orderedIndex, int currentCompareIndex, int currentMinIndex) {
        data.orderedIndex = orderedIndex;
        data.currentCompareIndex = currentCompareIndex;
        data.currentMinIndex = currentMinIndex;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    //TODO:根据情况决定是否实现键盘鼠标等交互事件监听器
    //键盘事件
    private class AlgoKeyListener extends KeyAdapter {

    }

    //鼠标事件
    private class AlgoMouseListener extends MouseAdapter {

    }
}
