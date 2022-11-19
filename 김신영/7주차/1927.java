import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stringTokenizer.nextToken());
        PriorityQueue<Integer> priorityQueueLowest = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int number = Integer.parseInt(stringTokenizer.nextToken());
            if (number == 0) {
                if (priorityQueueLowest.size() == 0) {
                    System.out.println(0);
                } else {
                    System.out.println(priorityQueueLowest.poll());
                }
            } else {
                priorityQueueLowest.add(number);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main meanHeap = new Main();
        meanHeap.solution();
    }
}
