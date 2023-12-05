import java.net.Socket;
import java.util.HashMap;
import java.util.Scanner;

public class ThreadStream implements Runnable {
	Window frame;
	HashMap<Integer, TicketCell> ticketMap;
	Scanner in;

	public ThreadStream(Scanner in, Window frame, HashMap<Integer, TicketCell> ticketMap) {
		this.in = in;
		this.frame = frame;
		this.ticketMap = ticketMap;
	}
	
	void stop() {
		frame.stop_btn.setEnabled(false);
		frame.start_btn.setEnabled(true);
		frame.disconnect_btn.setEnabled(true);
		frame.log_output.append("Fine partita\n");	
	}
	
	@Override
	public void run() {
		String s;
		Integer n;
		TicketCell tempCell;

		while (true) {
			s = in.nextLine();
			System.out.println(s);
			if (s.equals("+")) {
				stop();
				break;
			}

			n = Integer.parseInt(s);
			frame.log_output.append("Estratto: " + n.toString() + "\n");
			if (ticketMap.containsKey(n)) {
				tempCell = ticketMap.get(n);
				tempCell.setSelected(true);
			}
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}

}
