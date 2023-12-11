import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class Listener implements ActionListener {

	private Window		frame;
	private Socket		socket;
	private Scanner		in;
	private PrintWriter	out;
	
	
	public Listener(Window f) {
		frame = f;
	}
	
	private void connect() throws IOException {
		socket = new Socket(frame.getServerAddress(), frame.getServerPort());
		in = new Scanner(socket.getInputStream());
		out = new PrintWriter(socket.getOutputStream());
		frame.setConnect();
	}
	
	private void disconnect() throws IOException {
		in.close();
		out.close();
		socket.close();
		frame.setDisconnect();
	}
	
	private void start() throws IOException {
		if (!frame.isBoxesValid())
		{
			JOptionPane.showMessageDialog(frame, new JLabel("Numeri selezionati non validi!"));
			throw new IOException(); 
		}
		
		Thread t = new Thread(new TDownload(in, frame));
		t.start();
		
		frame.setStarted();
		out.println("start");
		out.flush();
		frame.setStarted();
	}
	
	private void stop() {
		out.println("stop");
		out.flush();
	}
	
	private void random() {
		Random rand = new Random();
		Integer n;
		Boolean check;
		
		System.out.println("RANDOM");
		for (int c = 0; c < Window.cBoxes; c++) {
			for (int r = 0; r < Window.rBoxes; ) {
				n = rand.nextInt(90) + 1;
				check = true;
				for (int i = 0; i < r; i++) {
					if (frame.boxes[i][c].getSelectedIndex() == n) {
						check = false;
						break ;
					}
				}
				if (check)
					frame.boxes[r++][c].setSelectedIndex(n);
			}
		}
	}
	
	
	@Override
	public void actionPerformed(ActionEvent e) {
		JButton btn = (JButton) e.getSource();

		if (btn != frame.resetBtn && btn != frame.randomBtn)
			btn.setEnabled(false);
		try {
			if (e.getSource() == frame.connectBtn) connect();
			else if  (e.getSource() == frame.disconnectBtn) disconnect();
			else if  (e.getSource() == frame.startBtn) start();
			else if  (e.getSource() == frame.stopBtn) stop();
			else if  (e.getSource() == frame.resetBtn) frame.resetBoxes();
			else if  (e.getSource() == frame.randomBtn) random();
		} catch (IOException e1) {
			btn.setEnabled(true);
		}
	}

}
