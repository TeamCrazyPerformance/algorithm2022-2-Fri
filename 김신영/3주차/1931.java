import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    int n;
    int last = 0;

    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int[][] meetingTime = new int[n][2];
        int answer = 0;

        for (int i = 0; i < n; i++) {
            String[] temp = br.readLine().split(" ");
            meetingTime[i][0] = Integer.parseInt(temp[0]);
            meetingTime[i][1] = Integer.parseInt(temp[1]);
        }

        Arrays.sort(meetingTime, (o1, o2) -> {
           if (o1[1] == o2[1]) {
               return Integer.compare(o1[0], o2[0]);
           } else {
               return Integer.compare(o1[1], o2[1]);
           }
        });

        for (int i = 0; i < n; i++) {
            int start = meetingTime[i][0];
            int end = meetingTime[i][1];
            if (!isMeeting(start)) {
                addMeeting(end);
                answer += 1;
            }
        }

        return answer;
    }

    private boolean isMeeting(int start) {
        return start < last;
    }

    private boolean addMeeting(int end) {
        last = end;
        return false;
    }

    public static void main(String[] args) throws Exception {
        Main setMeetingRoom = new Main();
        System.out.println(setMeetingRoom.solution());
    }
}
