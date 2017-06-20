import java.util.*;

import javax.swing.JOptionPane;
public class operation {
	public static void Add(Data d,  List<Data> list){
		list.add(d);
	}
	public static void Erase(String str, List<Data> list){
		for(int i = 0; i < list.size(); i ++){
			if(str.equals(list.get(i).getName()) || str.equals(list.get(i).getId())){
				list.remove(i);
				return ;
			}
		}
		System.out.println("Couldn't find the chip");
	}
    public static List<Integer> Search(String name,  List<Data> list) {
    	List<Integer> index = new ArrayList<Integer>();
    	for(int i = 0; i < list.size(); i ++){
    		if(list.get(i).getId().contains(name) || list.get(i).getName().contains(name)){
    			System.out.println(list.get(i).getId() + " " + name );
    			index.add(i);
    		}
    	}
    	System.out.println("*************");
        return index;
    }
    
    public static void modify(Data d, List<Data> list){
		for(int i = 0; i < list.size(); i ++){
			if(d.getName().equals(list.get(i).getName()) || d.getId().equals(list.get(i).getId())){
				list.set(i, d);
				return ;
			}
		}
		JOptionPane.showMessageDialog(null, "²»´æÔÚ¸ÃÐ¾Æ¬", "Error", JOptionPane.ERROR_MESSAGE);
	}
    
    public int getName(int num) {
    	int index = 0;
        return index;
    }
    
}
