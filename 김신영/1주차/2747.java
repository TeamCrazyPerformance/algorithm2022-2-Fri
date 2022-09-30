import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int smaller = 0;
        int bigger = 1;
        int count = 1;

        if (n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        while(count != n) {
            count++;
            int temp = Fibo(smaller, bigger);
            smaller = bigger;
            bigger = temp;
        }
        return bigger;
    }

    public int Fibo(int smaller, int bigger) {
        return smaller + bigger;
    }

    public static void main(String[] args) throws Exception {
        System.out.println(new Main().solution());
    }
}
