import java.io.*;

public class Boj9663_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        input.close();
        boolean[][] board = new boolean[n][n];
        int[] arr = new int[n];

        output.write(backTracking(n * n, n, arr, board, 0) + "");
        output.flush();
        output.close();
    }

    public static boolean canPlace(int i, int j, boolean[][] board) {
        for (int k = 0; k < board.length; k++) {
            if (i >= k && j >= k)
                if (board[i - k][j - k] == true)
                    return false;
            if (i + k < board.length && j + k < board.length)
                if (board[i + k][j + k] == true)
                    return false;
            if (i >= k && j + k < board.length)
                if (board[i - k][j + k] == true)
                    return false;
            if (i + k < board.length && j >= k)
                if (board[i + k][j - k] == true)
                    return false;
            if (board[k][j] == true || board[i][k] == true)
                return false;
        }
        return true;
    }

    public static long backTracking(int n, int m, int[] arr, boolean[][] board, long count) {
        int p;
        if (arr.length == m)
            p = 0;
        else
            p = arr.length - m - 1;

        for (int i = p; i < n; i++) {
            if ((m < arr.length && arr[arr.length - m - 1] >= i)
                || !canPlace(i / arr.length, i % arr.length, board))
                continue;
            arr[arr.length - m] = i;
            board[i / arr.length][i % arr.length] = true;
            if (m == 1)
                count++;
            else
                count = backTracking(n, m - 1, arr, board, count);
            board[i / arr.length][i % arr.length] = false;
        }
        return count;
    }
}
