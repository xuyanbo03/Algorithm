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

    private CircleData data;

    public void render(CircleData data) {
        this.data = data;
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
            drawCircle(g2d, data.getStartX(), data.getStartY(), data.getStartR(), 0);
        }

        private void drawCircle(Graphics2D g, int x, int y, int r, int depth) {
            if (depth == data.getDepth() || r < 1) {
                return;
            }
            if (depth % 2 == 0) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Red);
            } else {
                AlgoVisHelper.setColor(g, AlgoVisHelper.LightBlue);
            }
            AlgoVisHelper.fillCircle(g, x, y, r);
            drawCircle(g, x, y, r - data.getStep(), depth + 1);
        }

        @Override
        public Dimension getPreferredSize() {
            //画布绘制
            return new Dimension(canvasWidth, canvasHeight);
        }
    }
}
