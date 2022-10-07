import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            if (getDecomposeSum(i) == n) {
                return i;
            }
        }
        return 0;
    }

    public int getDecomposeSum(int number) {
        int sum = number;
        while(number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solution());
    }
}
