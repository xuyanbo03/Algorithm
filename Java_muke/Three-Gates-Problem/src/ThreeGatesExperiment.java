public class ThreeGatesExperiment {
    private int N;

    public ThreeGatesExperiment(int N) {
        if (N <= 0) {
            throw new IllegalArgumentException("N must be large than 0!");
        }
        this.N = N;
    }

    public void run(boolean changeDoor) {
        int wins = 0;
        for (int i = 0; i < N; i++) {
            if (play(changeDoor)) {
                wins++;
            }
        }
        System.out.println(changeDoor ? "Change" : "Not Change");
        System.out.println("winning rate:" + (double) wins / N);
    }

    private boolean play(boolean changeDoor) {
        //DOOR 0,1,2
        int prizeDoor = (int) (Math.random() * 3);
        int playerChoice = (int) (Math.random() * 3);
        if (playerChoice == prizeDoor) {
            return changeDoor ? false : true;
        } else {
            return changeDoor ? true : false;
        }
    }
}
