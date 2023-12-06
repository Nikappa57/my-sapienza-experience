import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class FlagDownload implements Runnable {
	
	Window		frame;
	Socket		socket;
	Scanner		in;
	PrintWriter	out;
	
	public FlagDownload(Window frame, Socket socket, Scanner in, PrintWriter out) {
		this.frame = frame;
		this.socket = socket;
		this.in = in;
		this.out = out;
	}
	
	private void close() {
		frame.stop_btn.setEnabled(false);
		frame.start_btn.setEnabled(true);
		frame.disconnect_btn.setEnabled(true);
	}
	
	@Override
	public void run() {
		String	s;
		String	positionCode;
		String	colorCode;
		
		
		while (true) {
			s = in.nextLine();
			System.out.println(s);
			positionCode = s.substring(s.indexOf(';') + 1, s.length());
			colorCode = s.substring(0, s.indexOf(';'));
			
			if (positionCode.equals("-1") && colorCode.equals("-1")) {
				close();
				break;
			}
			
			if (positionCode.equals("SX")) frame.flag_left.setColor(colorCode);
			if (positionCode.equals("CX")) frame.flag_center.setColor(colorCode);
			if (positionCode.equals("DX")) frame.flag_right.setColor(colorCode);

			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				break ;
			}
		}

	}

}
