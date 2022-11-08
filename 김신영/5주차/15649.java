import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int n = Integer.parseInt(input.charAt(0) + "");
        int m = Integer.parseInt(input.charAt(2) + "");

        Queue<Stack<Integer>> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            Stack<Integer> stack = new Stack<>();
            stack.push(i);
            queue.add(stack);
        }

        while(!queue.isEmpty()) {
            Stack<Integer> temp = queue.poll();
            if (temp.size() == m) {
                printStack(temp);
                continue;
            }
            for (int i = 1; i <= n; i++) {
                Stack<Integer> copy = (Stack<Integer>) temp.clone();
                copy.push(i);
                if (!isNumberExist(temp, i)) {
                    if (copy.size() == m) {
                        printStack(copy);
                    } else {
                        queue.add(copy);
                    }
                }
            }
        }
    }

    public boolean isNumberExist(Stack<Integer> stack, int number) {
        if (stack.contains(number)) {
            return true;
        }
        return false;
    }

    public void printStack(Stack<Integer> stack) {
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }
        sb.reverse();
        String answer = sb.substring(1);
        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {
        Main nnm = new Main();
        nnm.solution();
    }
}
