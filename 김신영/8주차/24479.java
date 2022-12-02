import java.io.*;
import java.util.*;

public class Main {
    int count = 1;
    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int vertexNumber = Integer.parseInt(stringTokenizer.nextToken());
        int edgeNumber = Integer.parseInt(stringTokenizer.nextToken());
        int startNumber = Integer.parseInt(stringTokenizer.nextToken());
        boolean[] visited = new boolean[vertexNumber];
        HashMap<Integer, ArrayList<Integer>> edgeMap = new HashMap<>();
        int[] orderArray = new int[vertexNumber];

        for (int i = 0; i < edgeNumber; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int vertex1 = Integer.parseInt(stringTokenizer.nextToken());
            int vertex2 = Integer.parseInt(stringTokenizer.nextToken());
            if (!edgeMap.containsKey(vertex1)) {
                edgeMap.put(vertex1, new ArrayList<>());
            }
            edgeMap.get(vertex1).add(vertex2);

            if (!edgeMap.containsKey(vertex2)) {
                edgeMap.put(vertex2, new ArrayList<>());
            }
            edgeMap.get(vertex2).add(vertex1);
        }

        for (ArrayList arrayList: edgeMap.values()) {
            Collections.sort(arrayList);
        }

        orderArray[startNumber - 1] = 1;

        dfs(visited, startNumber, edgeMap, orderArray);

        for (int i = 0; i < orderArray.length; i++) {
            System.out.println(orderArray[i]);
        }
    }

    public void dfs(boolean[] visited, int visitVertex, HashMap<Integer, ArrayList<Integer>> edgeMap, int[] orderArray) {
        visited[visitVertex - 1] = true;
        if (!edgeMap.containsKey(visitVertex)) {
            return;
        }
        ArrayList<Integer> arrayList = edgeMap.get(visitVertex);

        for (int edge:arrayList) {
            if (!visited[edge - 1]) {
                count += 1;
                orderArray[edge - 1] = count;
                dfs(visited, edge, edgeMap, orderArray);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main algorithmDfs = new Main();
        algorithmDfs.solution();
    }
}
