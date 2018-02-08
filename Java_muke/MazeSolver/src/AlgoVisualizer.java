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

    public AlgoVisualizer(String mazeFile) {
        //数据初始化
        data = new MazeData(mazeFile);
        int sceneHeight = data.N() * blockSide;
        int sceneWidth = data.M() * blockSide;

        //初始化视图
        //事件队列
        EventQueue.invokeLater(() -> {
            frame = new AlgoFrame("Maze Solver Visualization", sceneWidth, sceneHeight);
            //创建一个新线程，执行任务
            new Thread(() -> {
                run();
            }).start();
        });
    }

    private void run() {
        //动画逻辑
        setData(-1, -1, false);
        //深度优先遍历递归求解迷宫问题
//        if(!go(data.getEntranceX(), data.getEntranceY())){
//            System.out.println("The maze has no solution");
//        }

        //深度优先遍历非递归求解迷宫问题
//        Stack<Position> stack = new Stack<Position>();
//        Position entrance = new Position(data.getEntranceX(), data.getEntranceY());
//        stack.push(entrance);
//        data.visited[entrance.getX()][entrance.getY()] = true;
//
//        boolean isSolved = false;
//        while (!stack.empty()) {
//            Position curPos = stack.pop();
//            setData(curPos.getX(), curPos.getY(), true);
//
//            if (curPos.getX() == data.getExitX() && curPos.getY() == data.getExitY()) {
//                isSolved = true;
//                findPath(curPos);
//                break;
//            }
//            for (int i = 0; i < 4; i++) {
//                int newX = curPos.getX() + d[i][0];
//                int newY = curPos.getY() + d[i][1];
//                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
//                    stack.push(new Position(newX, newY, curPos));
//                    data.visited[newX][newY] = true;
//                }
//            }
//        }
//        if (!isSolved) {
//            System.out.println("The maze has no solution");
//        }


        //广度优先遍历非递归求解迷宫问题
        LinkedList<Position> queue = new LinkedList<Position>();
        Position entrance = new Position(data.getEntranceX(), data.getEntranceY());
        queue.addLast(entrance);
        data.visited[entrance.getX()][entrance.getY()] = true;

        boolean isSolved = false;
        while (queue.size() != 0) {
            Position curPos = queue.pop();
            setData(curPos.getX(), curPos.getY(), true);

            if (curPos.getX() == data.getExitX() && curPos.getY() == data.getExitY()) {
                isSolved = true;
                findPath(curPos);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int newX = curPos.getX() + d[i][0];
                int newY = curPos.getY() + d[i][1];
                if (data.inArea(newX, newY) && !data.visited[newX][newY] && data.getMaze(newX, newY) == MazeData.ROAD) {
                    queue.addLast(new Position(newX, newY, curPos));
                    data.visited[newX][newY] = true;
                }
            }
        }
        if (!isSolved) {
            System.out.println("The maze has no solution");
        }
        setData(-1, -1, false);
    }

    //深度优先遍历递归求解迷宫问题
    private boolean go(int x, int y) {
        if (!data.inArea(x, y)) {
            throw new IllegalArgumentException("x,y are out of index in go function");
        }
        data.visited[x][y] = true;
        setData(x, y, true);

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
        setData(x, y, false);
        return false;
    }

    //非递归求解迷宫问题回头寻找路径
    private void findPath(Position des) {
        Position cur = des;
        while (cur != null) {
            data.result[cur.getX()][cur.getY()] = true;
            cur = cur.getPrev();
        }
    }

    private void setData(int x, int y, boolean isPath) {
        if (data.inArea(x, y)) {
            data.path[x][y] = isPath;
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
