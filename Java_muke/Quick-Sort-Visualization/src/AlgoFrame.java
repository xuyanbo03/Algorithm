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

    //private QuickSortData data;
    //private TwoWaysQuickSortData data;
    private ThreeWaysQuickSortData data;

    //    public void render(QuickSortData data) {
//        this.data = data;
//        repaint();
//    }
//    public void render(TwoWaysQuickSortData data) {
//        this.data = data;
//        repaint();
//    }
    public void render(ThreeWaysQuickSortData data) {
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

            //具体绘制单路快排
//            int w = canvasWidth / data.N();
//            for (int i = 0; i < data.N(); i++) {
//                if (i >= data.l && i <= data.r) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Green);
//                } else {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Grey);
//                }
//                if (i == data.curPivot) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Indigo);
//                }
//                if (i == data.curElement) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
//                }
//                if (data.fixedPivots[i]) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Red);
//                }
//                AlgoVisHelper.fillRectangle(g2d, i * w, canvasHeight - data.get(i), w - 1, data.get(i));
//            }
            //具体绘制双路快排
//            int w = canvasWidth / data.N();
//            for (int i = 0; i < data.N(); i++) {
//                if (i >= data.l && i <= data.r) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Green);
//                } else {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Grey);
//                }
//                if (i == data.curPivot) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Indigo);
//                }
//                if (i >= data.l+1&&i<=data.curL) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
//                }
//                if (i >= data.curR+1&&i<=data.r) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
//                }
//                if (data.fixedPivots[i]) {
//                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Red);
//                }
//                AlgoVisHelper.fillRectangle(g2d, i * w, canvasHeight - data.get(i), w - 1, data.get(i));
//            }
            //具体绘制三路快排
            int w = canvasWidth / data.N();
            for (int i = 0; i < data.N(); i++) {
                if (i >= data.l && i <= data.r) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Green);
                } else {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Grey);
                }
                if (i == data.curPivot) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Indigo);
                }
                if (i >= data.l + 1 && i <= data.curL) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
                }
                if (i >= data.curR + 1 && i <= data.r) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
                }
                if (data.fixedPivots[i]) {
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Red);
                }
                AlgoVisHelper.fillRectangle(g2d, i * w, canvasHeight - data.get(i), w - 1, data.get(i));
            }
        }

        @Override
        public Dimension getPreferredSize() {
            //画布绘制
            return new Dimension(canvasWidth, canvasHeight);
        }
    }
}
