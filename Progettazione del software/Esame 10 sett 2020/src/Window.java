import java.awt.*;
import javax.swing.*;

//class GetSize implements ActionListener {
//	
//	JFrame frame;
//	
//	GetSize(JFrame frame) {
//		this.frame = frame;
//	}
//
//	@Override
//	public void actionPerformed(ActionEvent e) {
//		System.out.println(frame.getSize());
//		
//	}
//	
//}

public class Window extends JFrame {
	
	private static final long serialVersionUID = 1L;
	JLabel server_label;
	JTextArea server_input;
	JLabel port_label;
	JTextArea port_input;
	JButton connect_btn;
	JButton disconnect_btn;
	JButton start_btn;
	JButton stop_btn;
	JTextArea log_output;
	
	JPanel btn_panel;
	JPanel btnBottomPanel;
	JPanel card_panel;
	JPanel log_panel;
	
	TicketCell ticketMat[][];
	
	private Listener listener;
	
	
	
	
	public Window()
	{
		super("Titolo");
		
		listener = new Listener(this);
		
		// TOP BTN
		btn_panel = new JPanel();
		
		this.add(btn_panel, BorderLayout.NORTH);
		
		server_label = new JLabel("Server Address");
		server_input = new JTextArea(1, 10);
		port_label = new JLabel("Port");
		port_input = new JTextArea(1, 5);
		connect_btn = new JButton("Connect");
		disconnect_btn = new JButton("Disconnect");
		
		connect_btn.addActionListener(listener);
		disconnect_btn.setEnabled(false);
		disconnect_btn.addActionListener(listener);
		
		btn_panel.setLayout(new FlowLayout());
		btn_panel.add(server_label);
		btn_panel.add(server_input);
		btn_panel.add(port_label);
		btn_panel.add(port_input);
		btn_panel.add(connect_btn);
		btn_panel.add(disconnect_btn);
		
		
		// CENTER CARD
		
		card_panel = new JPanel();
		
		this.add(card_panel, BorderLayout.CENTER);
		
		card_panel.setLayout(new GridLayout(3, 5, 2, 2));
		card_panel.setBorder(BorderFactory.createTitledBorder("Cartella"));
		
		ticketMat = new TicketCell[3][5];
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				ticketMat[i][j] = new TicketCell(1);
				card_panel.add(ticketMat[i][j]);
			}
		}

		// BOTTOM BTN

		btnBottomPanel = new JPanel();

		this.add(btnBottomPanel, BorderLayout.SOUTH);

		start_btn = new JButton("Start");
		stop_btn = new JButton("Stop");
		
		start_btn.setEnabled(false);
		start_btn.addActionListener(listener);
		stop_btn.setEnabled(false);
		stop_btn.addActionListener(listener);

		btnBottomPanel.setLayout(new FlowLayout());

		btnBottomPanel.add(start_btn);
		btnBottomPanel.add(stop_btn);

		// LOG RIGHT
		log_panel = new JPanel();
		log_panel.setBorder(BorderFactory.createTitledBorder("Log"));
		
		this.add(log_panel, BorderLayout.EAST);
		
		log_output = new JTextArea(20, 30);
		
		log_panel.add(new JScrollPane(log_output));

		this.setSize(811, 436);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

}
