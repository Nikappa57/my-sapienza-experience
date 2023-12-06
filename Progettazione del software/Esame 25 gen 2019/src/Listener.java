import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Listener implements ActionListener {
	
	Window		frame;
	Socket		socket;
	Scanner		in;
	PrintWriter	out;
	
	public Listener(Window frame) {
		this.frame = frame;
	}
	
	
	private void connect() {
		frame.connect_btn.setEnabled(false);

		try {
			socket = new Socket(frame.address_input.getText(), Integer.parseInt(frame.port_input.getText()));
			in = new Scanner(socket.getInputStream());
			out = new PrintWriter(socket.getOutputStream());
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
			frame.connect_btn.setEnabled(true);
			return ;
		}
		
		frame.disconnect_btn.setEnabled(true);
		frame.start_btn.setEnabled(true);
		

	}
	
	private void disconnect() {
		frame.disconnect_btn.setEnabled(false);
		
		out.println("disconnect");
		out.flush();
		
		try {
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			frame.disconnect_btn.setEnabled(false);
			return ;
		}
		in.close();
		out.close();
		frame.resetFlag();
		frame.connect_btn.setEnabled(true);
		frame.start_btn.setEnabled(false);
	}
	
	
	private void start() {
		frame.start_btn.setEnabled(false);
		frame.disconnect_btn.setEnabled(false);
		frame.resetFlag();
		
		Thread tDownload = new Thread(new FlagDownload(frame, socket, in, out));
		tDownload.start();
		
		out.println("start");
		out.flush();
		
		frame.stop_btn.setEnabled(true);
	}
	
	private void stop() {
		out.println("stop");
		out.flush();
	}

	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("Connect")) connect();
		else if (e.getActionCommand().equals("Disconnect")) disconnect();
		else if (e.getActionCommand().equals("Start")) start();
		else if (e.getActionCommand().equals("Stop")) stop();
	}

}
