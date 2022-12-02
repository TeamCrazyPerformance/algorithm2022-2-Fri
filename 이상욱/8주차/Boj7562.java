import java.util.*;
import java.io.*;

public class Boj7562 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));


        int t = Integer.parseInt(input.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(input.readLine());
            boolean[][] visited = new boolean[n][n];
            int count = 0;

            StringTokenizer split = new StringTokenizer(input.readLine());
            int startPointRow = Integer.parseInt(split.nextToken());
            int startPointCol = Integer.parseInt(split.nextToken());
            split = new StringTokenizer(input.readLine());
            int endPointRow = Integer.parseInt(split.nextToken());
            int endPointCol = Integer.parseInt(split.nextToken());

            Queue<Integer> queueX = new LinkedList<>();
            Queue<Integer> queueY = new LinkedList<>();
            Queue<Integer> queueCount = new LinkedList<>();

            queueX.add(startPointCol);
            queueY.add(startPointRow);
            queueCount.add(count);
            visited[startPointCol][startPointRow] = true;
            while (queueX.size() > 0) {
                int x = queueX.remove();
                int y = queueY.remove();
                count = queueCount.remove();
                
                if (x < visited[y].length - 2) {
                    if (y < visited.length - 1 && !visited[y + 1][x + 2]) {
                        queueX.add(x + 2);
                        queueY.add(y + 1);
                        visited[y + 1][x + 2] = true;
                        queueCount.add(count + 1);
                    }
                    if (y > 0 && !visited[y - 1][x + 2]) {
                        queueX.add(x + 2);
                        queueY.add(y - 1);
                        visited[y - 1][x + 2] = true;
                        queueCount.add(count + 1);
                    }
                }
                if (x < visited[y].length - 1) {
                    if (y < visited.length - 2 && !visited[y + 2][x + 1]) {
                        queueX.add(x + 1);
                        queueY.add(y + 2);
                        visited[y + 2][x + 1] = true;
                        queueCount.add(count + 1);
                    }
                    if (y > 1 && !visited[y - 2][x + 1]) {
                        queueX.add(x + 1);
                        queueY.add(y - 2);
                        visited[y - 2][x + 1] = true;
                        queueCount.add(count + 1);
                    }
                }
                if (x > 0) {
                    if (y < visited.length - 2 && !visited[y + 2][x - 1]) {
                        queueX.add(x - 1);
                        queueY.add(y + 2);
                        visited[y + 2][x - 1] = true;
                        queueCount.add(count + 1);
                    }
                    if (y > 1 && !visited[y - 2][x - 1]) {
                        queueX.add(x - 1);
                        queueY.add(y - 2);
                        visited[y - 2][x - 1] = true;
                        queueCount.add(count + 1);
                    }
                }
                if (x > 1) {
                    if (y < visited.length - 1 && !visited[y + 1][x - 2]) {
                        queueX.add(x - 2);
                        queueY.add(y + 1);
                        visited[y + 1][x - 2] = true;
                        queueCount.add(count + 1);
                    }
                    if (y > 0 && !visited[y - 1][x - 2]) {
                        queueX.add(x - 2);
                        queueY.add(y - 1);
                        visited[y - 1][x - 2] = true;
                        queueCount.add(count + 1);
                    }
                }

                // output.write(x + " " + y + " " + count + "\n");
                if (x == endPointCol && y == endPointRow) {
                    break;
                }
            }
            output.write(count + "\n");
        }

        input.close();
        output.flush();
        output.close();
    }
}
