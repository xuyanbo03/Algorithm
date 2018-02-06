import javax.swing.*;
import java.awt.*;

//View
public class AlgoFrame extends JFrame {
    private int canvasWidth;
    private int canvasHeight;

    public AlgoFrame(String title, int canvasWidth, int canvasHeight) {
        super(title);
        this.canvasWidth = canvasWidth;
        this.canvasHeight = canvasHeight;

        AlgoCanvas canvas = new AlgoCanvas();
        setContentPane(canvas);
        pack();

        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public AlgoFrame(String title) {
        this(title, 1024, 768);
    }

    public int getCanvasWidth() {
        return canvasWidth;
    }

    public int getCanvasHeight() {
        return canvasHeight;
    }


    private int[] money;

    public void render(int[] money) {
        this.money = money;
        repaint();
    }

    private class AlgoCanvas extends JPanel {
        public AlgoCanvas() {
            //双缓存
            super(true);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;

            //抗锯齿
            RenderingHints hints = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2d.addRenderingHints(hints);

            //具体绘制
            int w = canvasWidth / money.length;
            for (int i = 0; i < money.length; i++) {
                if (money[i] > 0) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Blue);
                    AlgoVisHelper.fillRectangle(g2d, i * w + 1, canvasHeight / 2 - money[i], w - 1, money[i]);
                } else {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Red);
                    AlgoVisHelper.fillRectangle(g2d, i * w + 1, canvasHeight / 2, w - 1, -money[i]);
                }
            }
        }

        @Override
        public Dimension getPreferredSize() {
            //画布绘制
            return new Dimension(canvasWidth, canvasHeight);
        }
    }
}