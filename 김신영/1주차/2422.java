import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PrintStar {
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int wholeStar = n * 2 - 1;

        for(int i = 1; i < n + 1; i++) {
            int currentStar = i * 2 - 1;
            int spaceNumber = (wholeStar - currentStar) / 2;

            String currentString = "";
            for(int j = 0; j < spaceNumber; j++) {
                currentString += " ";
            }
            for(int j = 0; j < currentStar; j++) {
                currentString += "*";
            }
            System.out.println(currentString);
        }
    }

    public static void main(String[] args) throws Exception {
        new PrintStar().solution();
    }
}
