import java.awt.Button;	// importing button feature of Java AWT 
import java.awt.Frame;	// importing frame feature of Java AWT
import java.awt.Label;	// importing label feature of Java AWT
import java.awt.TextArea;	// importing multi-line text-box feature of Java AWT
import java.awt.TextField;	// importing single-line text-box feature of Java AWT
import java.awt.event.ActionEvent;	// importing action-receiving feature of Java AWT
import java.awt.event.ActionListener;	// importing action-processing feature of Java AWT
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Server_Machine extends Frame implements ActionListener
{
	
	Frame f = new Frame();	// creating a new Java AWT Frame object
	Label head = new Label("Server Machine");
	Label message = new Label("Type your Message here:");
	TextField text = new TextField();	// creating a textfield to receive messages from the user
	Button send = new Button("Send");	// creating a "send" button to send text messages
	TextArea chat = new TextArea();	// creating the chat area
	Socket socket = null ;
	ServerSocket server = null ;
	DataInputStream in = null ;
	DataOutputStream out = null ;
	SimpleDateFormat form = new SimpleDateFormat("HH:mm:ss");	// to print timestamp of texts

	Server_Machine(int port) throws IOException
	{
		f.setBounds(300, 300, 490, 417);
		f.setLayout(null);
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter() {
		      public void windowClosing(WindowEvent
		      windowEvent) {
		        System.exit(0);
		      }
		    });
		head.setBounds(195, 74, 108, 13);
		f.add(head);
		message.setBounds(23, 328, 177, 15);
		f.add(message);
		text.setBounds(24, 361, 371, 24);
		f.add(text);
		send.setBounds(402, 359, 78, 33);
		f.add(send);
		chat.setBounds(23, 123, 456, 181);
		f.add(chat);
		chat.setEditable(false);	// so that chatrecords cannot be edited
		send.addActionListener(this);
		text.addActionListener(this);
		try
	    {
		      server = new ServerSocket(port);
		      chat.setText("Waiting for client.\n");
		      socket = server.accept();
		      chat.append("Client is online. Say Hi!\n\n");
		      in = new DataInputStream(socket.getInputStream());  
		      out = new DataOutputStream(socket.getOutputStream());
		      while(true)
		      {
			      String data = in.readUTF();	// receiving texts from the client
			      chat.append("Client (" + form.format(new Date()) + ") : "+ data + "\n");	// updating the chat
		      }
	    }
	    catch(IOException ioe)
	    {
	    	chat.append("\nClient has left the chat.\n\n");
	    }
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		try
		{
			if(!text.getText().trim().equals(""))	// if the textbox is not empty
			{
				out.writeUTF(text.getText());	// send output to the client
				chat.append("Server (" + form.format(new Date()) + ") : " + text.getText() + "\n");	// updating the chat
			}
		}
		catch (IOException | NullPointerException ex)
		{
			chat.append("Client is not online to receive your messages.\n\n");
		}
		finally
		{
			text.setText("");	// clearing the textbox once message is sent
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		new Server_Machine(42069);	// switching on port number 42069
	}
	
}