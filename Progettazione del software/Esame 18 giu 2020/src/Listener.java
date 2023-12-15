import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import javax.swing.JButton;

public class Listener implements ActionListener {
	
	private Window		frame;
	private Socket		socket;
	private Scanner		in;
	private PrintWriter	out;
	private Thread 		t;

	
	public Listener(Window frame) {
		this.frame = frame;
	}
	
	private void connect() throws UnknownHostException, IOException {
		socket = new Socket(frame.getAddr(), frame.getPort());
		in = new Scanner(socket.getInputStream());
		out = new PrintWriter(socket.getOutputStream());
		
		frame.setConnect();
	}
	
	private void disconnect() throws IOException {
		out.println("disconnect");
		
		if (t != null && t.isAlive()) t.interrupt();
		
		in.close();
		out.close();
		socket.close();

		frame.setDisconnect();
	}
	
	private void start() {
		
		frame.setStart();
		
		t = new Thread(new TReceiver(frame, in));
		t.start();
		
		out.println("start");
		out.flush();
	}
	
	private void stop() {
		out.println("stop");
		out.flush();
	}
	
	
	
	@Override
	public void actionPerformed(ActionEvent e) {
		
		JButton btn = (JButton) e.getSource();
		
		btn.setEnabled(false);
		
		try {
			if (btn.equals(frame.connectBtn)) connect();
			else if (btn.equals(frame.disconnectBtn)) disconnect();
			else if (btn.equals(frame.startBtn)) start();
			else if (btn.equals(frame.stopBtn)) stop();
			else if (btn.equals(frame.revealBtn)) frame.showBtns(false);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			btn.setEnabled(true);
		}
	}

}
