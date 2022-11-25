import java.io.*;
import java.util.*;

public class Main {
    public int solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stringTokenizer.nextToken());
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        int[][] meetingArray = new int[n][2];

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; j++) {
                meetingArray[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }

        Arrays.sort(meetingArray, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }
                return o1[0] - o2[0];
            }
        });

        priorityQueue.add(meetingArray[0][1]);

        for (int i = 1; i < n; i++) {
            int[] meeting = meetingArray[i];
            int meetingStart = meeting[0];
            int meetingEnd = meeting[1];
            if (priorityQueue.peek() <= meetingStart) {
                priorityQueue.poll();
            }
            priorityQueue.add(meetingEnd);
        }

        return priorityQueue.size();
    }

    public static void main(String[] args) throws IOException {
        Main meetingRoom = new Main();
        System.out.println(meetingRoom.solution());
    }
}
