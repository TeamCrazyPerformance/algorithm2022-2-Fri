import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    int m, n, k;

    public void printQueue(Queue<int[]> queue) {
        StringBuffer sb = new StringBuffer();
        for (int[] location:queue) {
            sb.append("[" + location[0] +" , " + location[1] + "]").append(", ");
        }
        System.out.println(sb);
    }

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int testNumber = Integer.parseInt(stringTokenizer.nextToken());
        for (int i = 0; i < testNumber; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            m = Integer.parseInt(stringTokenizer.nextToken());
            n = Integer.parseInt(stringTokenizer.nextToken());
            k = Integer.parseInt(stringTokenizer.nextToken());
            boolean[][] map = new boolean[m + 1][n + 1];
            int currentX = 0;
            int currentY = 0;
            for (int j = 0; j < k; j++) {
                stringTokenizer = new StringTokenizer(br.readLine());
                currentX = Integer.parseInt(stringTokenizer.nextToken());
                currentY = Integer.parseInt(stringTokenizer.nextToken());
                map[currentX][currentY] = true;
            }

            Queue<int[]> queue = new LinkedList<>();
            int[] cabbageLocation = findCabbageLocation(map);
            queue.add(cabbageLocation);
            map[cabbageLocation[0]][cabbageLocation[1]] = false;
            k -= 1;
            int count = 1;

            while (k > 0) {
                //printQueue(queue);
                int[] wormLocation = queue.poll();

                count = moveWorm(wormLocation, queue, count, map);

            }

            System.out.println(count);
        }
    }

    public int moveWorm(int[] wormLocation, Queue<int[]> queue, int count, boolean[][] map) {
        int wormX = wormLocation[0];
        int wormY = wormLocation[1];
        boolean canMove = false;

        int[] xDiff = {-1, 1, 0, 0};
        int[] yDiff = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int changedX = wormX + xDiff[i];
            int changedY = wormY + yDiff[i];
            int[] changedLocation = new int[]{changedX, changedY};

            if (changedX > m || changedY > n || changedX < 0 || changedY < 0) {
                continue;
            }

            if (map[changedX][changedY]) {
                //System.out.println(changedLocation[0] +", " + changedLocation[1]);
                map[changedX][changedY] = false;
                k -= 1;
                queue.add(changedLocation);
                canMove = true;
            }
        }

        if (!canMove && k > 0 && queue.isEmpty()) {
            count += 1;
            int[] cabbageLocation = findCabbageLocation(map);
            queue.add(cabbageLocation);
            map[cabbageLocation[0]][cabbageLocation[1]] = false;
            k -= 1;
        }

        return count;
    }

    private int[] findCabbageLocation(boolean[][] map) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j]) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[0];
    }

    public static void main(String[] args) throws IOException {
        Main organicCabbage = new Main();
        organicCabbage.solution();
    }
}
