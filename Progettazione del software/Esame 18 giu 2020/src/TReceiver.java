import java.util.Scanner;

public class TReceiver implements Runnable {
	
	private Window	frame;
	private Scanner	in;
	
	public TReceiver(Window frame, Scanner in) {
		this.frame = frame;
		this.in = in;
		
	}
	
	
	private void setBtn(String s) {
		String[] 	info;
		int			r;
		int			c;
		int			n;

		info = s.split(":");
		r = Integer.parseInt(info[0]);
		c = Integer.parseInt(info[1]);
		n = Integer.parseInt(info[2]);
		
		if (n == -1) {
			frame.btns[r][c].setMine(true);
			frame.minesCount += 1;
		} else {
			frame.btns[r][c].setAdjacentMinesCount(n);
		}
	}
	
	@Override
	public void run() {
		String		s;
		

		while (Integer.valueOf(42).equals(42)) {
			s = in.nextLine();
			System.out.println(s);
			if (s.equals("done")) {
				frame.setDone(false);
				break;
			} else if (s.equals("interrupted")) {
				frame.setDone(true);
				break;
			}
			setBtn(s);
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				break;
			}
		}

	}

}
