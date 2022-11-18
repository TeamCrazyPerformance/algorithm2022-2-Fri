import java.io.*;
import java.util.*;

public class Boj11660_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer split = new StringTokenizer(input.readLine());

        int n = Integer.parseInt(split.nextToken());
        int m = Integer.parseInt(split.nextToken());
        int[][] arr = new int[n + 1][n + 1];
        int[][] sumRow = new int[n + 1][n + 1];
        int[][] total = new int[n + 1][n + 1];

        for (int i = 1; i < arr.length; i++) {
            StringTokenizer splitArr = new StringTokenizer(input.readLine());
            for (int j = 1; j < arr[i].length; j++)
                arr[i][j] = Integer.parseInt(splitArr.nextToken());
        }

        for (int i = 1; i < arr.length; i++) {
            total[i][0] += total[i - 1][arr[i].length - 1];
            for (int j = 1; j < arr[i].length; j++) {
                sumRow[i][j] = arr[i][j] + sumRow[i][j - 1];
                total[i][j] = arr[i][j] + total[i][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer splitArr = new StringTokenizer(input.readLine());
            int x1 = Integer.parseInt(splitArr.nextToken());
            int y1 = Integer.parseInt(splitArr.nextToken());
            int x2 = Integer.parseInt(splitArr.nextToken());
            int y2 = Integer.parseInt(splitArr.nextToken());
            int result = 0;
            for (int j = x1; j <= x2; j++)
                result += sumRow[j][y2] - sumRow[j][y1 - 1];
            output.write(result + "\n");
        }

        input.close();
        output.flush();
        output.close();
    }
}