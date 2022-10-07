import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(br.readLine());
        int answer = 0;

        for (int i = 1; i < input + 1; i++) {
            if (isSequence(i)) {
                answer += 1;
            }
        }
        return answer;
    }

    private boolean isSequence(int number) {
        int before = number % 10;
        number = number / 10;
        int current = number % 10;
        int diff = before - current;
        while(number >= 10) {
            before = current;
            number = number / 10;
            current = number % 10;
            if (before - diff != current) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solution());
    }
}
