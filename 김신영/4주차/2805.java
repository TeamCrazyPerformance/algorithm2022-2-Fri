import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        Integer[] trees = new Integer[n];
        String[] treeStrings = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            trees[i] = Integer.parseInt(treeStrings[i]);
        }

        Arrays.sort(trees);

        int cutted = 0;
        int wholeIndex = trees.length - 1;
        int index = wholeIndex;
        int height = trees[index];

        while(true) {
            if (index <= 0) {
                if (cutted < m) {
                    height -= Math.ceil((double)(m - cutted) / n);
                }
                break;
            }
            int cuttingPlan = cutted + (trees[index] - trees[index - 1]) * (wholeIndex - index + 1);
            if (m > cuttingPlan) {
                cutted = cuttingPlan;
                index -= 1;
                height = trees[index];
            } else if (m == cuttingPlan) {
                cutted = cuttingPlan;
                height = trees[index - 1];
                break;
            } else {
                index = Arrays.asList(trees).indexOf(trees[index]);
                cuttingPlan = wholeIndex - index + 1;
                height -= Math.ceil((double)(m - cutted) / cuttingPlan);
                break;
            }
        }
        return height;
    }

    public static void main(String[] args) throws Exception {
        Main cuttingTree = new Main();
        System.out.println(cuttingTree.solution());
    }
}
