public class Main {

    public static void main(String[] args) {
        int N = 10000000;

        ThreeGatesExperiment exp = new ThreeGatesExperiment(N);
        exp.run(true);
        exp.run(false);
    }
}
