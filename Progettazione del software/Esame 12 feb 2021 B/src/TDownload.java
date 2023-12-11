import java.util.Scanner;

public class TDownload implements Runnable {

	Scanner	in;
	Window	frame;

	public TDownload(Scanner in, Window frame) {
		this.in = in;
		this.frame = frame;
	}

	private void helper(String s) {
		int colum;
		int n;
		int splitIndex;
		
		splitIndex = s.indexOf(":");
		colum = Integer.parseInt(s.substring(0, splitIndex)) - 1;
		n = Integer.parseInt(s.substring(splitIndex + 1, s.length()));
		frame.selectBox(colum, n);
	}

	@Override
	public void run() {
		String s;

		while (true) {
			s = in.nextLine();
			
			if (s.equals("done")) {
				frame.showResults();
				break ;
			} else if (s.equals("interrupted")) {
				frame.showInterrupt();
				break ;
			} else {
				helper(s);
			}
			
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				break;
			}
		}

	}

}
