// ––– "Grid Split" - Solution (Java) –––
import java.util.Scanner;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int t = sc.nextInt();
    for (int i = 0; i < t; i++) solve();
  }

  static void solve() {
    int n = sc.nextInt();

    long pfs_a[] = new long[n+1];
    long pfs_b[] = new long[n+1];
    pfs_a[0] = 0; pfs_b[0] = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
      int h = sc.nextInt();
      pfs_a[i + 1] = pfs_a[i] + h;
      sum += h;
    }
    for (int i = 0; i < n; i++) {
      int h = sc.nextInt();
      pfs_b[i + 1] = pfs_b[i] + h;
      sum += h;
    }

    if (sum % 2 == 1) {
      System.out.println(0);
      return;
    }

    long half_sum = sum / 2;
    int ans = 0;
    for (int i = 0, k = n; i <= n && k >= 0;) {
      long pfs_sum = pfs_a[i] + pfs_b[k];
      if (pfs_sum < half_sum) { i++; }
      else if (pfs_sum > half_sum) { k--; }
      else { i++; k--; ans++; }
    }

    System.out.println(ans);
  }
}
