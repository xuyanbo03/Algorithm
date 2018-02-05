import java.awt.*;
import java.util.LinkedList;

public class MonteCarloPiData {
    private Circle circle;
    private int insideCircle = 0;
    private LinkedList<Point> points;

    public MonteCarloPiData(Circle circle) {
        this.circle = circle;
        points = new LinkedList<Point>();
    }

    public Circle getCircle() {
        return circle;
    }

    public Point getPoint(int i) {
        if (i < 0 || i >= points.size()) {
            try {
                throw new IllegalAccessException("Out of bound in getPoint!");
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }

        return points.get(i);
    }

    public int getPointsNumber() {
        return points.size();
    }

    public void addPoint(Point p) {
        points.add(p);
        if (circle.contain(p)) {
            insideCircle++;
        }
    }

    public double estimatePI() {
        if (points.size() == 0) {
            return 0.0;
        }
        int circleArea = insideCircle;
        int squareArea = points.size();
        return (4 * (double) circleArea / squareArea);
    }
}
