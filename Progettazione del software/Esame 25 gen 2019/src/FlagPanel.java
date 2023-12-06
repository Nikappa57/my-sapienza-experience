import java.awt.Color;
import java.util.HashMap;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

public class FlagPanel extends JPanel {
	
	private static final long serialVersionUID = 1L;
	private static HashMap<String, Color> COLORS = new HashMap<String, Color>() {{
		put("0", Color.WHITE);
		put("1", Color.BLACK);
		put("2", Color.GREEN);
		put("3", Color.RED);
		put("4", Color.YELLOW);
		put("5", Color.BLUE);
		put("6", Color.ORANGE);
	}};
	
	public FlagPanel() {
		super();
		this.setBorder(BorderFactory.createLineBorder(Color.BLACK));
		resetColor();
	}
	
	public void resetColor() {
		this.setBackground(Color.LIGHT_GRAY);
	}
	
	
	public void setColor(String colorCode) {
		if (!COLORS.containsKey(colorCode)) return;
		
		this.setBackground(COLORS.get(colorCode));
	}
}
