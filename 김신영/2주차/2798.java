import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] string = br.readLine().split(" ");
        int cardNumber = Integer.parseInt(string[0]);
        final int m = Integer.parseInt(string[1]);

        String[] cardsInString = br.readLine().split(" ");
        int[] cards = new int[cardNumber];
        for(int i = 0; i < cardNumber; i++) {
            cards[i] = Integer.parseInt(cardsInString[i]);
        }

        int answer = 0;
        for (int i = 0; i < cardNumber; i++) {
            for (int j = i + 1; j < cardNumber; j++) {
                for (int k = j + 1; k < cardNumber; k++) {
                    int newNum = cards[i] + cards[j] + cards[k];
                    if (m >= newNum && newNum > answer) {
                        answer = newNum;
                    }
                }
            }
        }
        if (answer == 0) {
            return -1;
        }
        return answer;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solution());
    }
}
