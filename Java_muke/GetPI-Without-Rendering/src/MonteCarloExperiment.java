import java.awt.*;
import java.util.IllformedLocaleException;

public class MonteCarloExperiment {
    private int squareSide;
    private int N;
    private int outputInterval = 100;

    public MonteCarloExperiment(int squareSide, int N) {
        if (squareSide <= 0 || N <= 0) {
            throw new IllformedLocaleException("squareSide and N must larger than 0");
        }
        this.squareSide = squareSide;
        this.N = N;
    }

    public void setOutputInterval(int interval) {
        if (interval <= 0) {
            throw new IllformedLocaleException("interval must larger than 0");
        }
        this.outputInterval = outputInterval;
    }

    public void run() {
        Circle circle = new Circle(squareSide / 2, squareSide / 2, squareSide / 2);
        MonteCarloPiData data = new MonteCarloPiData(circle);

        for (int i = 0; i < N; i++) {
            if (i % outputInterval == 0) {
                System.out.println(data.estimatePI());
            }
            int x = (int) (Math.random() * squareSide);
            int y = (int) (Math.random() * squareSide);
            data.addPoint(new Point(x, y));
        }
    }
}
