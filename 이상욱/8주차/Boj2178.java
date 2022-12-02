import java.util.*;
import java.io.*;

public class Boj2178 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer split = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(split.nextToken());
        int m = Integer.parseInt(split.nextToken());
        int count = 0;

        boolean[][] canMove = new boolean[n + 1][m + 1];

        for (int y = 0; y < canMove.length - 1; y++) {
            String maze = input.readLine();
            for (int x = 0; x < canMove[y].length - 1; x++) {
                if (maze.charAt(x) == '1') {
                    canMove[y + 1][x + 1] = true;
                }
            }
        }
        input.close();

        Queue<Integer> queueX = new LinkedList<>();
        Queue<Integer> queueY = new LinkedList<>();
        Queue<Integer> queueCount = new LinkedList<>();

        queueX.add(1);
        queueY.add(1);
        count++;
        queueCount.add(count);
        canMove[1][1] = false;
        while (queueX.size() > 0) {
            int x = queueX.remove();
            int y = queueY.remove();
            count = queueCount.remove();

            if (x < canMove[y].length - 1 && canMove[y][x + 1]) {
                queueX.add(x + 1);
                queueY.add(y);
                canMove[y][x + 1] = false;
                queueCount.add(count + 1);
            }
            if (y < canMove.length - 1 && canMove[y + 1][x]) {
                queueX.add(x);
                queueY.add(y + 1);
                canMove[y + 1][x] = false;
                queueCount.add(count + 1);
            }
            if (y > 0 && canMove[y - 1][x]) {
                queueX.add(x);
                queueY.add(y - 1);
                canMove[y - 1][x] = false;
                queueCount.add(count + 1);
            }
            if (x > 0 && canMove[y][x - 1]) {
                queueX.add(x - 1);
                queueY.add(y);
                canMove[y][x - 1] = false;
                queueCount.add(count + 1);
            }

            // output.write(x + " " + y + " " + count + "\n");
            if (x == m && y == n) {
                break;
            }
        }

        output.write(count + "");
        output.flush();
        output.close();
    }
}