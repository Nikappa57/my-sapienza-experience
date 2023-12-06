import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Window extends JFrame {
	private static final long serialVersionUID = 1L;
	JLabel		address_label;
	JTextArea	address_input;
	JLabel		port_label;
	JTextArea	port_input;
	JButton		connect_btn;
	JButton		disconnect_btn;
	JButton		start_btn;
	JButton		stop_btn;
	FlagPanel	flag_left;
	FlagPanel	flag_center;
	FlagPanel	flag_right;
	
	JPanel		top_panel;
	JPanel		center_panel;
	JPanel		bottom_panel;
	
	public void resetFlag() {
		flag_left.resetColor();
		flag_center.resetColor();
		flag_right.resetColor();
	}
	
	public Window() {
		super("Title");
		
		Listener listener = new Listener(this);
		
		// Top
		address_label = new JLabel("Server address");
		address_input = new JTextArea(1, 10);
		port_label = new JLabel("Port");
		port_input = new JTextArea(1, 5);
		connect_btn = new JButton("Connect");
		disconnect_btn = new JButton("Disconnect");
		
		connect_btn.addActionListener(listener);
		disconnect_btn.addActionListener(listener);
		disconnect_btn.setEnabled(false);
		
		top_panel = new JPanel();
		top_panel.setLayout(new FlowLayout());
		top_panel.add(address_label);
		top_panel.add(address_input);
		top_panel.add(port_label);
		top_panel.add(port_input);
		top_panel.add(connect_btn);
		top_panel.add(disconnect_btn);
		this.add(top_panel, BorderLayout.NORTH);
		
		// Center
		flag_left = new FlagPanel();
		flag_center = new FlagPanel();
		flag_right = new FlagPanel();
		
		center_panel = new JPanel();
		center_panel.setLayout(new GridLayout(1, 3));
		center_panel.add(flag_left);
		center_panel.add(flag_center);
		center_panel.add(flag_right);
		this.add(center_panel, BorderLayout.CENTER);
		
		
		// Bottom
		start_btn = new JButton("Start");
		stop_btn = new JButton("Stop");
		
		start_btn.addActionListener(listener);
		stop_btn.addActionListener(listener);
		start_btn.setEnabled(false);
		stop_btn.setEnabled(false);
		
		bottom_panel = new JPanel();
		bottom_panel.setLayout(new FlowLayout());
		bottom_panel.add(start_btn);
		bottom_panel.add(stop_btn);
		this.add(bottom_panel, BorderLayout.SOUTH);
		
		this.setSize(800, 600);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}
