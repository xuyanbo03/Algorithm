public class FractalData {
    public int depth;
    public double splitAngle;

    public FractalData(int depth) {
        this.depth = depth;
    }

    public FractalData(int depth, double splitAngle) {
        this.depth = depth;
        this.splitAngle = splitAngle;
    }
}
