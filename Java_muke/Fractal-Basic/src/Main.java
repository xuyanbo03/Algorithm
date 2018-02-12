public class Main {

    public static void main(String[] args) {
        int sceneWidth = 800;
        int sceneHeight = 800;
        int maxDepth = 9;
        double splitAngle = 60.0;

        //分形
        //AlgoVisualizer visualizer = new AlgoVisualizer(maxDepth);

        //树分形
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, maxDepth, splitAngle);
    }
}
