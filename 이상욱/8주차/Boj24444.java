import java.util.*;
import java.io.*;

public class Boj24444 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer split = new StringTokenizer(input.readLine());

        int n = Integer.parseInt(split.nextToken());
        int m = Integer.parseInt(split.nextToken());
        int r = Integer.parseInt(split.nextToken());

        // 간선 저장
        ArrayList<Integer>[] line = new ArrayList[n + 1];
        for (int i = 0; i < line.length; i++) {
            line[i] = new ArrayList<Integer>();
        }
 
        int[] visitedOrder = new int[n + 1]; // 방문 순서 저장
        int visitCount = 1;
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            StringTokenizer splitLine = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(splitLine.nextToken());
            int end = Integer.parseInt(splitLine.nextToken());
            line[start].add(end);
            line[end].add(start);
        }
        input.close();

        for (int i = 0; i < line.length; i++) {
            if (line[i].size() > 1)
                line[i].sort(Comparator.naturalOrder());
        }

        // BFS
        visitedOrder[r] = visitCount++;
        queue.add(r);
        while (queue.size() > 0) {
            int currentPoint = queue.remove();
            for (int i = 0; i < line[currentPoint].size(); i++) {
                int nearbyPoint = line[currentPoint].get(i);
                if (visitedOrder[nearbyPoint] == 0) {
                    visitedOrder[nearbyPoint] = visitCount++;
                    queue.add(nearbyPoint);
                }
            }
        }

        for (int i = 1; i < visitedOrder.length; i++) {
            output.write(visitedOrder[i] + "\n");
        }
        output.flush();
        output.close();
    }
}