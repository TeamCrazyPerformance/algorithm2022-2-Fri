import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int answer = 0;
        int position = (int) (Math.log10(n));
        /*
        String string = "";

        for (int i = 1; i < n + 1; i++) {
            string += i;
        }

        return string.length();

         */
        for (int i = 0; i < position; i++) {
            answer += (Math.pow(10, i + 1) - Math.pow(10, i)) * (i + 1);
        }

        answer += (n - Math.pow(10, position) + 1) * (position + 1);
        return answer;
    }

    public static void main(String[] args) throws Exception {
        System.out.println(new Main().solution());
    }
}
