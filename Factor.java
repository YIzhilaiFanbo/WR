import java.util.Scanner;
public class Factor {
    public static void main(String args[]) {
        int n = new Scanner(System.in).nextInt();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                System.out.print(i + " ");
                n /= i--;
            }
        }
        System.out.print(n);
    }
}
