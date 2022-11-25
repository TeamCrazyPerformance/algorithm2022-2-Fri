    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.*;

    public class Main {
        public void solution() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(stringTokenizer.nextToken());
            PriorityQueue<int[]> priorityQueueLowest = new PriorityQueue<>(new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if (o1[0] == o2[0]) {
                        return o1[1] - o2[1];
                    }
                    return o1[0] - o2[0];
                }
            });

            for (int i = 0; i < n; i++) {
                int number = Integer.parseInt(br.readLine());

                if (number == 0) {
                    if (priorityQueueLowest.isEmpty()) {
                        System.out.println(0);
                    } else {
                        int[] smallest = priorityQueueLowest.poll();
                        System.out.println(smallest[1]);
                    }
                } else {
                    priorityQueueLowest.add(new int[]{Math.abs(number), number});
                }
            }
        }

        public static void main(String[] args) throws IOException {
            Main absHeap = new Main();
            absHeap.solution();
        }
    }
