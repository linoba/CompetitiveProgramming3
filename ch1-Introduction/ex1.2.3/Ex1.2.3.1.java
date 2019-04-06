import java.util.Scanner;
// javac Ex1.2.3.1.java && java Main

class Main {
	public static void main(String[] args) {
		Scanner scanner_in = new Scanner(System.in);
		double x = scanner_in.nextDouble();
		System.out.format("x = %7.3f%n", x);
		return;
	}
}