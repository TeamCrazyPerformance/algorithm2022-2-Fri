import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stringTokenizer.nextToken());
        int m = Integer.parseInt(stringTokenizer.nextToken());
        int[][] array = new int[n][n];
        int[][] sumArray = new int[n][n];

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int tempSum = 0;
            for (int j = 0; j < n; j++) {
                int temp = Integer.parseInt(stringTokenizer.nextToken());
                array[i][j] = temp;
                tempSum += temp;
                sumArray[i][j] = tempSum;
            }
        }

        for (int i = 0; i < m; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(stringTokenizer.nextToken());
            int y1 = Integer.parseInt(stringTokenizer.nextToken());
            int x2 = Integer.parseInt(stringTokenizer.nextToken());
            int y2 = Integer.parseInt(stringTokenizer.nextToken());

            bw.write(String.valueOf(calculateSubSum(x1 - 1, y1 - 1, x2 - 1, y2 - 1, sumArray)));
            bw.newLine();
        }
        bw.flush();
    }

    public int calculateSubSum(int x1, int y1, int x2, int y2, int[][] sumArray) {
        int answer = 0;
        for (int i = x1; i <= x2; i++) {
            answer += sumArray[i][y2];
            if (y1 - 1 > -1) {
                answer -= sumArray[i][y1 - 1];
            }
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        Main subSumFive = new Main();
        subSumFive.solution();
    }
}
