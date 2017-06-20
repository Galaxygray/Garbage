
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.List;

import javax.swing.*;
import javax.swing.event.DocumentListener;
import javax.swing.text.JTextComponent;


public class MainFrame extends JFrame{
	 private FileDialog openDia;// 定义“打开、保存”对话框
	 private TextArea ta;
	 private JTextField text;
	 private File file;//定义文件
	 private List<Data> data;
	 private static final String INITIAL_LABEL_TEXT = "00:00:00";
	 private CountingThread thread = new CountingThread();  
	 private long programStart = System.currentTimeMillis();
	 private JLabel label = new JLabel(INITIAL_LABEL_TEXT);  
	 private List<Integer> postion;
	 private List<Integer> res;
	 private Data d;
	 private int ok;
	public MainFrame(){
		super();
		data = new ArrayList<Data>();
		res = new ArrayList<Integer>();
		d = null;
		this.setTitle("芯片查询系统");
		setSize(1080, 900);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		text = new JTextField("请输入搜索内容", 50);
		ta = new TextArea();
		final JToolBar toolBar = new JToolBar();
		getContentPane().add(toolBar, BorderLayout.NORTH);
		openDia = new FileDialog(this, "打开", FileDialog.LOAD);
		final JButton buttonopen = new JButton();
		final JButton buttonout = new JButton();
		final JButton buttonadd = new JButton();
		final JButton buttonerase = new JButton();
		final JButton buttonhelp = new JButton("帮助");
		final JButton buttonxiugai = new JButton("修改参数");
		//导入配置文件
		buttonopen.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
                openDia.setVisible(true);//显示打开文件对话框
                
                String dirpath = openDia.getDirectory();//获取打开文件路径并保存到字符串中。
                String fileName = openDia.getFile();//获取打开文件名称并保存到字符串中
                
                if (dirpath == null || fileName == null)//判断路径和文件是否为空
                    return;
                else
                {
                	data = new Excel().getAllByExcel(dirpath + fileName);
               // 	System.out.println(data);
                }
            }
		});
		buttonout.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				List<Data> out = new ArrayList<Data>();
				for(int i = 0; i < res.size(); i ++){
					out.add(data.get(res.get(i)));
				}
                new Excel().Out(out);
            }
		});
		buttonadd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				NewFrame();
            }
		});
		buttonerase.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JTextField pw = new JTextField(100);
				JOptionPane.showMessageDialog(null, pw, "请输入芯片型号或者名称", JOptionPane.PLAIN_MESSAGE);
				if(pw.getText().length() == 0) return ;
                new operation().Erase(pw.getText(), data);
            }
		});
		buttonhelp.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Desktop.getDesktop().open(new File("help.docx"));
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
            }
		});
		buttonxiugai.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				xiugaiFrame();
            }
		});
		buttonopen.setText("导入配置文件");
		buttonout.setText("导出结果文件");
		buttonadd.setText("增加芯片");
		buttonerase.setText("删除芯片");
		toolBar.add(buttonopen);
		toolBar.add(buttonout);
		toolBar.add(buttonadd);
		toolBar.add(buttonerase);
		toolBar.add(buttonhelp);
		toolBar.add(buttonxiugai);
		text.setPreferredSize(new Dimension(400,50));
		text.addKeyListener(new KeyListener() {
			@Override
			public void keyTyped(KeyEvent e) {
			}
			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
			//	System.out.println(e.getKeyCode());
				if(e.getKeyCode() != KeyEvent.VK_ENTER) return ;
				ta.setText("");
				String str = text.getText();
				if(data == null || data.size() == 0 ){
					return ;
				}
				res = new operation().Search(str,data);
				for(int i = 0; i < res.size(); i ++){
					ta.append(data.get(res.get(i)).getName() + "\n");
				}
			}
			@Override
			public void keyReleased(KeyEvent e) {
			}
		});
		ta.addMouseListener(new MouseListener(){

			@Override
			public void mouseClicked(MouseEvent e) {
				int cnt = e.getClickCount(), pos = 0;
				if(cnt >= 2){
					int x = ta.getCaretPosition(), pre = -1;
					String str = ta.getText();
					for(int i = 0; i < str.length(); i ++){
						if(str.charAt(i) == '\n'){
							if(i >= x){
							//	System.out.println(str.substring(pre, i));
								str = str.substring(pre + 1, i);
							//	System.out.println(str + str.length());
								for(int j = 0; j < data.size(); j ++){
									if(data.get(j).getName().equals(str) || data.get(j).getId().equals(str)){
										JOptionPane.showMessageDialog(null, data.get(j).toString(), "详细信息", JOptionPane.INFORMATION_MESSAGE);
										break;
									}
								}
								break;
							}
							pre = i;
						}
						//System.out.println(i + " " + str.charAt(i));
					}
				}
			}
			@Override
			public void mousePressed(MouseEvent e) {
			}
			@Override
			public void mouseReleased(MouseEvent e) {
			}
			@Override
			public void mouseEntered(MouseEvent e) {
			}
			@Override
			public void mouseExited(MouseEvent e) {
			}
		});
		setLayout(new FlowLayout());
		this.add(text,FlowLayout.LEFT);
		ta.setPreferredSize(new Dimension(1000,400));
		this.add(ta);
		label.setPreferredSize(new Dimension(200,200));
		this.add(label);
		
		thread.start();
	}
	public void NewFrame(){
		JFrame New = new JFrame();
		JPanel Id = new JPanel();
		Id.add(new JLabel("型号"));
		Id.add(new JTextField(100));
		Id.setLayout(new GridLayout(1,2));
		JPanel Name = new JPanel();
		Name.add(new JLabel("名称"));
		Name.add(new JTextField(100));
		Name.setLayout(new GridLayout(1,2));
		JPanel Fuc = new JPanel();
		Fuc.add(new JLabel("功能"));
		Fuc.add(new JTextField(100));
		Fuc.setLayout(new GridLayout(1,2));
		JPanel Num = new JPanel();
		Num.add(new JLabel("管教数目"));
		Num.add(new JTextField(100));
		Num.setLayout(new GridLayout(1,2));
		JPanel In = new JPanel();
		In.add(new JButton("添加"));
		In.setLayout(new FlowLayout());
		JPanel Def = new JPanel();
		Def.add(new JLabel("定义"));
		Def.add(new TextArea());
		Def.setLayout(new GridLayout(1,2));
		JPanel Intr = new JPanel();
		Intr.add(new JLabel("简介"));
		Intr.add(new TextArea());
		Intr.setLayout(new GridLayout(1,2));
		ok = 0;
		New.setLayout(new GridLayout(7,1));
		New.add(Id);
		New.add(Name);
		New.add(Fuc);
		New.add(Num);
		New.add(Def);
		New.add(Intr);
		In.setLayout(new FlowLayout());
		New.add(In);
		New.setSize(500, 800);
		New.setVisible(true);
		((JButton )In.getComponent(0)).addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String id = ((JTextField)Id.getComponent(1)).getText();
				String name = ((JTextField)Name.getComponent(1)).getText();
				String fuc = ((JTextField)Fuc.getComponent(1)).getText();
				String num = ((JTextField)Num.getComponent(1)).getText();
				String def = ((TextArea)Def.getComponent(1)).getText();
				String intr = ((TextArea)Intr.getComponent(1)).getText();
				if(id.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入型号", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				if(name.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入名称", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				if(num.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入管脚数目", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				d = new Data(id, name,fuc, Integer.parseInt(num), def, intr);
				New.setVisible(false);
				new operation().Add(d, data);
            }
		});
	}
	
	public void xiugaiFrame(){
		JFrame New = new JFrame();
		JPanel Id = new JPanel();
		Id.add(new JLabel("型号"));
		Id.add(new JTextField(100));
		Id.setLayout(new GridLayout(1,2));
		JPanel Name = new JPanel();
		Name.add(new JLabel("名称"));
		Name.add(new JTextField(100));
		Name.setLayout(new GridLayout(1,2));
		JPanel Fuc = new JPanel();
		Fuc.add(new JLabel("功能"));
		Fuc.add(new JTextField(100));
		Fuc.setLayout(new GridLayout(1,2));
		JPanel Num = new JPanel();
		Num.add(new JLabel("管教数目"));
		Num.add(new JTextField(100));
		Num.setLayout(new GridLayout(1,2));
		JPanel In = new JPanel();
		In.add(new JButton("修改"));
		In.setLayout(new FlowLayout());
		JPanel Def = new JPanel();
		Def.add(new JLabel("定义"));
		Def.add(new TextArea());
		Def.setLayout(new GridLayout(1,2));
		JPanel Intr = new JPanel();
		Intr.add(new JLabel("简介"));
		Intr.add(new TextArea());
		Intr.setLayout(new GridLayout(1,2));
		ok = 0;
		New.setLayout(new GridLayout(7,1));
		New.add(Id);
		New.add(Name);
		New.add(Fuc);
		New.add(Num);
		New.add(Def);
		New.add(Intr);
		In.setLayout(new FlowLayout());
		New.add(In);
		New.setSize(500, 800);
		New.setVisible(true);
		((JButton )In.getComponent(0)).addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String id = ((JTextField)Id.getComponent(1)).getText();
				String name = ((JTextField)Name.getComponent(1)).getText();
				String fuc = ((JTextField)Fuc.getComponent(1)).getText();
				String num = ((JTextField)Num.getComponent(1)).getText();
				String def = ((TextArea)Def.getComponent(1)).getText();
				String intr = ((TextArea)Intr.getComponent(1)).getText();
				if(id.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入型号", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				if(name.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入名称", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				if(num.equals("")){
					System.out.println(((JTextField)Id.getComponent(1)).getText());
					JOptionPane.showMessageDialog(null, "请输入管脚数目", "Error", JOptionPane.ERROR_MESSAGE);
					return ;
				}
				d = new Data(id, name,fuc, Integer.parseInt(num), def, intr);
				New.setVisible(false);
				new operation().modify(d, data);
            }
		});
	}
	
	public  void getinf(String name){
		JOptionPane Message = new JOptionPane();
		TextArea m = new TextArea();
		Message.add(m);
		for(int i = 0; i < data.size(); i ++){
			if(data.get(i).getName().equals(name)){
				JOptionPane.showMessageDialog(null, data.get(i).toString(), "Error", JOptionPane.PLAIN_MESSAGE);
				break;
			}
		}
	}
	
	private class CountingThread extends Thread {    
   
        private CountingThread() {  
            setDaemon(true);  
        }  
        @Override  
        public void run() {  
            while (true) {  
                    long elapsed = System.currentTimeMillis() - programStart;  
                    label.setText(format(elapsed));  
                try {  
                    sleep(1000);  // 1毫秒更新一次显示
                } catch (InterruptedException e) {  
                    e.printStackTrace();  
                    System.exit(1);  
                }  
            }  
        }  
   
        // 将毫秒数格式化  
        private String format(long elapsed) {  
            int hour, minute, second;  
            elapsed = elapsed / 1000;  
            second = (int) (elapsed % 60);  
            elapsed = elapsed / 60;  
   
            minute = (int) (elapsed % 60);  
            elapsed = elapsed / 60;  
   
            hour = (int) (elapsed % 60);  
   
            return String.format("%02d:%02d:%02d", hour, minute, second);  
        }  
    }
	
	
	public static void main(String args[]){
		SwingUtilities.invokeLater(new Runnable(){
			
			public void run(){  
				MainFrame mainFrame = new MainFrame();
				mainFrame.setVisible(true);
			}
		});
	}
}


