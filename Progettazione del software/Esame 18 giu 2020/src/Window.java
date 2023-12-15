import java.awt.*;
import javax.swing.*;


public class Window extends JFrame {
	
	public int			minesCount;
	public int			btnsCount;

	JPanel				topPanel;
	JPanel				centerPanel;
	JPanel				bottomPanel;
	
	JTextField			addrField;
	JTextField			portField;
	JButton				connectBtn;
	JButton				disconnectBtn;
	JButton				startBtn;
	JButton				stopBtn;
	JButton				revealBtn;
	
	final BoardListener boardListener;
	final Listener		listener;
	
	BoardButton[][]	btns;
	
	public String getAddr() {
		return addrField.getText();
	}
	
	public Integer getPort() {
		return Integer.parseInt(portField.getText());
	}
	
	
	public void setDisconnect() {
		connectBtn.setEnabled(true);
		disconnectBtn.setEnabled(false);
		startBtn.setEnabled(false);
		stopBtn.setEnabled(false);
		revealBtn.setEnabled(false);
	}
	
	public void setConnect() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(true);
		startBtn.setEnabled(true);
		stopBtn.setEnabled(false);
		revealBtn.setEnabled(true);
	}
	
	public void setStart() {
		System.out.println("START!");
		resetBtns(false);
		
		minesCount = 0;
		btnsCount = 0;
		
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(false);
		startBtn.setEnabled(false);
		stopBtn.setEnabled(true);
		revealBtn.setEnabled(false);
	}

	public void setDone(Boolean error) {
		setConnect();
		JOptionPane.showMessageDialog(this, new JLabel(error ? "Ricezione interrotta" : "La partita può iniziare!"));
		
		if (!error) {
			setActionListenerBtns();
			enableBtns(true);
		}
	}

	public void resetBtns(Boolean enable) {
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++) {
				btns[r][c].reset();
				btns[r][c].setEnabled(enable);
			}
		}
	}

	public void enableBtns(Boolean enable) {
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++) {
				btns[r][c].setEnabled(enable);
			}
		}
	}
	
	public void showBtns(Boolean enable) {
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++) {
				btns[r][c].reveal();
				btns[r][c].setEnabled(enable);
			}
		}
	}
	
	public void setFinish(Boolean win) {
		enableBtns(false);
		if (win) showBtns(false);
		JOptionPane.showMessageDialog(this, new JLabel(win ? "Hai vinto!" : "Hai perso!"));
	}
	
	private void setActionListenerBtns() {
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++) {
				if (btns[r][c].getActionListeners().length == 0)
					btns[r][c].addActionListener(boardListener);
			}
		}
	}

	public Window() {
		super("Title!");

		listener = new Listener(this);
		boardListener = new BoardListener(this);
		
		// TOP
		
		topPanel = new JPanel();
		topPanel.setLayout(new FlowLayout());
		
		
		addrField = new JTextField(10);
		portField = new JTextField(5);
		connectBtn = new JButton("Connect");
		disconnectBtn = new JButton("Disconnect");
		
		// for debug
		addrField.setText("localhost");
		portField.setText("4400");

		connectBtn.addActionListener(listener);
		disconnectBtn.addActionListener(listener);
	
		topPanel.add(new JLabel("Server Adress"));
		topPanel.add(addrField);
		topPanel.add(new JLabel("Port"));
		topPanel.add(portField);
		topPanel.add(connectBtn);
		topPanel.add(disconnectBtn);
		
		this.add(topPanel, BorderLayout.NORTH);
		
		// CENTER
		
		centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(10, 10));
		
		btns = new BoardButton[10][10];
		
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++) {
				btns[r][c] = new BoardButton();
				centerPanel.add(btns[r][c]);
			}
		}
		
		this.add(centerPanel, BorderLayout.CENTER);
		
		// BOTTOM
		
		bottomPanel = new JPanel();
		bottomPanel.setLayout(new FlowLayout());
		
		startBtn = new JButton("Start");
		stopBtn = new JButton("Stop");
		revealBtn = new JButton("Rivela");
		
		startBtn.addActionListener(listener);
		stopBtn.addActionListener(listener);
		revealBtn.addActionListener(listener);
		
		bottomPanel.add(startBtn);
		bottomPanel.add(stopBtn);
		bottomPanel.add(revealBtn);
		
		this.add(bottomPanel, BorderLayout.SOUTH);
		
		setDisconnect();
		
		this.setLocationRelativeTo(null);
		this.setSize(800, 900);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
}
