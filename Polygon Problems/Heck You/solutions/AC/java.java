import java.util.*;
import java.io.*;

public class Main {
	static Scanner io = new Scanner(System.in);
	public static void main(String[] args) {
		int MOD = 1_000_000_007;

		int n = io.nextInt();
		int t = io.nextInt();

		int[] c = new int[n];
		long[] pfs1 = new long[n + 1];
		long[] pfs2 = new long[n + 1];
		pfs1[0] = 0;
		pfs2[0] = 0;
		for (int i = 0; i < n; i++) {
			c[i] = io.nextInt();
			pfs1[i + 1] = pfs1[i] + c[i];
			pfs2[i + 1] = pfs2[i] + (1 + i) * c[i];
		}

		for (int i = 0; i < t; i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			int r = io.nextInt();

			long hugs1 = pfs1[b] - pfs1[a - 1];
			long hugs2 = pfs2[b] - pfs2[a - 1];
			long scaledHugs = hugs2 * r - hugs1 * (r - 1);
			long subRect = hugs1 * (a - 1) * r;
    		long ans = (scaledHugs - subRect) % MOD;

		    System.out.println(ans);
  		}

		io.close(); // make sure to include this line -- closes io and flushes the output
	}
}
