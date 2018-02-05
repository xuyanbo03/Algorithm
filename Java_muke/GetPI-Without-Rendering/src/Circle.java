import java.awt.*;

//Model
public class Circle {
    public int x, y;
    private int r;//半径

    public Circle(int x, int y, int r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public int getR() {
        return r;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    //判断点是否在圆内
    public boolean contain(Point p) {
        return Math.pow(p.getX() - x, 2) + Math.pow(p.getY() - y, 2) <= r * r;
    }
}
