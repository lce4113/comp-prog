// ––– "Qpwoeirut and the City" - Slowest Acceptable Solution –––
import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) solve();
	}

	static int costs(int[] buildings, int ind) {
		int a = buildings[ind - 1], b = buildings[ind], c = buildings[ind + 1];
		return Math.max(a, Math.max(b - 1, c)) - b + 1;
	}

	static void solve() {
		int n = sc.nextInt();

		int buildings[] = new int[n];
		for (int i = 0; i < n; i++) {
			int h = sc.nextInt();
			buildings[i] = h;
		}

		long totalHeight = 0;
		for (int i = 1; i < n - 1; i += 2) {
			totalHeight += costs(buildings, i);
		}

		if (n % 2 == 1) {
			System.out.println(totalHeight);
			return;
		}

		long minHeight = totalHeight;
		for (int i = n - 3; i >= 1; i -= 2) {
			totalHeight -= costs(buildings, i);
			totalHeight += costs(buildings, i + 1);
			minHeight = Math.min(minHeight, totalHeight);
		}

		System.out.println(minHeight);
	}
}
