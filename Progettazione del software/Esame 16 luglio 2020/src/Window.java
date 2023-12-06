import java.awt.*;
import javax.swing.*;

public class Window extends JFrame {

	private static final long serialVersionUID = 1L;

	private JPanel		topPanel;
	private JPanel		centerPanel;
	private JPanel		bottomPanel;
	private JTextField	addressInput;
	private JTextField	portInput;
	private JTextField	commandInput;
	private JTextArea	consoleLog;
	private JButton		connectBtn;
	private JButton		disconnectBtn;
	private JButton		executeBtn;
	private JButton		interruptBtn;
	
	public String getAddress() {
		return addressInput.getText();
	}
	
	public Integer getPort() {
		return Integer.parseInt(this.portInput.getText());
	}
	
	public String getCommand() {
		return commandInput.getText();
	}
	
	public void appendLog(String text) {
		consoleLog.append(text);
	}
	
	public void setConnected() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(true);
		executeBtn.setEnabled(true);
		interruptBtn.setEnabled(false);
		consoleLog.setText("");
	}
	
	public void setDisconnected() {
		connectBtn.setEnabled(true);
		disconnectBtn.setEnabled(false);
		executeBtn.setEnabled(false);
		interruptBtn.setEnabled(false);
	}
	
	public void setExecuted() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(false);
		executeBtn.setEnabled(false);
		interruptBtn.setEnabled(true);
	}
	
	public void setFinish() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(true);
		executeBtn.setEnabled(true);
		interruptBtn.setEnabled(false);
	}
	
	
	public Window() {
		super("Title");
		
		Listener listener = new Listener(this);

		// TOP
		topPanel = new JPanel();
		topPanel.setLayout(new FlowLayout());
		
		addressInput = new JTextField(10);
		portInput = new JTextField(5);
		connectBtn = new JButton("Connect");
		disconnectBtn = new JButton("Disconnect");
		
		connectBtn.addActionListener(listener);
		disconnectBtn.addActionListener(listener);
		disconnectBtn.setEnabled(false);
		
		topPanel.add(new JLabel("Server Address"));
		topPanel.add(addressInput);
		topPanel.add(new JLabel("Port"));
		topPanel.add(portInput);
		topPanel.add(connectBtn);
		topPanel.add(disconnectBtn);
		
		this.add(topPanel, BorderLayout.NORTH);
		
		// CENTER
		centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(1, 1));
		centerPanel.setBorder(BorderFactory.createTitledBorder("Console"));
		
		consoleLog = new JTextArea(25, 80);
		consoleLog.setEditable(false);
		
		centerPanel.add(new JScrollPane(consoleLog));
		
		
		this.add(centerPanel, BorderLayout.CENTER);
		
		// BOTTOM
		bottomPanel = new JPanel();
		bottomPanel.setLayout(new FlowLayout());
		
		commandInput = new JTextField(20);
		executeBtn = new JButton("Execute");
		interruptBtn = new JButton("Interrupt");
		
		executeBtn.addActionListener(listener);
		interruptBtn.addActionListener(listener);
		executeBtn.setEnabled(false);
		interruptBtn.setEnabled(false);

		bottomPanel.add(new JLabel("Command"));
		bottomPanel.add(commandInput);
		bottomPanel.add(executeBtn);
		bottomPanel.add(interruptBtn);
		
		this.add(bottomPanel, BorderLayout.SOUTH);

		this.setSize(800, 500);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

}
