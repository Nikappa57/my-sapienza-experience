import java.util.Scanner;

public class Download implements Runnable {
	
	private	Scanner 	in;
	private	Window		frame;
	private Listener	listener;

	public Download(Scanner in, Window frame, Listener listener) {
		this.in = in;
		this.frame = frame;
		this.listener = listener;
	}
	
	@Override
	public void run() {
		String	s;

		while (true) {
			
			if (in.hasNextLine()) {
				s = in.nextLine();
				
				if (s.equals("END")) {
					frame.appendLog("=============== Downoad completato ===============\n");
					frame.setFinish();
				} else if (s.equals("INTERRUPTED")) {
					frame.appendLog("=============== Downoad interrotto ===============\n");
				} else if (s.equals("ERROR")) {
					frame.appendLog("=============== Comando errato ===============\n");
					listener.connectSocket();
				} else {
					frame.appendLog(s + "\n");
				}
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
