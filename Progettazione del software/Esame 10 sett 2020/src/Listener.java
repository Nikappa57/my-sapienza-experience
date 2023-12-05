import java.awt.event.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

public class Listener implements ActionListener {
	
	Window frame;
	HashMap<Integer, TicketCell> ticketMap;
	Socket socket;
	Scanner in;
	PrintWriter out;
	Thread thread;


	public Listener(Window frame) {
		this.frame = frame;
	}

	private void connect() {
		try {
			frame.connect_btn.setEnabled(false);
			socket = new Socket(frame.server_input.getText(), Integer.parseInt(frame.port_input.getText()));
			in = new Scanner(socket.getInputStream());
			out = new PrintWriter(socket.getOutputStream());
			
			frame.disconnect_btn.setEnabled(true);
			frame.start_btn.setEnabled(true);
			
			
			
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			frame.connect_btn.setEnabled(true);
			e.printStackTrace();
		}
	}
	
	private void disconnect() {
		try {
			frame.disconnect_btn.setEnabled(false);
			out.println("disconnect");
			out.flush();
			
			socket.close();
			in.close();
			out.close();
			
			frame.connect_btn.setEnabled(true);
			frame.start_btn.setEnabled(false);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			frame.disconnect_btn.setEnabled(true);
			e.printStackTrace();
		}
		
	}
	
	private void start() {
		
		if (ticketMap != null) {
			for (TicketCell t: ticketMap.values()) {
				t.setSelected(false);
			}
		}
		
		ArrayList<Integer> randList = new ArrayList<Integer>();
		Random rand = new Random();
		int n;
		TicketCell tempCell;
		ticketMap = new HashMap<Integer, TicketCell>();
		
		frame.start_btn.setEnabled(false);
		
		while (randList.size() < 15) {
			n = rand.nextInt(90);
			if (n > 0 && !randList.contains(n)) {
				randList.add(Integer.valueOf(n));
			}
		}
		
		randList.sort(null);
		System.out.println(randList.toString());
		for (int j = 0; j < 5; j++) {
			for (int i = 0; i < 3; i++) {
				tempCell = frame.ticketMat[i][j];
				tempCell.setValue(randList.get(0));
				ticketMap.put(randList.get(0), tempCell);
				randList.remove(0);
			}
		}

		thread = new Thread(new ThreadStream(in, frame, ticketMap));
		thread.start();

		out.println("start");
		out.flush();
		System.out.println("START");

		frame.stop_btn.setEnabled(true);
		frame.disconnect_btn.setEnabled(false);
	}
	
	private void stop() {
		frame.stop_btn.setEnabled(false);
		out.println("stop");
		out.flush();
	}
	
	
	
	@Override
	public void actionPerformed(ActionEvent e) {
		
		switch (e.getActionCommand()) {
			
			case "Connect":
				connect(); break;
			case "Disconnect":
				disconnect(); break;
			case "Start":
				start(); break;
			case "Stop":
				stop(); break;
		
		}
		
	}
	
}
