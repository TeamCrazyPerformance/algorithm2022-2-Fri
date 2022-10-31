import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] nString = br.readLine().split(" ");
        Integer[] nArray = new Integer[n];
        int maxNumber = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp = Integer.parseInt(nString[i]);
            nArray[i] = temp;
            maxNumber = Math.max(maxNumber, temp);
            sum += temp;
        }
        int m = Integer.parseInt(br.readLine());

        Arrays.sort(nArray);

        int nLength = nArray.length;
        int temp = nArray.length - 1;

        while (m < sum) {
            if (temp == 0) {
                maxNumber = m / n;
                sum = m;
                continue;
            }
            if (nArray[temp - 1] == maxNumber) {
                temp = Arrays.asList(nArray).indexOf(maxNumber);
                int number = nLength - temp;
                sum -= number;
                maxNumber -= 1;
                continue;
            }
            int number = nLength - temp;
            if (maxNumber - 1 == nArray[temp - 1] && temp > 0) {
                temp -= 1;
            }
            sum -= number;
            maxNumber -= 1;
        }

        return maxNumber;
    }

    public static void main(String[] args) throws Exception {
        Main budget = new Main();
        System.out.println(budget.solution());
    }
}
