public class Main {

    public static void main(String[] args) {
        double change = 0.2;
        int playTime = 5;
        int N = 10000000;

        WinningPrize exp = new WinningPrize(change, playTime, N);
        exp.run();
    }
}

//1-(0.8)^5=0.672
//期望值为5
