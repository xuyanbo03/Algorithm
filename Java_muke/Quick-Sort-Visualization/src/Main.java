public class Main {

    public static void main(String[] args) {
        int sceneWidth = 800;
        int sceneHeight = 800;
        int N = 100;

        //AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N, QuickSortData.Type.Identical);
        //AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N, TwoWaysQuickSortData.Type.Identical);
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N, ThreeWaysQuickSortData.Type.Identical);
    }
}
