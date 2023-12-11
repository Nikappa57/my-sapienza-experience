import java.awt.*;
import javax.swing.*;

public class Window extends JFrame {

	private static final long serialVersionUID = 1L;
	
	private JTextField			serverAddressInput;
	private JTextField			serverPortInput;
	public JButton				connectBtn;
	public JButton				disconnectBtn;
	public LotteryComboBox[][]	boxes;
	public static int			rBoxes = 5;
	public static int			cBoxes = 5;
	public JButton				startBtn;
	public JButton				stopBtn;
	public JButton				resetBtn;
	public JButton				randomBtn;
	
	private JPanel				topPanel;
	private JPanel				centerPanel;
	private JPanel				bottomPanel;
	
	public String getServerAddress() {
		return serverAddressInput.getText();
	}
	
	public Integer getServerPort() {
		return Integer.parseInt(serverPortInput.getText());
	}
	
	public Boolean isBoxesValid() {
		for (int r = 0; r < rBoxes; r++) {
			for (int c = 0; c < cBoxes; c++) {
				if (!boxes[r][c].isNumberSelected())
					return false;
				for (int i = r + 1; i < rBoxes; i++)
				{
					if (boxes[r][c].getSelectedIndex() == boxes[i][c].getSelectedIndex())
						return false;
				}
			}
		}
		return true;
		
	}
	
	private void setBoxesReadOnly(Boolean rOnly) {
		for (int r = 0; r < rBoxes; r++) {
			for (int c = 0; c < cBoxes; c++) {
				boxes[r][c].setReadOnly(rOnly);
			}
		}
	}
	
	private void resetSelectedBoxes() {
		for (int r = 0; r < rBoxes; r++) {
			for (int c = 0; c < cBoxes; c++) {
				boxes[r][c].setChecked(false);
			}
		}
	}
	
	public void resetBoxes() {
		for (int r = 0; r < rBoxes; r++) {
			for (int c = 0; c < cBoxes; c++) {
				boxes[r][c].setSelectedIndex(0);
				boxes[r][c].setChecked(false);
			}
		}
	}
	
	public void selectBox(int c, Integer n) {
		if (n < 1 || n > 90 || c < 0 || c > cBoxes) return ;
		
		for (int r = 0; r < rBoxes; r++) {
			if (boxes[r][c].getSelectedIndex() == n)
				boxes[r][c].setChecked(true);
		}
	}
	
	public void showInterrupt() {
		JOptionPane.showMessageDialog(this, new JLabel("Estrazione Interrotta"));
		setConnect();
	}
	
	public void showResults() {
		int[] results = new int[cBoxes];
		
		for (int i = 0; i < cBoxes; i++)
			results[i] = 0;
		
		for (int r = 0; r < rBoxes; r++) {
			for (int c = 0; c < cBoxes; c++) {
				if (boxes[r][c].isChecked()) {
					results[c]++;
				}
			}
		}
		
		JPanel resultPanel = new JPanel();
		resultPanel.setLayout(new GridLayout(2, cBoxes));
		
		for (int i = 0; i < cBoxes; i++)
			resultPanel.add(new JLabel("Ruota " + (i + 1)));
		
		for (int i = 0; i < cBoxes; i++)
			resultPanel.add(new JLabel("" + results[i]));
		
		
		JOptionPane.showMessageDialog(this, resultPanel);
		
 		setConnect();
	}
	
	public void setDisconnect() {
		connectBtn.setEnabled(true);
		disconnectBtn.setEnabled(false);
		startBtn.setEnabled(false);
		stopBtn.setEnabled(false);
		resetBtn.setEnabled(false);
		randomBtn.setEnabled(false);
		setBoxesReadOnly(true);
	}
	
	public void setConnect() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(true);
		startBtn.setEnabled(true);
		stopBtn.setEnabled(false);
		resetBtn.setEnabled(true);
		randomBtn.setEnabled(true);
		setBoxesReadOnly(false);
	}
	
	public void setStarted() {
		connectBtn.setEnabled(false);
		disconnectBtn.setEnabled(false);
		startBtn.setEnabled(false);
		stopBtn.setEnabled(true);
		resetBtn.setEnabled(false);
		randomBtn.setEnabled(false);
		resetSelectedBoxes();
		setBoxesReadOnly(true);
	}

	public Window() {
		super("Title!");
		
		Listener listener = new Listener(this);
	
		
		// TOP
		topPanel = new JPanel();
		topPanel.setLayout(new FlowLayout());
		this.add(topPanel, BorderLayout.NORTH);

		serverAddressInput = new JTextField(10);
		serverPortInput = new JTextField(5);
		connectBtn = new JButton("Connect");
		disconnectBtn = new JButton("Disconnect");
		
		// -- debug default options -- 
		serverAddressInput.setText("localhost");
		serverPortInput.setText("4400");
		// --		  -				--

		topPanel.add(new JLabel("Server Adress"));
		topPanel.add(serverAddressInput);
		topPanel.add(new JLabel("Server Port"));
		topPanel.add(serverPortInput);
		topPanel.add(connectBtn);
		topPanel.add(disconnectBtn);
		
		// CENTER
		centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(rBoxes, cBoxes + 1));
		centerPanel.setBorder(BorderFactory.createTitledBorder("Lotteria"));
		this.add(centerPanel, BorderLayout.CENTER);
		
		boxes = new LotteryComboBox[rBoxes][cBoxes];
		for (int r = 0; r < rBoxes; r++) {
			centerPanel.add(new JLabel("Ruota " + r));
			for (int c = 0; c < cBoxes; c++) {
				boxes[r][c] = new LotteryComboBox();
				centerPanel.add(boxes[r][c]);
			}
		}
		
		// BOTTOM
		bottomPanel = new JPanel();
		bottomPanel.setLayout(new FlowLayout());
		this.add(bottomPanel, BorderLayout.SOUTH);
		
		startBtn = new JButton("Start");
		stopBtn = new JButton("Stop");
		resetBtn = new JButton("Reset");
		randomBtn = new JButton("Radomize");
		
		bottomPanel.add(startBtn);
		bottomPanel.add(stopBtn);
		bottomPanel.add(resetBtn);
		bottomPanel.add(randomBtn);
		
		
		// LISTENER
		
		connectBtn.addActionListener(listener);
		disconnectBtn.addActionListener(listener);
		startBtn.addActionListener(listener);
		stopBtn.addActionListener(listener);
		resetBtn.addActionListener(listener);
		randomBtn.addActionListener(listener);
		
		// SETUP
		
		this.setDisconnect();
		
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(800, 400);
		this.setVisible(true);
	}
}
