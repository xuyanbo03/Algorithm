import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.LinkedList;
import java.util.Stack;

//Control
public class AlgoVisualizer {
    private MazeData data;//数据
    private AlgoFrame frame;//视图
    private static int blockSide = 8;//格子为8像素
    private static int DELAY = 5;

    private static final int d[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public AlgoVisualizer(int N, int M) {
        //数据初始化
        data = new MazeData(N, M);
        int sceneHeight = data.N() * blockSide;
        int sceneWidth = data.M() * blockSide;

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Random Maze Generation Visualization", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setData(-1, -1);
        //深度优先遍历递归生成迷宫
        //go(data.getEntranceX(), data.getEntranceY() + 1);

        //深度优先遍历非递归求解迷宫问题
//        Stack<Position> stack = new Stack<Position>();
//        Position first = new Position(data.getEntranceX(), data.getEntranceY() + 1);
//        stack.push(first);
//        data.visited[first.getX()][first.getY()] = true;
//
//        while (!stack.empty()) {
//            Position curPos = stack.pop();
//
//            for (int i = 0; i < 4; i++) {
//                int newX = curPos.getX() + d[i][0] * 2;
//                int newY = curPos.getY() + d[i][1] * 2;
//                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
//                    stack.push(new Position(newX, newY));
//                    data.visited[newX][newY] = true;
//                    setData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
//                }
//            }
//        }


        //广度优先遍历非递归求解迷宫问题
        LinkedList<Position> queue = new LinkedList<Position>();
        Position first = new Position(data.getEntranceX(), data.getEntranceY() + 1);
        queue.addLast(first);
        data.visited[first.getX()][first.getY()] = true;

        while (queue.size() != 0) {
            Position curPos = queue.removeFirst();

            for (int i = 0; i < 4; i++) {
                int newX = curPos.getX() + d[i][0] * 2;
                int newY = curPos.getY() + d[i][1] * 2;
                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
                    queue.addLast(new Position(newX, newY));
                    data.visited[newX][newY] = true;
                    setData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
                }
            }
        }
        setData(-1, -1);
    }

    //深度优先遍历递归生成迷宫
//    private void go(int x, int y) {
//        if (!data.inArea(x, y)) {
//            throw new IllegalArgumentException("x,y are out of index in go function");
//        }
//        data.visited[x][y] = true;
//
//        for (int i = 0; i < 4; i++) {
//            int newX = x + d[i][0] * 2;
//            int newY = y + d[i][1] * 2;
//            if (data.inArea(newX, newY) && !data.visited[newX][newY]) {
//                setData(x + d[i][0], y + d[i][1]);
//                go(newX, newY);
//            }
//        }
//    }

    //非递归求解迷宫问题回头寻找路径
//    private void findPath(Position des) {
//        Position cur = des;
//        while (cur != null) {
//            data.result[cur.getX()][cur.getY()] = true;
//            cur = cur.getPrev();
//        }
//    }

    private void setData(int x, int y) {
        if (data.inArea(x, y)) {
            data.maze[x][y] = MazeData.ROAD;
        }
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
