import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    int[][] matrixA;
    int[][] matrixB;
    int[][] diffMap;

    int n;
    int m;
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] string = br.readLine().split(" ");
        n = Integer.parseInt(string[0]);
        m = Integer.parseInt(string[1]);

        matrixA = new int[n][m];
        matrixB = new int[n][m];
        diffMap = new int[n][m];

        int answer = 0;

        for (int i = 0; i < n; i++) {
            String[] temp = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                matrixA[i][j] = Integer.parseInt(temp[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            String[] temp = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                matrixB[i][j] = Integer.parseInt(temp[j]);
            }
        }

        makeDiffMap();

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (diffMap[i][j] > 0) {
                    changeDiffMap(i, j);
                    answer += 1;
                }
            }
        }

        if (Stream.of(diffMap).flatMapToInt(IntStream::of).sum() > 0) {
            return -1;
        }
        return answer;
    }

    private void makeDiffMap() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diffMap[i][j] = Math.abs(matrixA[i][j] - matrixB[i][j]);
            }
        }
    }

    private void changeDiffMap(int row, int col) {
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (diffMap[i][j] == 0) {
                    diffMap[i][j] = 1;
                } else {
                    diffMap[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Main matrix = new Main();
        System.out.println(matrix.solution());
    }
}
