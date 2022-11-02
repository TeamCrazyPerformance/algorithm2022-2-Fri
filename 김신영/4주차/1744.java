import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    int temp;
    int answer;
    int zeroNum;

    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int number = Integer.parseInt(br.readLine());
        Integer[] numberArray = new Integer[number];

        for (int i = 0; i < number; i++) {
            numberArray[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(numberArray);

        int arrayNumber = numberArray.length;
        answer = 0;
        temp = 0;

        for (int i = arrayNumber - 1; i > -1; i--) {
            int current = numberArray[i];

            if (current > 0) {
                calculate(current);
            } else if (current == 0) {
                zeroNum += 1;
            } else {
                break;
            }
        }

        finishCalculate();

        for (int i = 0; i < arrayNumber; i++) {
            int current = numberArray[i];

            if (current < 0) {
                calculate(current);
            } else {
                break;
            }
        }
        finishCalculate();

        return answer;
    }

    private void calculate(int current) {
        if (temp == 0) {
            temp = current;
        } else {
            int mul = temp * current;
            int sum = temp + current;
            if (mul > sum) {
                answer += mul;
                temp = 0;
            } else {
                if (zeroNum > 0 && current < 0) {
                    temp = current;
                    zeroNum -= 1;
                } else {
                    answer += temp;
                    temp = current;
                }
            }
        }
    }

    private void finishCalculate() {
        if (temp >= 0 || zeroNum == 0) {
            answer += temp;
            temp = 0;
        }
    }

    public static void main(String[] args) throws Exception {
        Main bindingNumber = new Main();
        System.out.println(bindingNumber.solution());
    }

}
