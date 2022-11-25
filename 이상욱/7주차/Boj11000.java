import java.io.*;
import java.util.*;

public class Boj11000 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());

        // 수업 시작 시간을 기준으로 오름차순 정렬하는 우선순위 큐
        PriorityQueue<int[]> lecture = new PriorityQueue<>((arr1, arr2) -> {
            if (arr1[0] == arr2[0]) {
                return arr1[1] - arr2[1];
            } else {
                return arr1[0] - arr2[0];
            }});

        for (int i = 0; i < n; i++) {
            int[] arr = new int[2];
            StringTokenizer split = new StringTokenizer(input.readLine());
            arr[0] = Integer.parseInt(split.nextToken());
            arr[1] = Integer.parseInt(split.nextToken());
            lecture.add(arr);
        }
        input.close();

        // 수업 종료 시간이 들어오면 오름차순으로 정렬하는 우선순위 큐
        PriorityQueue<Integer> lectureEndTime = new PriorityQueue<>();

        // Exception 방지를 위해 첫 수업의 종료시간을 추가시킴
        lectureEndTime.add(lecture.poll()[1]);
        while (!lecture.isEmpty()) {
            int[] currentLecture = lecture.poll();
            // 현재 강의가 제일 일찍 끝나는 강의보다 늦게 시작할 경우 강의실 추가 안 됨
            if (currentLecture[0] >= lectureEndTime.peek()) {
                lectureEndTime.poll();
            }
            // 아닐 경우 강의실 추가 
            lectureEndTime.add(currentLecture[1]);
        }

        output.write(lectureEndTime.size() + "");
        output.flush();
        output.close();
    }
}