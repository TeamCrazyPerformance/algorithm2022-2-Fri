import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Stack;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int count = 0;

        HashSet<Integer> numberSet = new HashSet<>();

        for (int i = 1; i < 10000; i++) {
            if (calCount(i) > n) {
                count = i;
                break;
            }
        }

        for (int i = 1; i < count + 1; i++) {
            calNumbers(i, numberSet);
        }

        ArrayList<Integer> numberList = new ArrayList<>(numberSet);
        Collections.sort(numberList);

        return numberList.get(n - 1);
    }

    public int calCount(int number) {
        int beforeString = (int) (Math.pow(10, number - 1) - 10);
        int afterString = (int) (Math.pow(10, number - 1) - 1);
        int beforeSum = 0;
        for (int i = 1; i < number; i++) {
            beforeSum += calCount(i);
        }
        return beforeString * number + afterString * 1 - beforeSum;
    }

    public void calNumbers(int number, HashSet<Integer> numberSet) {
        String defaultNumber = "666";
        Stack<String> stack = new Stack<>();
        stack.add(defaultNumber);

        while(stack.size() > 0) {
            String string = stack.pop();

            if (string.length() - 3 == number) {
                numberSet.add(Integer.parseInt(string));
                continue;
            }

            for (int i = 0; i < 10; i++) {
                stack.add(i + string);
                stack.add(string + i);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solution());
    }
}
