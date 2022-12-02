import java.util.*;
import java.io.*;

public class Boj24479 {
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
        int[] visitCount = {1};

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

        DFS(line, visitedOrder, r, visitCount);

        for (int i = 1; i < visitedOrder.length; i++) {
            output.write(visitedOrder[i] + "\n");
        }
        output.flush();
        output.close();
    }

    public static void DFS(final ArrayList<Integer>[] line, int[] visitedOrder, int startPoint, int[] visitCount) {
        visitedOrder[startPoint] = visitCount[0]++;
        for (int i = 0; i < line[startPoint].size(); i++) {
            if (visitedOrder[line[startPoint].get(i)] == 0) {
                DFS(line, visitedOrder, line[startPoint].get(i), visitCount);
            }
        }
    }
}