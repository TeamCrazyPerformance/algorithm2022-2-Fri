import java.util.*;
import java.io.*;

public class Boj1012 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(input.readLine());

        for (int i = 0; i < t; i++) {
            StringTokenizer split = new StringTokenizer(input.readLine());
            int m = Integer.parseInt(split.nextToken());
            int n = Integer.parseInt(split.nextToken());
            int k = Integer.parseInt(split.nextToken());

            boolean[][] isPlanted = new boolean[n][m];
            int earthWormCount = 0;

            for (int j = 0; j < k; j++) {
                StringTokenizer splitLine = new StringTokenizer(input.readLine());
                int plantedCol = Integer.parseInt(splitLine.nextToken());
                int plantedRow = Integer.parseInt(splitLine.nextToken());
                isPlanted[plantedRow][plantedCol] = true;
            }

            for (int y = 0; y < isPlanted.length; y++) {
                for (int x = 0; x < isPlanted[y].length; x++) {
                    if (isPlanted[y][x]) {
                        earthWormCount += DFS(isPlanted, x, y);
                    }
                }
            }
            output.write(earthWormCount + "\n");
        }

        input.close();
        output.flush();
        output.close();
    }

    public static int DFS(boolean isPlanted[][], int x, int y) {
        isPlanted[y][x] = false;
        if (y > 0 && isPlanted[y - 1][x]) {
            DFS(isPlanted, x, y - 1);
        }
        if (x > 0 && isPlanted[y][x - 1]) {
            DFS(isPlanted, x - 1, y);
        }
        if (y < isPlanted.length - 1 && isPlanted[y + 1][x]) {
            DFS(isPlanted, x, y + 1);
        }
        if (x < isPlanted[y].length - 1 && isPlanted[y][x + 1]) {
            DFS(isPlanted, x + 1, y);
        }

        return 1;
    }
}