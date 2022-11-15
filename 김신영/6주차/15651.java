import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    int n;
    int m;
    StringBuffer output = new StringBuffer();

    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        n = Integer.parseInt(input.charAt(0) + "");
        m = Integer.parseInt(input.charAt(2) + "");

        int[] permutation = new int[m];
        recursion(0, permutation, 1);
        System.out.println(output);
    }

    public void recursion(int depth, int[] permutation, int index) {
        if (depth == m) {
            printPermutation(permutation);
            return;
        }

        for (int i = index; i <= n; i++) {
            permutation[depth] = i;
            depth += 1;
            recursion(depth, permutation, index);
            depth -= 1;
        }
    }

    public void printPermutation(int[] permutation) {
        for (int i = 0; i < m - 1; i++) {
            output.append(permutation[i]).append(" ");
        }
        output.append(permutation[m - 1]);
        output.append("\n");
    }

    public static void main(String[] args) throws Exception {
        Main nnmThree = new Main();
        nnmThree.solution();
    }
}
