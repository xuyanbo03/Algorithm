public class WinningPrize {
    private double change;
    private double playTime;
    private double N;

    public WinningPrize(double change, int playTime, int N) {
        if (change < 0.0 || change > 1.0) {
            throw new IllegalArgumentException("change must be between 0 and 1");
        }
        if (playTime <= 0 || N <= 0) {
            throw new IllegalArgumentException("playTime or N must be larger than 0");
        }

        this.change = change;
        this.playTime = playTime;
        this.N = N;
    }

    public void run() {
        int wins = 0;
        for (int i = 0; i < N; i++) {
            if (play()) {
                wins++;
            }
        }
        System.out.println("winning rate:" + (double) wins / N);
    }

    private boolean play() {
        for (int i = 0; i < playTime; i++) {
            if (Math.random() < change) {
                return true;
            }
        }
        return false;
    }
}
