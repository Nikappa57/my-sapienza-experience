import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Listener implements ActionListener {

	private Window		frame;
	private Socket		socket;
	private Scanner		in;
	private PrintWriter	out;
	private Thread		t;
	
	
	Listener (Window frame) {
		this.frame = frame;
	}
	
	Boolean connectSocket() {
		try {
			socket = new Socket(frame.getAddress(), frame.getPort());
			in = new Scanner(socket.getInputStream());
			out = new PrintWriter(socket.getOutputStream());
			return true;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			frame.setDisconnected();
			return false;
		}
	}
	
	private void connect() {
		
		frame.setConnected();
		
		if (connectSocket()) {
			t = new Thread(new Download(in, frame, this));
			t.start();
		}
	}
	
	private void disconnect() {
		frame.setDisconnected();
		
		out.println("DISCONNECT");
		out.flush();
		
		t.interrupt();
		in.close();
		out.close();
		try {
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			frame.setConnected();
		}
	}
	
	private void execute() {
		frame.setExecuted();
		out.println(frame.getCommand());
		out.flush();
	}
	
	private void interrupt() {
		frame.setFinish();
		out.println("INTERRUPT");
		out.flush();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		String name = e.getActionCommand();
		
		if (name.equals("Connect")) connect();
		else if (name.equals("Disconnect")) disconnect();
		else if (name.equals("Execute")) execute();
		else if (name.equals("Interrupt")) interrupt();
	}

}
