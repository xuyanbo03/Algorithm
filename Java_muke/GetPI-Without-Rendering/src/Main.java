public class Main {

    public static void main(String[] args) {
        int squareSide = 800;
        int N = 10000000;

        MonteCarloExperiment exp = new MonteCarloExperiment(squareSide, N);
        exp.setOutputInterval(10000);
        exp.run();
    }
}
