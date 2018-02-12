public class Main {

    public static void main(String[] args) {
        //String filename = "level/boston_09.txt";
        String filename = "level/boston_16.txt";
        AlgoVisualizer vis = new AlgoVisualizer(filename);
    }
}

/*
 * 自动求解-人工智能启蒙
 * 1.动态规划：解决重叠子问题
 * 2.剪枝：树搜索->图搜索，x-p剪枝算法
 * 3.启发式搜索：A*，最大最小搜索
 * 4.传统搜索框架：深度优先，广度优先，双向搜索，优先队列搜索
 * 5.非传统搜索：梯度下降算法，模拟退火，遗传算法
 * 6.逻辑推演：符号主义->连接主义（神经网络->深度学习）
 * */

