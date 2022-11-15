import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int number = Integer.parseInt(stringTokenizer.nextToken());
        int[] redArray = new int[number];
        int[] greenArray = new int[number];
        int[] blueArray = new int[number];
        for (int i = 0; i < number; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            redArray[i] = Integer.parseInt(stringTokenizer.nextToken());
            greenArray[i] = Integer.parseInt(stringTokenizer.nextToken());
            blueArray[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        int[][] sum = new int[number][3];
        for (int i = 0; i < number; i++) {
            if (i == 0) {
                sum[0] = new int[]{redArray[0], greenArray[0], blueArray[0]};
            } else {
                sum[i][0] = redArray[i] + Math.min(sum[i - 1][1], sum[i - 1][2]);
                sum[i][1] = greenArray[i] + Math.min(sum[i - 1][0], sum[i - 1][2]);
                sum[i][2] = blueArray[i] + Math.min(sum[i - 1][0], sum[i - 1][1]);
            }
        }
        int sumLength = sum.length - 1;

        return Math.min(Math.min(sum[sumLength][0], sum[sumLength][1]), sum[sumLength][2]);
    }

    public static void main(String[] args) throws Exception {
        Main rgbStreet = new Main();
        System.out.println(rgbStreet.solution());
    }
}
