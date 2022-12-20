import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.net.*;
import java.io.*; 
 
public class Server 
{ 
	//AWT Components
	Frame frame = new Frame("Server");
	Button sendButton = new Button("Send");
	Label titleLabel = new Label("Server Machine", Label.CENTER);
	Label typeLabel = new Label("Type your message here:", Label.LEFT);
	TextArea messageArea = new TextArea();
	TextField messageField = new TextField();
	
	//Networking Components
	private ServerSocket server;
	private Socket socket;
	private DataInputStream in;
	private DataOutputStream out;
	
	StringBuilder chatHistory = new StringBuilder("");
	
	public static void main(String[] args)
	{
		new Server(5000);
	}
	
	Server(int port)
	{
		try
		{
			server = new ServerSocket(port);
			System.out.println("Server started.");
			System.out.println("Waiting for client...");
			
			createGUI();
			
			while(true)
			{
				socket = server.accept();
				System.out.println("Client accpeted.");
				
				in = new DataInputStream(socket.getInputStream());  
			      out = new DataOutputStream(socket.getOutputStream());
				String line = "";
				
				while(true)
				{
					line = in.readUTF();
					System.out.println("Here: "+line);
					chatHistory.append("Client: " + line + "\n");
					messageArea.setText(chatHistory.toString());
				}
				//catch (Exception e) {System.out.println(e);}
			}
			
		} catch (Exception e) {System.out.println(e);}
	}
	
	void createGUI()
	{
		frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e)
			{
				try
				{
					socket.close();
					server.close();
					in.close();
					out.close();
				} catch (Exception exception) {System.out.println(exception);}
				System.exit(0);
			}
		});
		
		frame.setLayout(null);
		frame.setSize(new Dimension(500, 400));
		
		addAll();
		setBounds();
		
		frame.setVisible(true);
	}
	
	void setBounds()
	{
		titleLabel.setBounds(100, 35, 280, 20);
		messageArea.setBounds(25, 70, 450, 200);
		typeLabel.setBounds(25, 280, 200, 35);
		messageField.setBounds(25, 320, 370, 30);
		sendButton.setBounds(400, 320, 50, 30);
	}
	
	void addAll()
	{
		frame.add(titleLabel);
		frame.add(typeLabel);
		frame.add(messageArea);
		frame.add(messageField);
		frame.add(sendButton);
		
		titleLabel.setFont(new Font("Title", Font.BOLD, 14));
		typeLabel.setFont(new Font("Label", Font.BOLD, 13));
		
		messageArea.setEditable(false);
		messageArea.setFont(new Font("Text", Font.BOLD, 12));
		messageField.setFont(new Font("Text", Font.BOLD, 12));
		
		sendButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				String line = messageField.getText();
				try { out.writeUTF(line);}
				catch (Exception exception) { System.out.println(exception);}
				
				chatHistory.append("Server: " + line + "\n");
				messageArea.setText(chatHistory.toString());
			}
		});
	}
} 