import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int count = 1;
    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int vertexNumber = Integer.parseInt(stringTokenizer.nextToken());
        int edgeNumber = Integer.parseInt(stringTokenizer.nextToken());
        int startNumber = Integer.parseInt(stringTokenizer.nextToken());
        Queue<Integer> queue = new LinkedList<>();
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

        queue.add(startNumber);
        visited[startNumber - 1] = true;

        while (!queue.isEmpty()) {
            int currentVertex = queue.poll();
            orderArray[currentVertex - 1] = count;
            count += 1;

            ArrayList<Integer> arrayList = edgeMap.get(currentVertex);

            for (int vertex:arrayList) {
                if (!visited[vertex - 1]) {
                    visited[vertex - 1] = true;
                    queue.add(vertex);
                }
            }
        }

        for (int i = 0; i < orderArray.length; i++) {
            System.out.println(orderArray[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        Main algorithmBfs = new Main();
        algorithmBfs.solution();
    }
}
