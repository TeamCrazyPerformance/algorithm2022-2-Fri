import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] array = new int[7];
        int leastNumber = Integer.MAX_VALUE;
        int sumOdd = 0;

        for (int i = 0; i < 7; i++) {
            array[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < 7; i++) {
            if(findOdd(array[i])) {
                sumOdd += array[i];
                if (array[i] < leastNumber) {
                    leastNumber = array[i];
                }
            }
        }

        if (sumOdd > 0) {
            System.out.println(sumOdd);
            System.out.println(leastNumber);
        } else {
            System.out.println(-1);
        }

    }

    public boolean findOdd(int number) {
        if (number % 2 == 1) {
            return true;
        }
        return false;
    }
    public static void main(String[] args) throws Exception {
        Main odd = new Main();
        odd.solution();
    }
}
