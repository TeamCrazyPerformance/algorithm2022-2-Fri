import java.io.*;
import java.util.*;

public class Boj1149 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        int[][] cost = new int[n][3]; // 0 == R, 1 == G, 2 == B

        for (int i = 0; i < cost.length; i++) {
            StringTokenizer split = new StringTokenizer(input.readLine());
            cost[i][0] = Integer.parseInt(split.nextToken());
            cost[i][1] = Integer.parseInt(split.nextToken());
            cost[i][2] = Integer.parseInt(split.nextToken());
        }
        input.close();

        int[][] sumCost = new int[n][3];
        sumCost[0][0] = cost[0][0];
        sumCost[0][1] = cost[0][1];
        sumCost[0][2] = cost[0][2];

        for (int i = 1; i < sumCost.length; i++) {
            sumCost[i][0] = Math.min(sumCost[i - 1][1], sumCost[i - 1][2]) + cost[i][0];
            sumCost[i][1] = Math.min(sumCost[i - 1][0], sumCost[i - 1][2]) + cost[i][1];
            sumCost[i][2] = Math.min(sumCost[i - 1][0], sumCost[i - 1][1]) + cost[i][2];
        }

        output.write(Math.min(Math.min(sumCost[n - 1][0], sumCost[n - 1][1]), sumCost[n - 1][2]) + "");
        output.flush();
        output.close();
    }
}