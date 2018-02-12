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

    private FractalData data;

    public void render(FractalData data) {
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
            //drawVicsekFractal(g2d, 0, 0, canvasWidth, canvasHeight, 0);
            //drawSierpinskiFractal(g2d, 0, 0, canvasWidth, canvasHeight, 0);
            //drawSierpinskiTriangle(g2d, 0, canvasHeight, canvasWidth, 0);
            //drawKochSnowflake(g2d, 0, canvasHeight - 3, canvasWidth, 0, 0);
            drawTree(g2d, canvasWidth / 2, canvasHeight, canvasHeight, 0, 0);
        }

        //Vicsek Fractal
        private void drawVicsekFractal(Graphics2D g, int x, int y, int w, int h, int depth) {
            if (depth == data.depth) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.fillRectangle(g, x, y, w, h);
                return;
            }
            if (w <= 1 || h <= 1) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.fillRectangle(g, x, y, Math.max(w, 1), Math.max(h, 1));
                return;
            }

            int w_3 = w / 3;
            int h_3 = h / 3;
            drawVicsekFractal(g, x, y, w_3, h_3, depth + 1);
            drawVicsekFractal(g, x + 2 * w_3, y, w_3, h_3, depth + 1);
            drawVicsekFractal(g, x + w_3, y + h_3, w_3, h_3, depth + 1);
            drawVicsekFractal(g, x, y + 2 * h_3, w_3, h_3, depth + 1);
            drawVicsekFractal(g, x + 2 * w_3, y + 2 * h_3, w_3, h_3, depth + 1);
            return;
        }

        //Sierpinski Fractal
        private void drawSierpinskiFractal(Graphics2D g, int x, int y, int w, int h, int depth) {
            int w_3 = w / 3;
            int h_3 = h / 3;
            if (depth == data.depth) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.fillRectangle(g, x + w_3, y + h_3, w_3, h_3);
                return;
            }
            if (w <= 1 || h <= 1) {
                return;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 1 && j == 1) {
                        AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                        AlgoVisHelper.fillRectangle(g, x + w_3, y + h_3, w_3, h_3);
                    } else {
                        drawSierpinskiFractal(g, x + i * w_3, y + j * h_3, w_3, h_3, depth + 1);
                    }
                }
            }
            return;
        }

        //Sierpinski Triangle
        /*
         * A：A点坐标
         * side边长：底边长
         * */
        private void drawSierpinskiTriangle(Graphics2D g, int Ax, int Ay, int side, int depth) {
            int Bx = Ax + side;
            int By = Ay;
            int h = (int) (Math.sin(60.0 * Math.PI / 180.0) * side);
            int Cx = Ax + side / 2;
            int Cy = Ay - h;

            if (depth == data.depth) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.fillTriangle(g, Ax, Ay, Bx, By, Cx, Cy);
                return;
            }
            if (side <= 1) {
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.fillRectangle(g, Ax, Ay, 1, 1);
                return;
            }

            int AB_centerx = (Ax + Bx) / 2;
            int AC_centerx = (Ax + Cx) / 2;
            int BC_centerx = (Cx + Bx) / 2;
            int AB_centery = (Ay + By) / 2;
            int AC_centery = (Ay + Cy) / 2;
            int BC_centery = (Cy + By) / 2;
            drawSierpinskiTriangle(g, Ax, Ay, side / 2, depth + 1);
            drawSierpinskiTriangle(g, AC_centerx, AC_centery, side / 2, depth + 1);
            drawSierpinskiTriangle(g, AB_centerx, AB_centery, side / 2, depth + 1);
            return;
        }

        //Koch Snowflake雪花分形
        private void drawKochSnowflake(Graphics2D g, double x1, double y1, double side, double angle, int depth) {
            if (depth == data.depth) {
                double x2 = x1 + side * Math.cos(angle * Math.PI / 180.0);
                double y2 = y1 - side * Math.sin(angle * Math.PI / 180.0);
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.drawLine(g, x1, y1, x2, y2);
                return;
            }
            if (side <= 0) {
                return;
            }

            double side_3 = side / 3;

            double x2 = x1 + side_3 * Math.cos(angle * Math.PI / 180.0);
            double x3 = x2 + side_3 * Math.cos((angle + 60.0) * Math.PI / 180.0);
            double x4 = x3 + side_3 * Math.cos((angle - 60.0) * Math.PI / 180.0);

            double y2 = y1 - side_3 * Math.sin(angle * Math.PI / 180.0);
            double y3 = y2 - side_3 * Math.sin((angle + 60.0) * Math.PI / 180.0);
            double y4 = y3 - side_3 * Math.sin((angle - 60.0) * Math.PI / 180.0);

            drawKochSnowflake(g, x1, y1, side_3, angle, depth + 1);
            drawKochSnowflake(g, x2, y2, side_3, angle + 60.0, depth + 1);
            drawKochSnowflake(g, x3, y3, side_3, angle - 60.0, depth + 1);
            drawKochSnowflake(g, x4, y4, side_3, angle, depth + 1);
            return;
        }

        //树分形
        private void drawTree(Graphics2D g, double x1, double y1, double side, double angle, int depth) {
            double side_2 = side / 2;
            if (depth == data.depth) {
                double x2 = x1 - side * Math.sin(angle * Math.PI / 180.0);
                double y2 = y1 - side * Math.cos(angle * Math.PI / 180.0);
                AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
                AlgoVisHelper.drawLine(g, x1, y1, x2, y2);
                return;
            }
            if (side_2 <= 0) {
                return;
            }

            double x2 = x1 - side_2 * Math.sin(angle * Math.PI / 180.0);
            double y2 = y1 - side_2 * Math.cos(angle * Math.PI / 180.0);
            AlgoVisHelper.setColor(g, AlgoVisHelper.Indigo);
            AlgoVisHelper.drawLine(g, x1, y1, x2, y2);

            drawTree(g, x2, y2, side_2, angle + data.splitAngle / 2, depth + 1);
            drawTree(g, x2, y2, side_2, angle - data.splitAngle / 2, depth + 1);
            return;
        }

        @Override
        public Dimension getPreferredSize() {
            //画布绘制
            return new Dimension(canvasWidth, canvasHeight);
        }
    }
}
