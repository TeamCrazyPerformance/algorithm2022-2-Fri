import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    int n;
    int answer = 0;
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());

        boolean[] visited = new boolean[n];
        int[][] queens = new int[n][2];
        recursion(0, visited, queens);

        bw.write(String.valueOf(answer));

        bw.flush();
        bw.close();
        br.close();
    }

    public void recursion(int depth, boolean[] visited, int[][] queens) {
        if (depth == n) {
            answer += 1;
            //System.out.println("----------------");
            return;
        }

        for (int i = 0; i < n; i++) {
            //System.out.println("depth : " + depth + ", y : " + i);
            //System.out.println(Arrays.toString(visited));
            //System.out.println(queens);
            if (!visited[i]) {
                if (canAddQueen(queens, depth, i)) {
                    visited[i] = true;
                    //recursion(depth, visited, queens);
                    queens[depth][0] = depth;
                    queens[depth][1] = i;
                    depth += 1;
                    recursion(depth, visited, queens);
                    depth -= 1;
                    //queens[depth] = null;
                    visited[i] = false;
                }

            }
        }
    }

    public boolean canAddQueen(int[][] queens, int depth, int y) {
        int diffY = 2;
        for (int i = 0; i < depth; i++) {
            int diffX = Math.abs(queens[i][0] - depth);
            diffY = Math.abs(queens[i][1] - y);

            if (diffX == diffY) {
                return false;
            }
        }

        if (diffY < 2) {
            return false;
        }

        return true;
    }

    class Queen{
        private int x;
        private int y;

        Queen(int x, int y) {
            this.x = x;
            this.y = y;
        }

        /*
        @Override
        public String toString() {
            return "Queen{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
         */
    }

    public static void main(String[] args) throws Exception {
        Main nQueen = new Main();
        nQueen.solution();
    }
}


