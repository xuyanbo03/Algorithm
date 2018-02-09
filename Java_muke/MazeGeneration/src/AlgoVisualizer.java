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
            frame.addKeyListener(new AlgoKeyListener());
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setRoadData(-1, -1);
        //深度优先遍历递归生成迷宫
        //go(data.getEntranceX(), data.getEntranceY() + 1);

        //深度优先遍历非递归生成迷宫
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


        //广度优先遍历非递归生成迷宫
//        LinkedList<Position> queue = new LinkedList<Position>();
//        Position first = new Position(data.getEntranceX(), data.getEntranceY() + 1);
//        queue.addLast(first);
//        data.visited[first.getX()][first.getY()] = true;
//
//        while (queue.size() != 0) {
//            Position curPos = queue.removeFirst();
//
//            for (int i = 0; i < 4; i++) {
//                int newX = curPos.getX() + d[i][0] * 2;
//                int newY = curPos.getY() + d[i][1] * 2;
//                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
//                    queue.addLast(new Position(newX, newY));
//                    data.visited[newX][newY] = true;
//                    setData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
//                }
//            }
//        }


        //使用随机队列(数组)生成迷宫
//        RandomQueue<Position> queue = new RandomQueue<Position>();
//        Position first = new Position(data.getEntranceX(), data.getEntranceY() + 1);
//        queue.add(first);
//        data.visited[first.getX()][first.getY()] = true;
//        data.openMist(first.getX(), first.getY());
//
//        while (queue.size() != 0) {
//            Position curPos = queue.remove();
//
//            for (int i = 0; i < 4; i++) {
//                int newX = curPos.getX() + d[i][0] * 2;
//                int newY = curPos.getY() + d[i][1] * 2;
//                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
//                    queue.add(new Position(newX, newY));
//                    data.visited[newX][newY] = true;
//                    data.openMist(newX, newY);
//                    setRoadData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
//                }
//            }
//        }

        //使用随机队列(链表)生成迷宫(更加随机)
        RandomQueue2<Position> queue = new RandomQueue2<Position>();
        Position first = new Position(data.getEntranceX(), data.getEntranceY() + 1);
        queue.add(first);
        data.visited[first.getX()][first.getY()] = true;
        data.openMist(first.getX(), first.getY());

        while (queue.size() != 0) {
            Position curPos = queue.remove();

            for (int i = 0; i < 4; i++) {
                int newX = curPos.getX() + d[i][0] * 2;
                int newY = curPos.getY() + d[i][1] * 2;
                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
                    queue.add(new Position(newX, newY));
                    data.visited[newX][newY] = true;
                    data.openMist(newX, newY);
                    setRoadData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
                }
            }
        }
        setRoadData(-1, -1);
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

    private void setRoadData(int x, int y) {
        if (data.inArea(x, y)) {
            data.maze[x][y] = MazeData.ROAD;
        }
        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    //深度优先遍历递归求解迷宫问题
    private boolean go(int x, int y) {
        if (!data.inArea(x, y)) {
            throw new IllegalArgumentException("x,y are out of index in go function");
        }
        data.visited[x][y] = true;
        setPathData(x, y, true);

        if (x == data.getExitX() && y == data.getExitY()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if (data.inArea(newX, newY) && data.getMaze(newX, newY) == MazeData.ROAD && !data.visited[newX][newY]) {
                if (go(newX, newY)) {
                    return true;
                }
            }
        }
        setPathData(x, y, false);
        return false;
    }

    private void setPathData(int x, int y, boolean isPath) {
        if (data.inArea(x, y)) {
            data.path[x][y] = isPath;
        }
        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    private class AlgoKeyListener extends KeyAdapter {
        @Override
        public void keyReleased(KeyEvent event) {
            if (event.getKeyChar() == ' ') {
                for (int i = 0; i < data.N(); i++) {
                    for (int j = 0; j < data.M(); j++) {
                        data.visited[i][j] = false;
                    }
                }

                new Thread(() -> {
                    go(data.getEntranceX(), data.getEntranceY());
                }).start();
            }
        }
    }
}
