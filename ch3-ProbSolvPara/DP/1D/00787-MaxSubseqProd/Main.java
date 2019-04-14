import java.util.Scanner;
import java.math.BigInteger;
// javac Main && java Main

class Calc {
	private int count;
	private int cur_count;
	private int cur_count_neg;
	private int state;

	public Calc() { reset(); };

	private void reset() {
		cur_count = 0;
		cur_count_neg = 0;
		state = 0;
		return;
	}

	public void calculate() {
		Scanner scanner_in = new Scanner(System.in);
		BigInteger prod_max = BigInteger.valueOf(0);
		BigInteger prod_pos = BigInteger.valueOf(0);
		BigInteger prod_neg = BigInteger.valueOf(0);
		count = 0;
		reset();
		while (scanner_in.hasNext()) {
			int number = scanner_in.nextInt();
			count++;
			cur_count++;
			if (state == 1) { state++; }
			if (number < 0) {
				cur_count_neg++;
				if ((cur_count_neg == 1) && (state == 0)) {
					state = 1;
				}
			}
			if (count == 1) {
				prod_max = BigInteger.valueOf(number);
				prod_pos = prod_max;
				prod_neg = prod_max;
			} 

			if (number == -999999) {
				// print max and reset rest
				System.out.println(prod_max.toString());
				count = 0;
				reset();
			} else if (number == 0) {
				prod_max = prod_max.max(BigInteger.valueOf(0));
				reset();
			} else if (cur_count == 1) {
				prod_pos = BigInteger.valueOf(number);
				prod_neg = prod_pos;
				prod_max = prod_max.max(prod_pos);
			} else {
				prod_pos = prod_pos.multiply(BigInteger.valueOf(number));
				if (state == 2) {
					prod_neg = BigInteger.valueOf(number);
					state++;
				} else {
					prod_neg = prod_neg.multiply(BigInteger.valueOf(number));
				}
				prod_max = prod_max.max(prod_pos.max(prod_neg));
			}
		}
		scanner_in.close(); 
	}
}

class Main {

	public static void main(String[] args) {
		Calc c = new Calc();
		c.calculate();      
		return;
	}
}