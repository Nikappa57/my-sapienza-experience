import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

public class BoardListener implements ActionListener {

	private Window		frame;
	public BoardListener(Window frame) {
		this.frame = frame;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		BoardButton btn = (BoardButton) e.getSource();

		btn.removeActionListener(this);
		if (btn.hasMine()) {
			frame.setFinish(false);
		} else {
			frame.btnsCount++;
			if (frame.minesCount == 100 - frame.btnsCount) {
				frame.setFinish(true);
			}
		}

	}

}
