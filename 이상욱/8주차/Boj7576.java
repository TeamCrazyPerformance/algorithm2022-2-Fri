import java.util.*;
import java.io.*;

public class Boj7576 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer split = new StringTokenizer(input.readLine());
        int m = Integer.parseInt(split.nextToken());
        int n = Integer.parseInt(split.nextToken());
        int day = 0;
        int tomatoCount = 0;

        boolean[][] isTomato = new boolean[n][m];
        ArrayList<Integer> ripedTomatoX = new ArrayList<>();
        ArrayList<Integer> ripedTomatoY = new ArrayList<>();

        for (int i = 0; i < isTomato.length; i++) {
            StringTokenizer splitArr = new StringTokenizer(input.readLine());
            for (int j = 0; j < isTomato[i].length; j++) {
                int temp = Integer.parseInt(splitArr.nextToken());
                if (temp == 0) {
                    isTomato[i][j] = true;
                    tomatoCount++;
                }
                else if (temp == 1) {
                    ripedTomatoX.add(j);
                    ripedTomatoY.add(i);
                }
            }
        }
        input.close();

        Queue<Integer> queueX = new LinkedList<>();
        Queue<Integer> queueY = new LinkedList<>();
        Queue<Integer> queueCount = new LinkedList<>();

        for (int i = 0; i < ripedTomatoX.size(); i++) {
            queueX.add(ripedTomatoX.get(i));
            queueY.add(ripedTomatoY.get(i));
            queueCount.add(day);
        }

        while (queueX.size() > 0) {
            day = queueCount.remove();
            int x = queueX.remove();
            int y = queueY.remove();

            if (x < isTomato[y].length - 1 && isTomato[y][x + 1]) {
                queueX.add(x + 1);
                queueY.add(y);
                isTomato[y][x + 1] = false;
                queueCount.add(day + 1);
                tomatoCount--;
            }
            if (y < isTomato.length - 1 && isTomato[y + 1][x]) {
                queueX.add(x);
                queueY.add(y + 1);
                isTomato[y + 1][x] = false;
                queueCount.add(day + 1);
                tomatoCount--;
            }
            if (y > 0 && isTomato[y - 1][x]) {
                queueX.add(x);
                queueY.add(y - 1);
                isTomato[y - 1][x] = false;
                queueCount.add(day + 1);
                tomatoCount--;
            }
            if (x > 0 && isTomato[y][x - 1]) {
                queueX.add(x - 1);
                queueY.add(y);
                isTomato[y][x - 1] = false;
                queueCount.add(day + 1);
                tomatoCount--;
            }

            // output.write(x + " " + y + " " + day + "\n");
        }

        if (tomatoCount == 0) {
            output.write(day + "");
        } else {
            output.write("-1");
        }
        output.flush();
        output.close();
    }
}