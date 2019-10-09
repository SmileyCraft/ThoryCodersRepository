
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger bi = new BigInteger("" + Integer.parseInt(st.nextToken()));
		System.out.println(bi.multiply(bi));
	}
}
