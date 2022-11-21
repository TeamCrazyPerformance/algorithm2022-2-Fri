import java.io.*;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class SayMiddle {
    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(stringTokenizer.nextToken());
        PriorityQueue<Integer> lowerPriorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> higherPriorityQueue = new PriorityQueue<>();
        int lowerPriorityQueueCount = 0;
        int higherPriorityQueueCount = 0;

        for (int i = 0; i < n; i++) {
            int input = Integer.parseInt(br.readLine());

            if (i >= 2 && input < higherPriorityQueue.peek()) {
                lowerPriorityQueue.add(input);
                lowerPriorityQueueCount += 1;
            } else {
                higherPriorityQueue.add(input);
                higherPriorityQueueCount += 1;
            }

            if (higherPriorityQueueCount - lowerPriorityQueueCount > 2) {
                lowerPriorityQueue.add(higherPriorityQueue.poll());
                higherPriorityQueueCount -= 1;
                lowerPriorityQueueCount += 1;
            }else if (lowerPriorityQueueCount >= higherPriorityQueueCount) {
                higherPriorityQueue.add(lowerPriorityQueue.poll());
                higherPriorityQueueCount += 1;
                lowerPriorityQueueCount -= 1;
            }

            bw.write(higherPriorityQueue.peek() + "\n");
        }
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        SayMiddle sayMiddle = new SayMiddle();
        sayMiddle.solution();
    }
}
