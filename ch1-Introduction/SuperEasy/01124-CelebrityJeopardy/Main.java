import java.util.Scanner;
// javac Main && java Main

class Main {
	public static void main(String[] args) {
		Scanner scanner_in = new Scanner(System.in);

		while (scanner_in.hasNext()) {
			String str_in = scanner_in.nextLine();
			System.out.println(str_in);
		}
		scanner_in.close();            
		return;
	}
}