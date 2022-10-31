import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public String solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] nString = br.readLine().split(" ");
        Integer[] nArray = new Integer[n];
        for (int i = 0; i < n; i++) {
            nArray[i] = Integer.parseInt(nString[i]);
        }
        int m = Integer.parseInt(br.readLine());
        String[] mString = br.readLine().split(" ");
        int[] mArray = new int[m];
        for (int i = 0; i < m; i++) {
            mArray[i] = Integer.parseInt(mString[i]);
        }

        //Arrays.sort(nArray);

        HashSet<Integer> set = new HashSet<Integer>(Arrays.asList(nArray));

        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < m; i++) {
            if (set.contains(mArray[i])) {
                answer.append(" " + 1);
            } else {
                answer.append(" " + 0);
            }
        }


        /*
        for (int i = 0; i < m; i++) {
            if (binarySearch(mArray[i], nArray)) {
                answer += " " + 1;
            } else {
                answer += " " + 0;
            }
        }
         */
        return answer.substring(1);
    }

    public static void main(String[] args) throws Exception {
        Main numberCard = new Main();
        System.out.println(numberCard.solution());
    }

    private boolean binarySearch(int number, int[] numArray) {
        int right = numArray.length - 1;
        int left = 0;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (numArray[mid] > number) {
                right = mid - 1;
                mid = (left + right) / 2;
            } else if (numArray[mid] < number) {
                left = mid + 1;
                mid = (left + right) / 2;
            } else {
                return true;
            }
        }
        return false;
    }
}
