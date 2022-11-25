import java.io.*;
import java.util.*;

public class Boj1927 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        int queueSize = 1;
        int[] priorityQueue = new int[n + 1];

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(input.readLine());
            if (num > 0) {
                insert(priorityQueue, num, queueSize);
                queueSize++;
            }
            else if (num == 0 && queueSize > 1) {
                queueSize--;
                output.write(remove(priorityQueue, queueSize) + "\n");
            }
            else
                output.write("0\n");
            // output.write(Arrays.toString(priorityQueue) + " " + queueSize + "\n");
        }

        output.flush();
        output.close();
    }

    public static void insert(int[] priorityQueue, int num, int queueSize) {
        priorityQueue[queueSize] = num;
        for (int i = queueSize; i > 1; i /= 2) {
            if (num < priorityQueue[i / 2]) {
                priorityQueue[i] = priorityQueue[i / 2];
                priorityQueue[i / 2] = num;
            }
        }
        // System.out.println(Arrays.toString(priorityQueue) + " " + queueSize);
    }

    public static int remove(int[] priorityQueue, int queueSize) {
        int result = priorityQueue[1];
        int num = priorityQueue[queueSize];
        priorityQueue[1] = num;
        priorityQueue[queueSize] = 0;
        for (int i = 2; i < queueSize; i *= 2) {
            if (num > priorityQueue[i] || (num > priorityQueue[i + 1] && priorityQueue[i + 1] != 0)) {
                if (priorityQueue[i] > priorityQueue[i + 1] && priorityQueue[i + 1] != 0) {
                    priorityQueue[i / 2] = priorityQueue[i + 1];
                    priorityQueue[i + 1] = num;
                    i++;
                }
                else {
                    priorityQueue[i / 2] = priorityQueue[i];
                    priorityQueue[i] = num;
                }
            }
            else
                break;
            // System.out.println(Arrays.toString(priorityQueue) + " " + queueSize);
        }
        return result;
    }
}
